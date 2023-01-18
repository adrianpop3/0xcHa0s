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

  reg [31:0]expected_pow;
  integer b;
  
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
		expo = -5;
		#20
		start=1;
		#20;
		while(ready == 0) #1;
		#5
		if(Cflag==0)
		    $display("(base is a negative number)error negative number should have set carry on 1");
		start=0;
		#200
		
		
		base = 0;
		expo = 0;
		start=1;
		#20;
		while(ready == 0) #1;
		#5;
		  if(Cflag==0)
		    $display("(0**0)error, should have set carry on 1");
		start=0;
		
		base = 12345;
		expo = 12345;
		start=1;
		#20;
		while(ready == 0) #1;
		#5;
		  if(Oflag==0)
		    $display("error, should have set overflow on 1");
		start=0;
	
		
		
		expo=1;
    while(expo<=35)begin
      base=0;
      while(base<(2**16)-1)begin
		  start=1;
		  #20;
		  while(ready == 0) #1;
		  #5;

      b={{16{base[15]}},base};
		  expected_pow=$floor($pow(b,expo));
		  if(expected_pow!=result)
		  $display("error: pow:base(%d),expo(%d) expected %h got %h ",base,expo,expected_pow,result);
		  
		   base=base+1;
		   end
		   expo=expo+1;
		end
		 $display("finished all tests\n",);    
		// Add stimulus here

	end
      
endmodule

