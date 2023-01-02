`timescale 1ns / 1ps

module divider(
	input [31:0] X,
	input [15:0] Y,
	output [31:0] Q,
	output [15:0] R
	);
	
	wire [31:0] UQ;
	wire [15:0] UR;
	wire [31:0] MX;
	wire [15:0] MY;

	assign MX = X[31]?-X:X;
	assign MY = Y[15]?-Y:Y;

	assign UQ = MX/MY;
	assign Q = (X[31]^Y[15])?-UQ:UQ;
	
	assign UR = MX%MY;
	assign R = X[31]?-UR:UR;

endmodule
