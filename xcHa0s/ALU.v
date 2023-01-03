`timescale 1ns / 1ps

module ALU(
	input clk,
	input rst,
	input [15:0] srcA,
	input [15:0] srcB,
	input [15:0] extra_X,
	output [15:0] res,
	output reg [15:0] extra_res,
	input [4:0] opsel,
	output reg ready,
	input Cflag,Oflag,
	output reg [3:0] flag_next
    );

`include "opsel.v"

`define ZF	3
`define NF	2
`define CF	1
`define OF	0

reg [16:0] res_ext;
reg [16:0] shift_aid;
reg [15:0] shift_amount;
wire [16:0] sign_srcA;
assign res = res_ext[15:0];
wire [31:0] mul_result;
wire [31:0] div_result;
wire [15:0] mod_result;

assign sign_srcA = {16{srcA[15]}};

multiplier mul(srcA,srcB,mul_result);
divider    div({extra_X,srcA},srcB,div_result,mod_result);

wire pow_ready,pow_C,pow_O;
wire [31:0] pow_result;
pow p(.clk(clk), .rst(rst), 
	.start(opsel == `ALU_POW),
	.ready(pow_ready),
	.base(srcA),.expo(srcB),
	.result(pow_result),
	.Cflag(pow_C),
	.Oflag(pow_O));

always @(*) begin
	extra_res = 0;
	res_ext = 0;
	ready = 1;
	flag_next[`CF] = Cflag;
	flag_next[`OF] = Oflag;
	shift_amount = srcB;
	if(opsel[3] == 1)
		shift_amount = srcB & 16'h000f;
	
	case(opsel)
		`ALU_SHORT_B: res_ext = {1'b0,srcB};
		`ALU_ADD: begin
			res_ext = srcA + srcB;
			flag_next[`CF] = res_ext[16];
			flag_next[`OF] = (srcA[15]&srcB[15]&(~res_ext[15]))|((~srcA[15])&(~srcB[15])&res_ext[15]);
			flag_next[`ZF] = (res_ext == 0);
			flag_next[`NF] = res_ext[15];
		end
		`ALU_SUB: begin
			res_ext = srcA - srcB;
			flag_next[`CF] = res_ext[16];
			flag_next[`OF] = (srcA[15]&(~srcB[15])&(~res_ext[15]))|((~srcA[15])&srcB[15]&res_ext[15]);
			flag_next[`ZF] = (res_ext == 0);
			flag_next[`NF] = res_ext[15];
		end
		
		`ALU_INC: begin
			res_ext = srcA + 1;
			flag_next[`CF] = res_ext[16];
			flag_next[`OF] = (~srcA[15])&res_ext[15];
			flag_next[`ZF] = (res_ext == 0);
			flag_next[`NF] = res_ext[15];
		end
		`ALU_DEC: begin
			res_ext = srcA - 1;
			flag_next[`CF] = res_ext[16];
			flag_next[`OF] = srcA[15]&(~res_ext[15]);
			flag_next[`ZF] = (res_ext == 0);
			flag_next[`NF] = res_ext[15];
		end
	

		`ALU_AND: begin
			res_ext = {1'b0, srcA & srcB};
			flag_next[`ZF] = (res_ext == 0);
			flag_next[`NF] = res_ext[15];
		end
		`ALU_OR: begin
			res_ext = {1'b0, srcA | srcB};
			flag_next[`ZF] = (res_ext == 0);
			flag_next[`NF] = res_ext[15];
		end
		`ALU_XOR: begin
			res_ext = {1'b0, srcA ^ srcB};
			flag_next[`ZF] = (res_ext == 0);
			flag_next[`NF] = res_ext[15];
		end
		`ALU_NOT: begin
			res_ext = {1'b0, ~srcA};
			flag_next[`ZF] = (res_ext == 0);
			flag_next[`NF] = res_ext[15];
		end
		`ALU_NEG: begin
			res_ext = {1'b0,-srcA};
			flag_next[`ZF] = (res_ext == 0);
			flag_next[`NF] = res_ext[15];
		end
		`ALU_MUL: begin
			res_ext = {1'b0,mul_result[15:0]};
			extra_res = mul_result[31:16];
			flag_next[`ZF] = (mul_result == 0);
			flag_next[`NF] = mul_result[31];
			flag_next[`OF] = (mul_result[31:15] == 0) || (mul_result[31:15] == 17'h1ffff);
			flag_next[`CF] = (mul_result[31:15] == 0) || (mul_result[31:15] == 17'h1ffff);
		end
		`ALU_DIV: begin
			res_ext = {1'b0,div_result[15:0]};
			extra_res = div_result[31:16];
			flag_next[`ZF] = (div_result == 0);
			flag_next[`NF] = div_result[31];
			flag_next[`OF] = ({extra_X,srcA} == 32'h80000000) && (srcB  == 16'hffff);
			flag_next[`CF] = (srcB == 0);
		end
		`ALU_MOD: begin
			res_ext = {1'b0,mod_result};
			flag_next[`ZF] = (mod_result == 0);
			flag_next[`NF] = mod_result[15];
			flag_next[`OF] = ({extra_X,srcA} == 32'h80000000) && (srcB  == 16'hffff);
			flag_next[`CF] = (srcB == 0);
		end
		`ALU_POW: begin
			ready = pow_ready;
			res_ext = {1'b0,pow_result[15:0]};
			extra_res = pow_result[31:16];
			
			flag_next[`ZF] = (pow_result == 0);
			flag_next[`NF] = pow_result[31];
			flag_next[`OF] = pow_O;
			flag_next[`CF] = pow_C;
		end
		
		/*
`define ALU_RSL	16
`define ALU_LSL  	17
`define ALU_RSA  	18
`define ALU_LSA  	19
`define ALU_RSR  	20
`define ALU_LSR  	21
`define ALU_RSC  	22
`define ALU_LSC  	23

`define ALU_RSL_M 24
`define ALU_LSL_M 25
`define ALU_RSA_M 26
`define ALU_LSA_M 27
`define ALU_RSR_M 28
`define ALU_LSR_M 29
`define ALU_RSC_M 30
`define ALU_LSC_M 31
		*/
		`ALU_RSL, `ALU_RSL_M: begin
			shift_aid = ({srcA,1'b0}>>shift_amount);
			res_ext = shift_aid[16:1];
			flag_next[`ZF] = (res_ext == 0);
			flag_next[`NF] = res_ext[15];
			flag_next[`OF] = (res_ext[15] != srcA[15]);
			flag_next[`CF] = shift_aid[0];
		end
		`ALU_LSL, `ALU_LSL_M: begin
			shift_aid = ({1'b0,srcA}<<shift_amount);
			res_ext = shift_aid[15:0];
			flag_next[`ZF] = (res_ext == 0);
			flag_next[`NF] = res_ext[15];
			flag_next[`OF] = (res_ext[15] != srcA[15]);
			flag_next[`CF] = shift_aid[16];
		end
		`ALU_RSA, `ALU_RSA_M: begin
			shift_aid = ({srcA,1'b0}>>shift_amount) | (sign_srcA<<(16-shift_amount));
			res_ext = shift_aid[16:1];
			flag_next[`ZF] = (res_ext == 0);
			flag_next[`NF] = res_ext[15];
			flag_next[`OF] = (res_ext[15] != srcA[15]);
			flag_next[`CF] = shift_aid[0];
		end
		`ALU_LSA, `ALU_LSA_M: begin
			shift_aid = ({1'b0,srcA}<<shift_amount) | (sign_srcA>>(16-shift_amount));
			res_ext = shift_aid[15:0];
			flag_next[`ZF] = (res_ext == 0);
			flag_next[`NF] = res_ext[15];
			flag_next[`OF] = (res_ext[15] != srcA[15]);
			flag_next[`CF] = shift_aid[16];
		end
		`ALU_RSR, `ALU_RSR_M: begin
			res_ext = {1'b0,(srcA>>shift_amount)|(srcA<<(16-shift_amount))};
			flag_next[`ZF] = (res_ext == 0);
			flag_next[`NF] = res_ext[15];
			flag_next[`OF] = (res_ext[15] != srcA[15]);
			flag_next[`CF] = res_ext[15];
		end
		`ALU_LSR, `ALU_LSR_M: begin
			res_ext = {1'b0,(srcA<<shift_amount)|(srcA>>(16-shift_amount))};
			flag_next[`ZF] = (res_ext == 0);
			flag_next[`NF] = res_ext[15];
			flag_next[`OF] = (res_ext[15] != srcA[15]);
			flag_next[`CF] = res_ext[0];
		end
		`ALU_RSC, `ALU_RSC_M: begin
			res_ext = ({Cflag,srcA}>>shift_amount) | ({Cflag,srcA}<<(17-shift_amount));
			flag_next[`CF] = res_ext[16];
			flag_next[`ZF] = (res_ext[15:0] == 0);
			flag_next[`NF] = res_ext[15];
			flag_next[`OF] = (res_ext[15] != srcA[15]);
		end
		`ALU_LSC, `ALU_LSC_M: begin
			res_ext = ({Cflag,srcA}<<shift_amount) | ({Cflag,srcA}>>(17-shift_amount));
			flag_next[`CF] = res_ext[16];
			flag_next[`ZF] = (res_ext[15:0] == 0);
			flag_next[`NF] = res_ext[15];
			flag_next[`OF] = (res_ext[15] != srcA[15]);
		end
		
		
		
		
		//////// COMPLICATED ALU OPERATIONS ////////
		
		
	endcase
	
	
end

endmodule
