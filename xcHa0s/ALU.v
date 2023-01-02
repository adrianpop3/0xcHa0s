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
assign res = res_ext[15:0];
wire [31:0] mul_result;
wire [31:0] div_result;
wire [15:0] mod_result;

multiplier mul(srcA,srcB,mul_result);
divider    div({extra_X,srcA},srcB,div_result,mod_result);

always @(*) begin
	extra_res = 0;
	res_ext = 0;
	ready = 1;
	flag_next[`CF] = Cflag;
	flag_next[`OF] = Oflag;
	
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
			flag_next[`NF] = mod_result[31];
			flag_next[`OF] = ({extra_X,srcA} == 32'h80000000) && (srcB  == 16'hffff);
			flag_next[`CF] = (srcB == 0);
		end
		
		/*
		
`define ALU_RSL_M  	16
`define ALU_LSL_M  	17
`define ALU_RSA_M  	18
`define ALU_LSA_M  	19
`define ALU_RSR_M  	20
`define ALU_LSR_M  	21
`define ALU_RSC_M  	22
`define ALU_LSC_M  	23

`define ALU_RSL  		24
`define ALU_LSL  		25
`define ALU_RSA  		26
`define ALU_LSA  		27
`define ALU_RSR  		28
`define ALU_LSR  		29
`define ALU_RSC  		30
`define ALU_LSC  		31
		*/
		`ALU_RSL: begin ///FA-LEEE!!!!!!!!!!!
			res_ext = (srcA>>srcB);
		end
		
		
		
		
		//////// COMPLICATED ALU OPERATIONS ////////
		
		
	endcase
	
	
end

endmodule
