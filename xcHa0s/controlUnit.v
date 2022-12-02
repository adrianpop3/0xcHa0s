`timescale 1ns / 1ps

module controlUnit(
	input clk,
	input rst,
	
	input [15:0] instr,
	
	output branch,
	output ret,
	output loadPC,
	
	
	output push,
	output op_stack,
	
	output [4:0] opsel,
	output [1:0] sel_srcA,
	output [1:0] sel_srcB,
	input ready,
	
	output [1:0] data_addr_sel,
	output wr_to_data_mem,
	
	output wr_from_mem,
	output wr_X,
	output wr_Y,
	output wr_ACC,
	
	output save_flags,
	input [3:0] flags
);



endmodule
