`timescale 1ns / 1ps

module data_mem(
	input clk,
	input we,
	input  [8:0] addr,
	input  [15:0] data_in,
	output [15:0] data_out
    );
	 
	reg    [15:0] ram [0:2**9-1]; 

	always @(posedge clk) begin   
		if (we)   
			ram[addr] <= data_in;   
	end   
	assign data_out = ram[addr];

endmodule
