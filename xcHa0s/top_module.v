`timescale 1ns / 1ps

module top_module();
	 
reg clk,rst;
	 
	 
wire [9:0] instr_Addr;
wire [15:0] instr;
wire [8:0] data_Addr;
wire [15:0] write_data;
wire [15:0] read_data;
wire write_enable;
	 
cpu procesor(.clk(clk), .rst(rst),
	.instr_Addr(instr_Addr),
	.instr(instr),
	.data_Addr(data_Addr),
	.write_data(write_data),
	.read_data(read_data),
	.write_enable(write_enable)
	);
	
data_mem dmem(
	.clk(clk),
	.we(write_enable),
	.addr(data_Addr),
	.data_in(write_data),
	.data_out(read_data)
);

instr_mem imem(
	.addr(instr_Addr),
	.data_out(instr)
);

initial begin
	clk = 0;
	forever begin
		#100clk = ~clk;
	end
end

initial begin
	rst=1;
	
	#400
	rst=0;
	rst=0;
	
	
	
end

endmodule
