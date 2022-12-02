`timescale 1ns / 1ps

module reg10(
    input clk,
    input rst,
	 input en,
    input [9:0] d,
    output reg [9:0] q
    );

always @(posedge clk) begin
	if(rst)
		q <= 0;
	else if(en)
		q <= d;
end

endmodule
