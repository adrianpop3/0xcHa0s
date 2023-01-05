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
  
  reg ok;
  reg [15:0]expected_sqrt;
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
		//initial_nr = -64;
		initial_nr=-9;
		start=1;
		  #20;
		  while(ready == 0) #1;
		  #5;
		  if(Cflag==0)
		    $display("error negative number should have set carry on 1");
		    
		    
		initial_nr=(2**31)-1;
		start=1;
		  #20;
		  while(ready == 0) #1;
		  #5;
		  if(Oflag==0)
		    $display("error negative number should have set overflow on 1");
		
		
		initial_nr=0;
		ok=1;
		
		while(ok==1)begin
		  start=1;
		  #20;
		  while(ready == 0) #1;
		  #5;
		  //$display("sqrt(%d)=%d",initial_nr,result);
		  expected_sqrt=$floor($sqrt(initial_nr));
		  if(expected_sqrt!=result)
		  $display("error: sqrt(%d)expected %h got %h ",initial_nr,expected_sqrt,result);
		  if(initial_nr==(2**31)-1)ok=0;
		  initial_nr=initial_nr+1;
		  if(initial_nr%1000==0)
		    $display("Finished %d test",initial_nr);
		    
		end
		 $display("finished all tests\n",);
        
		// Add stimulus here

	end
      
endmodule

