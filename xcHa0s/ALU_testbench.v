`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    18:54:03 12/04/2022 
// Design Name: 
// Module Name:    ALU_testbench 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module ALU_testbench(
    );
/*
ALU uut(

);*/
reg [31:0] mul;
reg [15:0] opa,opb;

initial begin
	opa = 16'b1000000000000000;
	opb = 16'b1000000000000000;
	opa=-3;
	opb=-42;
	#32
	 mul = opa*opb;

end

endmodule
