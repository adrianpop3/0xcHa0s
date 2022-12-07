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
reg [16:0] neg;
reg [15:0] opa;

initial begin
	opa = 16'h0001;
	#32
	neg = -opa;

end

endmodule
