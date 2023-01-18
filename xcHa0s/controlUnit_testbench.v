`timescale 1ns / 1ps
module controlUnit_testbench();
	reg [15:0] instr;
	
	wire branch;
	reg branch_exp;//pt citire din fisier
	wire ret;
	reg ret_exp;//pt citire din fisier
	wire loadPC;
	reg loadPC_exp;//pt citire din fisier
	
	
	wire push;
	reg push_exp;
	wire op_stack;
	reg op_stack_exp;
	
	wire [4:0] opsel;
	reg [4:0] opsel_exp;//ce op ii dau sa faca la alu
	wire [1:0] sel_srcA;
	reg [1:0] sel_srcA_exp;
	wire [1:0] sel_srcB;
	reg [1:0] sel_srcB_exp;
	reg ready;
	
	wire [1:0] data_addr_sel;
	reg [1:0] data_addr_sel_exp;//adr la care scriu/citesc in mem de cine e data?
	wire wr_to_data_mem;
	reg wr_to_data_mem_exp;
  wire [1:0] mem_data_wr_sel;
  reg [1:0] mem_data_wr_sel_exp;//ce date scriu in memorie
	
	wire reg_from_mem;
	reg reg_from_mem_exp;//scriu in reistru din memorie?
	wire extra_write_X;
	reg extra_write_X_exp;
	wire wr_X;
	reg wr_X_exp;
	wire wr_Y;
	reg wr_Y_exp;
	wire wr_ACC;
	reg wr_ACC_exp;
	
	wire save_flags;
	reg save_flags_exp;
	reg [3:0] flags;//de intrare
  
    
controlUnit uut(//intantiere
  .instr(instr),
  .branch(branch),
  .ret(ret),
  .loadPC(loadPC),
  .push(push),
  .op_stack(op_stack),
  .opsel(opsel),
  .sel_srcA(sel_srcA),
  .sel_srcB(sel_srcB),
  .ready(ready),
  .data_addr_sel(data_addr_sel),
  .wr_to_data_mem(wr_to_data_mem),
  .mem_data_wr_sel(mem_data_wr_sel),
  .reg_from_mem(reg_from_mem),
  .extra_write_X(extra_write_X),
  .wr_X(wr_X),
  .wr_Y(wr_Y),
  .wr_ACC(wr_ACC),
  .save_flags(save_flags),
  .flags(flags)
  );

  
  
  integer o,r;
  initial begin
  o=$fopen("./controlU.bin","r");//deschis fisier
  $display("file:%0d",o);
  while(!$feof(o)) begin
  r=$fscanf(o,"%b %b %b",instr,ready,flags);//citire din fisier
  r=$fscanf(o,"%b %b %b %b %b %b %b %b %b %b %b %b %b %b %b %b %b",branch_exp, ret_exp, loadPC_exp, push_exp, op_stack_exp, opsel_exp, sel_srcA_exp, sel_srcB_exp, data_addr_sel_exp, wr_to_data_mem_exp, mem_data_wr_sel_exp, reg_from_mem_exp,extra_write_X_exp, wr_X_exp, wr_Y_exp, wr_ACC_exp, save_flags_exp);
  //load_pc_exp=1;
  //$display("%b%b%b",instr,ready,flags);
  #1;//timp sa calculeze
  if (branch_exp!=branch)begin
    $display("error: %b, exp-branch_exp:%b got %b",instr,branch_exp,branch);
  end
  if (ret_exp!=ret)begin
    $display("error: %b, exp-ret_exp:%b got %b",instr,ret_exp,ret);
  end
  if (loadPC_exp!=loadPC)begin
    $display("error: %b, exp-loadPC_exp:%b got %b",instr,loadPC_exp,loadPC);
  end
  if (push_exp!=push)begin
    $display("error: %b, exp-push_exp:%b got %b",instr,push_exp,push);
  end
  if (op_stack_exp!=op_stack)begin
    $display("error: %b, exp-op_stack_exp:%b got %b",instr,op_stack_exp,op_stack);
  end
  if (opsel_exp!=opsel)begin
    $display("error: %b, exp-opsel_exp:%b got %b",instr,opsel_exp,opsel);
  end
  if (sel_srcA_exp!=sel_srcA)begin
    $display("error: %b, exp-sel_srcA_exp:%b got %b",instr,sel_srcA_exp,sel_srcA);
  end
  if (sel_srcB_exp!=sel_srcB)begin
    $display("error: %b, exp-sel_srcB_exp:%b got %b",instr,sel_srcB_exp,sel_srcB);
  end
  if (data_addr_sel_exp!=data_addr_sel)begin
    $display("error: %b, exp-data_addr_sel_exp:%b got %b",instr,data_addr_sel_exp,data_addr_sel);
  end
  if (wr_to_data_mem_exp!=wr_to_data_mem)begin
    $display("error: %b, exp-wr_to_data_mem_exp:%b got %b",instr,wr_to_data_mem_exp,wr_to_data_mem);
  end
  if (mem_data_wr_sel_exp!=mem_data_wr_sel)begin
    $display("error: %b, exp-mem_data_wr_sel_exp:%b got %b",instr,mem_data_wr_sel_exp,mem_data_wr_sel);
  end
  if (reg_from_mem_exp!=reg_from_mem)begin
    $display("error: %b, exp-reg_from_mem_exp:%b got %b",instr,reg_from_mem_exp,reg_from_mem);
  end
  if (extra_write_X_exp!=extra_write_X)begin
    $display("error: %b, exp-extra_write_X_exp:%b got %b",instr,extra_write_X_exp,extra_write_X);
  end
  if (wr_X_exp!=wr_X)begin
    $display("error: %b, exp-wr_X_exp:%b got %b",instr,wr_X_exp,wr_X);
  end
  if (wr_Y_exp!=wr_Y)begin
    $display("error: %b, exp-wr_Y_exp:%b got %b",instr,wr_Y_exp,wr_Y);
  end
  if (wr_ACC_exp!=wr_ACC)begin
    $display("error: %b, exp-wr_ACC_exp:%b got %b",instr,wr_ACC_exp,wr_ACC);
  end
  if (save_flags_exp!=save_flags)begin
    $display("error: %b, exp-save_flags_exp:%b got %b",instr,save_flags_exp,save_flags);
  end
  
     $display("\n");
  //$display("expected:%b%b",load_pc_exp,wr_x_exp);
  //$display("actual:%b%b",loadPC,wr_X);
  end
  $fclose(o);
  end
 
  //citesc inrare si dupa toate de iesirrile in c scru si acici citesc
  //reg load_pc_exp, wr_x_exp;//pt citire din fisier la fel pt fiecare semn de iesire si declar tot sus
 // si le citeste fscanf pe alea cu reg si dupa compar(load pc cu load pc_exp
  
  

endmodule
