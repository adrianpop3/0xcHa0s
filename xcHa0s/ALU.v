`timescale 1ns / 1ps

module ALU(
	input clk,
	input rst,
	input [15:0] srcA,
	input [15:0] srcB,
	output [15:0] res,
	input [4:0] opsel,
	output reg ready,
	input [3:0] flags,
	output reg [3:0] flag_next
    );

`include "opsel.v"

`define ZF	3
`define NF	2
`define CF	1
`define OF	0

reg [16:0] res_ext;
assign res = res_ext[15:0];

always @(*) begin
	res_ext = 0;
	ready = 1;
	flag_next = flags;
	
	case(opsel)
		`ALU_SHORT_B: res_ext = {1'b0,srcB};
		`ALU_ADD: begin
			res_ext = srcA + srcB;
			flag_next[`CF] = res_ext[16];
			flag_next[`OF] = (srcA[15]&srcB[15]&(~res_ext[15]))|((~srcA[15])&(~srcB[15])&res_ext[15]);
		end
		`ALU_SUB: begin
			res_ext = srcA - srcB;
			flag_next[`CF] = res_ext[16];
			flag_next[`OF] = (srcA[15]&(~srcB[15])&(~res_ext[15]))|((~srcA[15])&srcB[15]&res_ext[15]);
		end
		
		`ALU_INC: begin
			res_ext = srcA + 1;
			flag_next[`CF] = res_ext[16];
			flag_next[`OF] = (~srcA[15])&res_ext[15];
		end
		`ALU_DEC: begin
			res_ext = srcA - 1;
			flag_next[`CF] = res_ext[16];
			flag_next[`OF] = srcA[15]&(~res_ext[15]);
		end
	

		`ALU_AND: begin
			res_ext = {1'b0, srcA & srcB};
		end
		`ALU_OR: begin
			res_ext = {1'b0, srcA | srcB};
		end
		`ALU_XOR: begin
			res_ext = {1'b0, srcA ^ srcB};
		end
		`ALU_NOT: begin
			res_ext = {1'b0, ~srcA};
		end
		`ALU_NEG: begin
			res_ext = -srcA;
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
	
	flag_next[`ZF] = (res_ext == 0);
	flag_next[`NF] = res_ext[15];
	
end

endmodule
