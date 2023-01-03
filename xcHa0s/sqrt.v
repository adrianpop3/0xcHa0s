`timescale 1ns / 1ps

module sqrt(
	input clk,rst,
	input start,
	output reg ready,
	input [31:0] initial_nr,
	output [15:0] result,
	output reg Cflag,Oflag
    );
	 
`define IDLE 0
`define SH 1
`define SUB 2

reg [1:0] state_reg,state_nxt;
reg [63:0] operand,operand_nxt;
reg [15:0] res_tmp,res_tmp_nxt;
reg [7:0] cnt,cnt_nxt;
assign result = res_tmp;

always @(posedge clk) begin
	if(rst) begin
		state_reg <= `IDLE;
		operand <= 0;
		res_tmp <= 0;
		cnt <= 0;
	end else begin
		state_reg <= state_nxt;
		operand <= operand_nxt;
		res_tmp <= res_tmp_nxt;
		cnt <= cnt_nxt;
	end
end

always @(*) begin
	state_nxt = state_reg;
	operand_nxt = operand;
	res_tmp_nxt = res_tmp;
	ready = 0;
	Cflag = 0;
	Oflag = 0;
	case(state_reg)
		`IDLE: begin
			if(start) begin
				state_nxt = `SH;
				operand_nxt = {32'b0,initial_nr};
				res_tmp_nxt = 0;
				cnt_nxt = 16;
			end
		end
		`SH: begin
			operand_nxt = operand<<2;
			if(cnt == 0 || (cnt == 16 && operand[31])) begin
				if(operand[31])
					Cflag = 1;
				state_nxt = `IDLE;
				Oflag = res_tmp[15];
				ready = 1;
			end else
				state_nxt = `SUB;
		end
		`SUB: begin
			cnt_nxt = cnt - 1;
			if(operand[63:32] >= {14'b0,res_tmp,2'b01}) begin
				operand_nxt[63:32] = operand[63:32] - {14'b0,res_tmp,2'b01};
				res_tmp_nxt = {res_tmp[14:0],1'b1};
			end else begin
				res_tmp_nxt = {res_tmp[14:0],1'b0};
			end
			state_nxt = `SH;
		
		end
		
	
	endcase

end

endmodule
