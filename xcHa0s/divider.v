`timescale 1ns / 1ps

module divider(
	input [15:0] X,Y,
	output [15:0] R
	);
	
	wire [15:0] MR;
	wire [15:0] MX,MY;

	assign MX = X[15]?-X:X;
	assign MY = Y[15]?-Y:Y;

	assign MR = MX/MY;
	assign R = (X[15]^Y[15])?-MR:MR;

endmodule
