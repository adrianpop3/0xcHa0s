`timescale 1ns / 1ps

module controlUnit(
	input clk,
	input rst,
	
	input [15:0] instr,
	
	output reg branch,
	output reg ret,
	output reg loadPC,
	
	
	output reg push,
	output reg op_stack,
	
	output reg [4:0] opsel,
	output reg [1:0] sel_srcA,
	output reg [1:0] sel_srcB,
	input ready,
	
	output reg [1:0] data_addr_sel,
	output reg wr_to_data_mem,
	output reg mem_data_wr_sel,
	
	output reg reg_from_mem,
	output reg wr_X,
	output reg wr_Y,
	output reg wr_ACC,
	
	output reg save_flags,
	input [3:0] flags
);

localparam ZF = 3;
localparam NF = 2;
localparam CF = 1;
localparam OF = 0;

localparam sel_X = 	0;
localparam sel_Y = 	1;
localparam sel_ACC = 2;
localparam sel_imm = 3;
localparam sel_PC = 3;

localparam sel_addr_res = 		0;
localparam sel_addrimm = 	1;
localparam sel_SPreg = 		2;
localparam sel_SPnext = 	3;

`include "opcodes.v"
`include "opsel.v"

`define WR_ALU_RES_TO_ACC_WITH_FLAGS  	reg_from_mem = 0; wr_ACC = 1; save_flags = 1;
`define NO_WR_TO_ACC_WITH_FLAGS      	reg_from_mem = 0; wr_ACC = 0; save_flags = 1;

`define SEL_A_XY_SEL_B_ACC if(instr[9] == 0)sel_srcA = sel_X;else sel_srcA = sel_Y;  sel_srcB = sel_ACC;

