`timescale 1ns / 1ps

module reg4(
    input clk,
    input rst,
	 input en,
    input [3:0] d,
    output reg [3:0] q
    );

always @(posedge clk) begin
	if(rst)
		q <= 0;
	else if(en)
		q <= d;
end

endmodule
