`timescale 1ns / 1ps

module instr_mem(
	input  [9:0] addr,
	output [15:0] data_out
    );
	 
	reg    [15:0] rom [2**10-1:0]; 

	initial $readmemb("main.bin", rom);

	assign data_out = rom[addr];

endmodule