always @(*) begin

	branch = 0;
	ret = 0;
	loadPC = ready;
	
	push = 0;
	op_stack = 0;
	
	opsel = 0;
	sel_srcA = 0;
	sel_srcB = 0;
	
	data_addr_sel = 0;
	wr_to_data_mem = 0;
	mem_data_wr_sel = 0;
	
	reg_from_mem = 0;
	wr_X = 0;
	wr_Y = 0;
	wr_ACC = 0;
	
	save_flags = 0;

	case(instr[15:10])
		`NOP: begin /*nothing to do*/ end
		`PUSH_POP: begin
			if(instr[9]) begin //PUSH
				push = 1;
				op_stack = 1;
				data_addr_sel = sel_SPnext;
				mem_data_wr_sel = instr[8:7];
				wr_to_data_mem = 1;
			end else begin //POP
				push = 0;
				op_stack = 1;
				data_addr_sel = sel_SPreg;
				reg_from_mem = 1;
				if(instr[8:7] == 0)
					wr_X = 1;
				else if(instr[8:7] == 1)
					wr_Y = 1;
				else
					wr_ACC = 1;
			end
		end
		
		`LOAD: begin
			data_addr_sel = sel_addrimm;
			reg_from_mem = 1;
			if(instr[9] == 0)
				wr_X = 1;
			else
				wr_Y = 1;
		end
		`STORE: begin
			data_addr_sel = sel_addrimm;
			if(instr[9] == 0)
				mem_data_wr_sel = sel_X;
			else
				mem_data_wr_sel = sel_Y;
			wr_to_data_mem = 1;
		end
		
		`LOADB: begin
			data_addr_sel = sel_addr_res;
			opsel = `ALU_ADD;
			sel_srcB = sel_imm;
			reg_from_mem = 1;
			if(instr[9] == 0) begin
				wr_X = 1;
				sel_srcA = sel_Y;
			end else begin
				wr_Y = 1;
				sel_srcA = sel_X;
			end
		end
		`STOREB: begin
			data_addr_sel = sel_addr_res;
			opsel = `ALU_ADD;
			sel_srcB = sel_imm;
			if(instr[9] == 0) begin
				mem_data_wr_sel = sel_X;
				sel_srcA = sel_Y;
			end else begin
				mem_data_wr_sel = sel_Y;
				sel_srcA = sel_X;
			end
			wr_to_data_mem = 1;
		end
		
		`MOVI: begin
			opsel = `ALU_SHORT_B;
			sel_srcB = sel_imm;
			reg_from_mem = 0;
			if(instr[9] == 0)
				wr_X = 1;
			else
				wr_Y = 1;
		end
		`MOVR: begin
			opsel = `ALU_SHORT_B;
			reg_from_mem = 0;
			if(instr[9] == 0) begin
				wr_X = 1;
				sel_srcB = sel_Y;
				if(instr[8]) sel_srcB = sel_ACC;
			end else begin
				wr_Y = 1;
				sel_srcB = sel_X;
				if(instr[8]) sel_srcB = sel_ACC;
			end
		end
		
		`RAD: begin
			opsel = `ALU_RAD;
			sel_srcA = sel_ACC;
			`WR_ALU_RES_TO_ACC_WITH_FLAGS
		end
		`POW: begin
			opsel = `ALU_POW;
			sel_srcA = sel_ACC;
			sel_srcB = instr[9:8];
			`WR_ALU_RES_TO_ACC_WITH_FLAGS
		end
	
		`BRA: branch = 1;
		`BRE: branch = flags[ZF];
		`BNE: branch = ~flags[ZF];
		`BLT: branch = (flags[NF] != flags[OF]);
		`BGT: branch = ((flags[ZF]==0) && (flags[OF] == flags[NF]));
		`BLE: branch = ((flags[ZF]==1) || (flags[OF] != flags[NF]));
		`BGE: branch = (flags[NF] == flags[OF]);
		`BRC: branch = flags[CF];
		`BRO: branch = flags[OF];
		
		`JMP: begin
			push = 1;
			op_stack = 1;
			data_addr_sel = sel_SPnext;
			mem_data_wr_sel = sel_PC;
			wr_to_data_mem = 1;
			
			branch = 1;
		end
		`RET: begin
			push = 0;
			op_stack = 1;
			data_addr_sel = sel_SPreg;
			ret = 1;
		end
		
		/////////// ARITHMETIC/LOGIC INSTRUNCTIONS //////////
		
		`ADDRI: begin
			opsel = `ALU_ADD;
			if(instr[9] == 0)
				sel_srcA = sel_X;
			else
				sel_srcA = sel_Y;
			sel_srcB = sel_imm;
			`WR_ALU_RES_TO_ACC_WITH_FLAGS
		end
		`ADDAI: begin
			opsel = `ALU_ADD;
			sel_srcA = sel_ACC;
			sel_srcB = sel_imm;
			`WR_ALU_RES_TO_ACC_WITH_FLAGS
		end
		`ADDXY: begin
			opsel = `ALU_ADD;
			sel_srcA = sel_X;
			sel_srcB = sel_Y;
			`WR_ALU_RES_TO_ACC_WITH_FLAGS
		end
		`ADDRA: begin
			opsel = `ALU_ADD;
			if(instr[9] == 0)
				sel_srcA = sel_X;
			else
				sel_srcA = sel_Y;
			sel_srcB = sel_ACC;
			`WR_ALU_RES_TO_ACC_WITH_FLAGS
		end
		
		`SUBRI: begin
			opsel = 	`ALU_SUB;
			if(instr[9] == 0)
				sel_srcA = sel_X;
			else
				sel_srcA = sel_Y;
			sel_srcB = sel_imm;
			`WR_ALU_RES_TO_ACC_WITH_FLAGS
		end
		`SUBAI: begin
			opsel = `ALU_SUB;
			sel_srcA = sel_ACC;
			sel_srcB = sel_imm;
			`WR_ALU_RES_TO_ACC_WITH_FLAGS
		end
		`SUBXY: begin
			opsel = `ALU_SUB;
			if(instr[8] == 0) begin
				sel_srcA = sel_X;
				sel_srcB = sel_Y;
			end else begin
				sel_srcA = sel_Y;
				sel_srcB = sel_X;
			end
			`WR_ALU_RES_TO_ACC_WITH_FLAGS
		end
		`SUBRA: begin
			opsel = `ALU_SUB;
			case(instr[9:8])
				2'b00: begin
					sel_srcA = sel_X;
					sel_srcB = sel_ACC;
				end
				2'b01: begin
					sel_srcA = sel_ACC;
					sel_srcB = sel_X;
				end
				2'b10: begin
					sel_srcA = sel_Y;
					sel_srcB = sel_ACC;
				end
				2'b11: begin
					sel_srcA = sel_ACC;
					sel_srcB = sel_Y;
				end
			endcase
			`WR_ALU_RES_TO_ACC_WITH_FLAGS
		end
		
		`SHIFT: begin // 6'b:instr  3'b:operation 2'b:op1 1'b:imm 4'b:immval/op2
			opsel = {1'b1,instr[4] | instr[1],instr[9:7]};
			sel_srcA = instr[6:5];
			if(instr[4]==1) begin
				//immediate shift amount
				sel_srcB = sel_imm;
			end else begin
				//shift amount in another register
				//instr[3:0] = 2'b:reg2/op2 1'b:truncate%16 'bx
				sel_srcB = instr[3:2];
			end
			`WR_ALU_RES_TO_ACC_WITH_FLAGS
		end
		
		`INC: begin
			opsel = `ALU_INC;
			sel_srcA = instr[9:8];
			`WR_ALU_RES_TO_ACC_WITH_FLAGS
		end
		`DEC: begin
			opsel = `ALU_DEC;
			sel_srcA = instr[9:8];
			`WR_ALU_RES_TO_ACC_WITH_FLAGS
		end
		
		`MULRA: begin
			opsel = `ALU_MUL;
			`SEL_A_XY_SEL_B_ACC
			`WR_ALU_RES_TO_ACC_WITH_FLAGS
		end
		`MULAI: begin
			opsel = `ALU_MUL;
			sel_srcA = sel_ACC;  sel_srcB = sel_imm;
			`WR_ALU_RES_TO_ACC_WITH_FLAGS
		end
		`DIVRA: begin
			opsel = `ALU_DIV;
			`SEL_A_XY_SEL_B_ACC
			`WR_ALU_RES_TO_ACC_WITH_FLAGS
		end
		`DIVAI: begin
			opsel = `ALU_DIV;
			sel_srcA = sel_ACC;  sel_srcB = sel_imm;
			`WR_ALU_RES_TO_ACC_WITH_FLAGS
		end
		`MODRA: begin
			opsel = `ALU_MOD;
			`SEL_A_XY_SEL_B_ACC
			`WR_ALU_RES_TO_ACC_WITH_FLAGS
		end
		`MODAI: begin
			opsel = `ALU_MOD;
			sel_srcA = sel_ACC;  sel_srcB = sel_imm;
			`WR_ALU_RES_TO_ACC_WITH_FLAGS
		end
		
		`ANDRA: begin
			opsel = `ALU_AND;
			`SEL_A_XY_SEL_B_ACC
			`WR_ALU_RES_TO_ACC_WITH_FLAGS
		end
		`ANDAI: begin
			opsel = `ALU_AND;
			sel_srcA = sel_ACC;  sel_srcB = sel_imm;
			`WR_ALU_RES_TO_ACC_WITH_FLAGS
		end
		`ORRA: begin
			opsel = `ALU_OR;
			`SEL_A_XY_SEL_B_ACC
			`WR_ALU_RES_TO_ACC_WITH_FLAGS
		end
		`ORAI: begin
			opsel = `ALU_OR;
			sel_srcA = sel_ACC;  sel_srcB = sel_imm;
			`WR_ALU_RES_TO_ACC_WITH_FLAGS
		end
		`XORRA: begin
			opsel = `ALU_XOR;
			`SEL_A_XY_SEL_B_ACC
			`WR_ALU_RES_TO_ACC_WITH_FLAGS
		end
		`XORAI: begin
			opsel = `ALU_XOR;
			sel_srcA = sel_ACC;  sel_srcB = sel_imm;
			`WR_ALU_RES_TO_ACC_WITH_FLAGS
		end
		
		`NOT: begin
			opsel = `ALU_NOT;
			sel_srcA = instr[9:8];
			`WR_ALU_RES_TO_ACC_WITH_FLAGS
		end
		`NEG: begin
			opsel = `ALU_NEG;
			sel_srcA = instr[9:8];
			`WR_ALU_RES_TO_ACC_WITH_FLAGS
		end
		
		`CMPRI: begin
			opsel = 	`ALU_SUB;
			if(instr[9] == 0)
				sel_srcA = sel_X;
			else
				sel_srcA = sel_Y;
			sel_srcB = sel_imm;
			`NO_WR_TO_ACC_WITH_FLAGS
		end
		`CMPAI: begin
			opsel = `ALU_SUB;
			sel_srcA = sel_ACC;
			sel_srcB = sel_imm;
			`NO_WR_TO_ACC_WITH_FLAGS
		end
		`CMPRR: begin
			opsel = `ALU_SUB;
			sel_srcA = instr[9:8];
			sel_srcB = instr[7:6];
			`NO_WR_TO_ACC_WITH_FLAGS
		end
		
		
		`TSTRI: begin
			opsel = 	`ALU_AND;
			if(instr[9] == 0)
				sel_srcA = sel_X;
			else
				sel_srcA = sel_Y;
			sel_srcB = sel_imm;
			`NO_WR_TO_ACC_WITH_FLAGS
		end
		`TSTAI: begin
			opsel = `ALU_AND;
			sel_srcA = sel_ACC;
			sel_srcB = sel_imm;
			`NO_WR_TO_ACC_WITH_FLAGS
		end
		`TSTRR: begin
			opsel = `ALU_AND;
			sel_srcA = instr[9:8];
			sel_srcB = instr[7:6];
			`NO_WR_TO_ACC_WITH_FLAGS
		end
		
		
		
	endcase
end

endmodule
