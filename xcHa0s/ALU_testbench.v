`timescale 1ns / 1ps
module ALU_testbench(
    );
  reg clk;
	reg rst;
	reg [15:0] srcA;
	reg [15:0] srcB;
	reg [15:0] extra_X;
	wire [15:0] res;
	reg [15:0] res_exp;
	wire [15:0] extra_res;
	reg [15:0] extra_res_exp;
	
	reg [4:0] opsel;
	wire ready;
	reg ready_exp;
	reg Cflag;
	reg Oflag;
	wire [3:0] flag_next;
	reg [3:0] flag_next_exp;
  
ALU uut(
  .clk(clk),
  .rst(rst),
  .srcA(srcA),
  .srcB(srcB),
  .extra_X(extra_X),
  .res(res),
  .extra_res(extra_res),
  .opsel(opsel),
  .ready(ready),
  .Cflag(Cflag),
  .Oflag(Oflag),
  .flag_next(flag_next)
);
reg [16:0] shift_aid;
wire [16:0] sign_srcA;


  /*integer o,r;
  initial begin
  o=$fopen("./alu.bin","r");//deschis fisier
  $display("file:%0d",o);
  while(!$feof(o)) begin
  r=$fscanf(o,"%b %b %b %b %b",srcA,srcB,extra_X,opsel,Cflag,Oflag);//citire din fisier
  r=$fscanf(o,"%b %b",res_exp,extra_res_exp,ready_exp,flag_next_exp);
  //load_pc_exp=1;
  //$display("%b%b%b",instr,ready,flags);
  #1;//timp sa calculeze
  while(ready==0)begin
  end
  if (res_exp!=res)begin
    $display("error-res_exp: %b, exp-wr_Y_exp:%b got %b",res,flag_next_exp,flag_next);
  end
  if (extra_res_exp!=extra_res)begin
    $display("error-extra_res_exp: %b, exp-wr_Y_exp:%b got %b",res,ready_exp,ready);
  end
  if (ready_exp!=ready)begin
    $display("error-ready_exp: %b, exp-wr_Y_exp:%b got %b",res,flag_next_exp,flag_next);
  end
  if (flag_next_exp!=flag_next)begin
    $display("error-flag_next_exp: %b, exp-wr_Y_exp:%b got %b",res,flag_next_exp,flag_next);
  end
  
end
  $fclose(o);
  end*/

`define ZF	3
`define NF	2
`define CF	1
`define OF	0

 initial forever begin
		#10 clk = ~clk;
	end

  reg [31:0]expected_res;
  
  `include "opsel.v"
	initial begin
		// Initialize Inputs
		clk = 0;
		rst = 1;
		srcA = 0;
		srcB = 0;

		// Wait 100 ns for global reset to finish
		#55;
		rst=0;
		#40;
		
		
		opsel=`ALU_SHORT_B;
	  repeat (1000) begin 
	    srcB=$random;
	    #20;
		  while(ready == 0) #1;
		  #5;
		  expected_res=srcB;
		  if(expected_res[15:0]!=res)
		    $display("error %d expected_res:%b got %b",srcB,expected_res,res);
	  end
	  $display("finished all SHORT_B tests \n",);
	  
	  
		
	  opsel=`ALU_ADD;
	  repeat (1000) begin 
	    srcA=$random;
	    srcB=$random;
	    #20;
		  while(ready == 0) #1;
		  #5;
		  expected_res=srcA+srcB;
		  if(expected_res[15:0]!=res)
		    $display("error %d+%d expected_res:%b got %b",srcA,srcB,expected_res,res);
		  if(flag_next[`NF]!=expected_res[15])
		    $display("NF error %d+%d, negative flags ",srcA,srcB);
		  if(flag_next[`ZF]!=(expected_res[15:0]==0))
		    $display("ZF error %d+%d, zero flags ",srcA,srcB);
		  if(flag_next[`CF]!=expected_res[16])
		    $display("CF error %d+%d, carry flags ",srcA,srcB);
		  if(flag_next[`OF]!=((srcA[15]&srcB[15]&(~expected_res[15]))|((~srcA[15])&(~srcB[15])&expected_res[15])))
		    $display("OF error %d+%d, overflow flags ",srcA,srcB);  
	  end
	  $display("finished all ADD tests \n",);
	  
	  
	  
	  opsel=`ALU_SUB;
	  repeat (1000) begin 
	    srcA=$random;
	    srcB=$random;
	    #20;
		  while(ready == 0) #1;
		  #5;
		  expected_res=srcA-srcB;
		  if(expected_res[15:0]!=res)
		    $display("error %d-%d expected_res:%b got %b",srcA,srcB,expected_res,res);
		  if(flag_next[`NF]!=expected_res[15])
		    $display("NF error %d-%d, negative flags ",srcA,srcB);
		  if(flag_next[`ZF]!=(expected_res[15:0]==0))
		    $display("ZF error %d-%d, zero flags ",srcA,srcB);
		  if(flag_next[`CF]!=expected_res[16])
		    $display("CF error %d-%d, carry flags ",srcA,srcB);
		  if(flag_next[`OF]!=((srcA[15]&(~srcB[15])&(~expected_res[15]))|((~srcA[15])&srcB[15]&expected_res[15])))
		    $display("OF error %d-%d, overflow flags ",srcA,srcB);  
	  end
	  $display("finished all SUB tests \n",);
	  
	  
	  opsel=`ALU_INC;
	  repeat (1000) begin 
	    srcA=$random;
	    #20;
		  while(ready == 0) #1;
		  #5;
		  expected_res=srcA+1;
		  if(expected_res[15:0]!=res)
		    $display("error %d+1 expected_res:%b got %b",srcA,expected_res,res);
		  if(flag_next[`NF]!=expected_res[15])
		    $display("NF error %d+1, negative flags ",srcA);
		  if(flag_next[`ZF]!=(expected_res[15:0]==0))
		    $display("ZF error %d+1, zero flags ",srcA);
		  if(flag_next[`CF]!=expected_res[16])
		    $display("CF error %d+1, carry flags ",srcA);
		  if(flag_next[`OF]!=((~srcA[15])&expected_res[15]))
		    $display("OF error %d+1, overflow flags ",srcA);  
	  end
	  $display("finished all INC tests \n",);
	  
	  
	  opsel=`ALU_DEC;
	  repeat (1000) begin 
	    srcA=$random;
	    #20;
		  while(ready == 0) #1;
		  #5;
		  expected_res=srcA-1;
		  if(expected_res[15:0]!=res)
		    $display("error %d-1 expected_res:%b got %b",srcA,expected_res,res);
		  if(flag_next[`NF]!=expected_res[15])
		    $display("NF error %d-1, negative flags ",srcA);
		  if(flag_next[`ZF]!=(expected_res[15:0]==0))
		    $display("ZF error %d-1, zero flags ",srcA);
		  if(flag_next[`CF]!=expected_res[16])
		    $display("CF error %d-1, carry flags ",srcA);
		  if(flag_next[`OF]!=(srcA[15]&(~expected_res[15])))
		    $display("OF error %d-1, overflow flags ",srcA);  
	  end
	  $display("finished all DEC tests \n",);
	  
	  
	   opsel=`ALU_AND;
	  repeat (1000) begin 
	    srcA=$random;
	    srcB=$random;
	    #20;
		  while(ready == 0) #1;
		  #5;
		  expected_res=srcA&srcB;
		  if(expected_res[15:0]!=res)
		    $display("error %d&%d expected_res:%b got %b",srcA,srcB,expected_res,res);
		  if(flag_next[`NF]!=expected_res[15])
		    $display("NF error %d&%d, negative flags ",srcA,srcB);
		  if(flag_next[`ZF]!=(expected_res[15:0]==0))
		    $display("ZF error %d&%d, zero flags ",srcA,srcB); 
	  end
	  $display("finished all AND tests \n",);
	  
	  
	  opsel=`ALU_OR;
	  repeat (1000) begin 
	    srcA=$random;
	    srcB=$random;
	    #20;
		  while(ready == 0) #1;
		  #5;
		  expected_res=srcA|srcB;
		  if(expected_res[15:0]!=res)
		    $display("error %d|%d expected_res:%b got %b",srcA,srcB,expected_res,res);
		  if(flag_next[`NF]!=expected_res[15])
		    $display("NF error %d|%d, negative flags ",srcA,srcB);
		  if(flag_next[`ZF]!=(expected_res[15:0]==0))
		    $display("ZF error %d|%d, zero flags ",srcA,srcB); 
	  end
	  $display("finished all OR tests \n",);
	    
		
		opsel=`ALU_XOR;
	  repeat (1000) begin 
	    srcA=$random;
	    srcB=$random;
	    #20;
		  while(ready == 0) #1;
		  #5;
		  expected_res=srcA^srcB;
		  if(expected_res[15:0]!=res)
		    $display("error %d^%d expected_res:%b got %b",srcA,srcB,expected_res,res);
		  if(flag_next[`NF]!=expected_res[15])
		    $display("NF error %d^%d, negative flags ",srcA,srcB);
		  if(flag_next[`ZF]!=(expected_res[15:0]==0))
		    $display("ZF error %d^%d, zero flags ",srcA,srcB); 
	  end
	  $display("finished all XOR tests \n",);
		
		
		opsel=`ALU_NOT;
	  repeat (1000) begin 
	    srcA=$random;
	    #20;
		  while(ready == 0) #1;
		  #5;
		  expected_res=~srcA;
		  if(expected_res[15:0]!=res)
		    $display("error ~%d expected_res:%b got %b",srcA,expected_res,res);
		  if(flag_next[`NF]!=expected_res[15])
		    $display("NF error ~%d, negative flags ",srcA);
		  if(flag_next[`ZF]!=(expected_res[15:0]==0))
		    $display("ZF error ~%d, zero flags ",srcA); 
	  end
	  $display("finished all NOT tests \n",);
	  
	  
	  opsel=`ALU_NEG;
	  repeat (1000) begin 
	    srcA=$random;
	    #20;
		  while(ready == 0) #1;
		  #5;
		  expected_res=-srcA;
		  if(expected_res[15:0]!=res)
		    $display("error -%d expected_res:%b got %b",srcA,expected_res,res);
		  if(flag_next[`NF]!=expected_res[15])
		    $display("NF error -%d, negative flags ",srcA);
		  if(flag_next[`ZF]!=(expected_res[15:0]==0))
		    $display("ZF error -%d, zero flags ",srcA); 
	  end
	  $display("finished all NEG tests \n",);
		
		
		
		opsel=`ALU_RSL_M;
	  repeat (1000) begin 
	    srcA=$random;
	    srcB=$random;
	    #20;
		  while(ready == 0) #1;
		  #5;
		  shift_aid={srcA,1'b0}>>(srcB & 16'h000f);
		  expected_res=shift_aid[16:1];
		  if(expected_res[15:0]!=res)
		    $display("error ALU_RSL_M expected_res:%b got %b",expected_res,res);
		  if(flag_next[`NF]!=expected_res[15])
		    $display("NF error ALU_RSL_M, negative flags ");
		  if(flag_next[`ZF]!=(expected_res[15:0]==0))
		    $display("ZF error ALU_RSL_M, zero flags ");
		  if(flag_next[`CF]!=shift_aid[0])
		    $display("CF error ALU_RSL_M, carry flags ");
		  if(flag_next[`OF]!=(expected_res[15] != srcA[15]))
		    $display("OF error ALU_RSL_M, overflow flags ");  
	  end
	  $display("finished all RSL_M tests \n",);
		
		
		opsel=`ALU_LSL_M;
	  repeat (1000) begin 
	    srcA=$random;
	    srcB=$random;
	    #20;
		  while(ready == 0) #1;
		  #5;
		  shift_aid={1'b0,srcA}<<(srcB & 16'h000f);
		  expected_res=shift_aid[15:0];
		  if(expected_res[15:0]!=res)
		    $display("error ALU_LSL_M expected_res:%b got %b",expected_res,res);
		  if(flag_next[`NF]!=expected_res[15])
		    $display("NF error ALU_LSL_M, negative flags ");
		  if(flag_next[`ZF]!=(expected_res[15:0]==0))
		    $display("ZF error ALU_LSL_M, zero flags ");
		  if(flag_next[`CF]!=shift_aid[16])
		    $display("CF error ALU_LSL_M, carry flags ");
		  if(flag_next[`OF]!=(expected_res[15] != srcA[15]))
		    $display("OF error ALU_LSL_M, overflow flags ");  
	  end
	  $display("finished all LSL_M tests \n",);
	  
	  
	  opsel=`ALU_RSA_M;
	  repeat (1000) begin 
	    srcA=$random;
	    srcB=$random;
	    #20;
		  while(ready == 0) #1;
		  #5;
		  shift_aid=({srcA,1'b0}>>(srcB & 16'h000f))| (sign_srcA<<(16-(srcB & 16'h000f)));
		  expected_res=shift_aid[16:1];
		  if(expected_res[15:0]!=res)
		    $display("error ALU_RSA_M expected_res:%b got %b",expected_res,res);
		  if(flag_next[`NF]!=expected_res[15])
		    $display("NF error ALU_RSA_M, negative flags ");
		  if(flag_next[`ZF]!=(expected_res[15:0]==0))
		    $display("ZF error ALU_RSA_M, zero flags ");
		  if(flag_next[`CF]!=shift_aid[0])
		    $display("CF error ALU_RSA_M, carry flags ");
		  if(flag_next[`OF]!=(expected_res[15] != srcA[15]))
		    $display("OF error ALU_RSA_M, overflow flags ");  
	  end
	  $display("finished all RSA_M tests \n",);
		
		
		opsel=`ALU_LSA_M;
	  repeat (1000) begin 
	    srcA=$random;
	    srcB=$random;
	    #20;
		  while(ready == 0) #1;
		  #5;
		  shift_aid=({1'b0,srcA}<<(srcB & 16'h000f))| (sign_srcA>>(16-(srcB & 16'h000f)));
		  expected_res=shift_aid[15:0];
		  if(expected_res[15:0]!=res)
		    $display("error ALU_LSA_M expected_res:%b got %b",expected_res,res);
		  if(flag_next[`NF]!=expected_res[15])
		    $display("NF error ALU_LSA_M, negative flags ");
		  if(flag_next[`ZF]!=(expected_res[15:0]==0))
		    $display("ZF error ALU_LSA_M, zero flags ");
		  if(flag_next[`CF]!=shift_aid[16])
		    $display("CF error ALU_LSA_M, carry flags ");
		  if(flag_next[`OF]!=(expected_res[15] != srcA[15]))
		    $display("OF error ALU_LSA_M, overflow flags ");  
	  end
	  $display("finished all LSA_M tests \n",);
	  
	  
	  opsel=`ALU_RSR_M;
	  repeat (1000) begin 
	    srcA=$random;
	    srcB=$random;
	    #20;
		  while(ready == 0) #1;
		  #5;
		  shift_aid={1'b0,(srcA>>(srcB & 16'h000f))|(srcA<<(16-(srcB & 16'h000f)))};
		  expected_res=shift_aid[15:0];
		  if(expected_res[15:0]!=res)
		    $display("error ALU_RSR_M expected_res:%b got %b",expected_res,res);
		  if(flag_next[`NF]!=expected_res[15])
		    $display("NF error ALU_RSR_M, negative flags ");
		  if(flag_next[`ZF]!=(expected_res[15:0]==0))
		    $display("ZF error ALU_RSR_M, zero flags ");
		  if(flag_next[`CF]!=shift_aid[15])
		    $display("CF error ALU_RSR_M, carry flags ");
		  if(flag_next[`OF]!=(expected_res[15] != srcA[15]))
		    $display("OF error ALU_RSR_M, overflow flags ");  
	  end
	  $display("finished all RSR_M tests \n",);
	  
	  
	   opsel=`ALU_LSR_M;
	  repeat (1000) begin 
	    srcA=$random;
	    srcB=$random;
	    #20;
		  while(ready == 0) #1;
		  #5;
		  shift_aid={1'b0,(srcA<<(srcB & 16'h000f))|(srcA>>(16-(srcB & 16'h000f)))};
		  expected_res=shift_aid[15:0];
		  if(expected_res[15:0]!=res)
		    $display("error ALU_LSR_M expected_res:%b got %b",expected_res,res);
		  if(flag_next[`NF]!=expected_res[15])
		    $display("NF error ALU_LSR_M, negative flags ");
		  if(flag_next[`ZF]!=(expected_res[15:0]==0))
		    $display("ZF error ALU_LSR_M, zero flags ");
		  if(flag_next[`CF]!=shift_aid[0])
		    $display("CF error ALU_LSR_M, carry flags ");
		  if(flag_next[`OF]!=(expected_res[15] != srcA[15]))
		    $display("OF error ALU_LSR_M, overflow flags ");  
	  end
	  $display("finished all LSR_M tests \n",);
	  
	  
	  
	  
	end

endmodule