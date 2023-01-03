`timescale 1ns / 1ps


module sqrt_tb;

	// Inputs
	reg clk;
	reg rst;
	reg start;
	reg [31:0] initial_nr;

	// Outputs
	wire ready;
	wire [15:0] result;
	wire Cflag;
	wire Oflag;

	// Instantiate the Unit Under Test (UUT)
	sqrt uut (
		.clk(clk), 
		.rst(rst), 
		.start(start), 
		.ready(ready), 
		.initial_nr(initial_nr), 
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
		initial_nr = 0;

		// Wait 100 ns for global reset to finish
		#55;
		rst = 0;
		#40;
		initial_nr = -64;
		#20
		start=1;
		#20;
		while(ready == 0) #1;
		#5
		start=0;
        
		// Add stimulus here

	end
      
endmodule

