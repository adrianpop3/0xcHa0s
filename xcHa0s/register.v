`timescale 1ns / 1ps

module register(clk,rst,en,d,q);

	parameter WIDTH = 16;

	input clk;
	input rst;
	input en;
	input [WIDTH-1:0] d;
	output reg [WIDTH-1:0] q;
	 
always @(posedge clk) begin
	if(rst)
		q <= 0;
	else if(en)
		q <= d;
end

endmodule
