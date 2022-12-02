`timescale 1ns / 1ps

module SignExtend(
	input [8:0] imm,
	output [15:0] sgnimm
    );

assign sgnimm = {{7{imm[8]}},imm};

endmodule
