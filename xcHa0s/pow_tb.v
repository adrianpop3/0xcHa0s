`timescale 1ns / 1ps
module pow_tb;

	// Inputs
	reg clk;
	reg rst;
	reg start;
	reg [15:0] base;
	reg [15:0] expo;

	// Outputs
	wire ready;
	wire [31:0] result;
	wire Cflag;
	wire Oflag;

	// Instantiate the Unit Under Test (UUT)
	pow uut (
		.clk(clk), 
		.rst(rst), 
		.start(start), 
		.ready(ready), 
		.base(base), 
		.expo(expo), 
		.result(result), 
		.Cflag(Cflag), 
		.Oflag(Oflag)
	);
	
	initial forever begin
		#10 clk = ~clk;
	end

	initial begin
		// Initialize Inputs
		clk = 0;
		rst = 1;
		start = 0;
		base = 0;
		expo = 0;

		// Wait 100 ns for global reset to finish
		#55;
		rst=0;
		#40;
		base = 5;
		expo = 5;
		#20
		start=1;
		#20;
		while(ready == 0) #1;
		#5
		start=0;
		#200
		base = 21;
		expo = 3;
		start=1;
		#20;
		while(ready == 0) #1;
		start=0;
		
        
		// Add stimulus here

	end
      
endmodule

