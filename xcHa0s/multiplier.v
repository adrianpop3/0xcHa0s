`timescale 1ns / 1ps

module multiplier(
	input [15:0] X,Y,
	output [31:0] SignedResult
   );
	
	wire [31:0] MR;
	wire [15:0] MX,MY;

	assign MX = X[15]?-X:X;
	assign MY = Y[15]?-Y:Y;

	assign MR = MX*MY;
	assign SignedResult = (X[15]^Y[15])?-MR:MR;


endmodule
