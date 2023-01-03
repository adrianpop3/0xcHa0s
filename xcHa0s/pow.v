`timescale 1ns / 1ps

module pow(
	input clk,rst,
	input start,
	output reg ready,
	input [15:0] base,expo,
	output [31:0] result,
	output reg Cflag,Oflag
    );

reg is_idle,is_idle_nxt;
reg [47:0] tmp_res,tmp_res_nxt,tmp_tmp;
reg [15:0] base_reg,base_nxt,expo_reg,expo_nxt;
assign result = tmp_res[31:0];
reg Oflag_nxt;

always @(posedge clk) begin
	if(rst) begin
		is_idle <= 1;
		tmp_res <= 0;
		base_reg <= 0;
		expo_reg <= 0;
		Oflag <= 0;
	end else begin
		is_idle <= is_idle_nxt;
		tmp_res <= tmp_res_nxt;
		base_reg <= base_nxt;
		expo_reg <= expo_nxt;
		Oflag <= Oflag_nxt;
	end
end

always @(*) begin
	is_idle_nxt = is_idle;
	base_nxt = base_reg;
	expo_nxt = expo_reg;
	Oflag_nxt = Oflag;
	tmp_res_nxt = tmp_res;
	Cflag = 0;
	if(is_idle) begin
		ready = 0;
		if(start) begin
			is_idle_nxt = 0;
			base_nxt = base;
			expo_nxt = expo;
			tmp_res_nxt = 1;
			Oflag_nxt = 0;
		end
	end else begin //multiply
		if(expo_reg == 0 || expo_reg[15]) begin
			//Cflag = 0;
			if((expo_reg == 0 && base_reg == 0) || expo_reg[15])
				Cflag = 1;//0^0 -- error or negative exponent
			ready=1;
			is_idle_nxt = 1;
		end else begin
			expo_nxt = expo_reg - 1;
			
			tmp_tmp = (tmp_res[47]?-tmp_res:tmp_res) * {32'b0,(base_reg[15]?-base_reg:base_reg)};
			tmp_res_nxt = (tmp_res[47] ^ base_reg[15])?-tmp_tmp:tmp_tmp;
			
			if((tmp_res_nxt&48'hFFFF80000000) != 0 && (tmp_res_nxt&48'hFFFF80000000) != 48'hFFFF80000000)
				Oflag_nxt = 1;
		end
	
	end

end

endmodule
