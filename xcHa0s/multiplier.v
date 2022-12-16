`timescale 1ns / 1ps

module multiplier(
	input [15:0] X,Y,
	output [15:0] R
   );
	
	wire [31:0] MR,SignedRes;
	wire [15:0] MX,MY;

	assign MX = X[15]?-X:X;
	assign MY = Y[15]?-Y:Y;

	assign MR = MX*MY;
	assign SignedRes = (X[15]^Y[15])?-MR:MR;
	assign R = SignedRes[15:0];


endmodule
