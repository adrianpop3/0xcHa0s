`timescale 1ns / 1ps

module reg16(
    input clk,
    input rst,
	 input en,
    input [15:0] d,
    output reg [15:0] q
    );

always @(posedge clk) begin
	if(rst)
		q <= 0;
	else if(en)
		q <= d;
end

endmodule
