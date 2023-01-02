`timescale 1ns / 1ps

module cpu(
	input clk,rst,
	output [9:0] instr_Addr,
	input [15:0] instr,
	output reg [8:0] data_Addr,
	output reg [15:0] write_data,
	input [15:0] read_data,
	output write_enable
    );
	 
	 
	 

/////////////// SIGN EXTEND ///////////////

wire [15:0] sign_Imm;
wire [8:0] immediate;
assign immediate = instr[8:0];

SignExtend sgex(
	.imm(immediate),
	.sgnimm(sign_Imm)
);





/////////////// FLAG REGISTER ///////////////

wire [3:0] flag_reg,flag_next;
wire save_flags;

register #(4) FlagReg(clk,rst,save_flags,flag_next,flag_reg);



//// ALU DECLARE ////

reg [15:0] srcA,srcB;
wire [15:0] res,extra_res;

//// SP DECLARE ////

reg [8:0] SP_next;
wire [8:0] SP_reg;



/////////////// CONTROL UNIT ///////////////

wire branch,ret,loadPC,reg_from_mem;
wire push,op_stack,wr_X,wr_Y,wr_ACC,extra_write_X;
wire [1:0] sel_srcA,sel_srcB,data_addr_sel,mem_data_wr_sel;

wire [4:0] opsel;
wire ready;


controlUnit cu(
	.instr(instr),
	
	.branch(branch),
	.ret(ret),
	.loadPC(loadPC),
	
	.push(push),
	.op_stack(op_stack),
	
	.opsel(opsel),
	.sel_srcA(sel_srcA),
	.sel_srcB(sel_srcB),
	.ready(ready),
	
	.data_addr_sel(data_addr_sel),
	.wr_to_data_mem(write_enable),
	.mem_data_wr_sel(mem_data_wr_sel),
	
	.reg_from_mem(reg_from_mem),
	.extra_write_X(extra_write_X),
	.wr_X(wr_X),
	.wr_Y(wr_Y),
	.wr_ACC(wr_ACC),
	
	.save_flags(save_flags),
	.flags(flag_reg)
);



/////////////// GENERAL PURPOSE REGISTERS ///////////////

wire [15:0] X_reg,Y_reg,ACC_reg;
reg [15:0] reg_next;
register X  (clk,rst,wr_X, extra_write_X?extra_res:reg_next  ,X_reg);
register Y  (clk,rst,wr_Y,reg_next,Y_reg);
register ACC(clk,rst,wr_ACC,reg_next,ACC_reg);

always @(*) begin
	if(reg_from_mem)
		reg_next = read_data;
	else
		reg_next = res;
end





/////////////// PC REGISTER ///////////////

wire [9:0] PC_reg,PC_reg_plus_1;
reg [9:0] PC_next;
wire [9:0] PC_branch;

assign PC_reg_plus_1 = PC_reg + 1;

register #(10) PC(clk,rst,loadPC,PC_next,PC_reg);

assign instr_Addr = PC_reg;
assign PC_branch = instr[9:0];

always @(*) begin
	PC_next = PC_reg_plus_1;
	if(ret)
		PC_next = read_data[9:0];
	else if(branch)
		PC_next = PC_branch;
end





/////////////// ALU ///////////////

ALU alu(
	.clk(clk),.rst(rst),
	.srcA(srcA),
	.srcB(srcB),
	.extra_X(X_reg),
	.res(res),
	.extra_res(extra_res),
	.opsel(opsel),
	.ready(ready),
	.Cflag(flag_reg[1]),
	.Oflag(flag_reg[0]),
	.flag_next(flag_next)
);


always @(*) begin

	case(sel_srcA)
		0: srcA = X_reg;
		1: srcA = Y_reg;
		2: srcA = ACC_reg;
		3: srcA = sign_Imm;
	endcase
	
	case(sel_srcB)
		0: srcB = X_reg;
		1: srcB = Y_reg;
		2: srcB = ACC_reg;
		3: srcB = sign_Imm;
	endcase

end



/////////////// DATA MEMORY + STACK POINTER ///////////////

always @(*) begin

	case(mem_data_wr_sel)
		0: write_data = X_reg;
		1: write_data = Y_reg;
		2: write_data = ACC_reg;
		3: write_data = {6'b0,PC_reg_plus_1};
	endcase

	//compute SP_next before attributing it to data_Addr
	if(push)
		SP_next = SP_reg - 1;
	else
		SP_next = SP_reg + 1;
	
	case(data_addr_sel)
		0: data_Addr = res[8:0];
		1: data_Addr = instr[8:0];
		2: data_Addr = SP_reg;
		3: data_Addr = SP_next;
	endcase

end

register #(9) SP (clk,rst,op_stack,SP_next,SP_reg);


endmodule
