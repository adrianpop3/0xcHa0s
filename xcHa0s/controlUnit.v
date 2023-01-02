`timescale 1ns / 1ps

module controlUnit(
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
	output reg [1:0] mem_data_wr_sel,
	
	output reg reg_from_mem,
	output reg extra_write_X,
	output reg wr_X,
	output reg wr_Y,
	output reg wr_ACC,
	
	output reg save_flags,
	input [3:0] flags
);

`define ZF	3
`define NF	2
`define CF	1
`define OF	0

`define sel_X		0
`define sel_Y		1
`define sel_ACC	2
`define sel_imm	3
`define sel_PC		3

`define sel_addr_res		0
`define sel_addrimm		1
`define sel_SPreg			2
`define sel_SPnext		3

`include "opcodes.v"
`include "opsel.v"

`define WR_ALU_RES_TO_ACC_WITH_FLAGS  	reg_from_mem = 0; wr_ACC = ready; save_flags = ready;
`define NO_WR_TO_ACC_WITH_FLAGS      	reg_from_mem = 0; wr_ACC = 0; save_flags = ready;

//`define SEL_A_XY_SEL_B_ACC if(instr[9] == 0)sel_srcA = `sel_X;else sel_srcA = `sel_Y;  sel_srcB = `sel_ACC;

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
	extra_write_X = 0;
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
				data_addr_sel = `sel_SPnext;
				mem_data_wr_sel = instr[8:7];
				wr_to_data_mem = ready;
			end else begin //POP
				push = 0;
				op_stack = 1;
				data_addr_sel = `sel_SPreg;
				reg_from_mem = 1;
				if(instr[8:7] == 0)
					wr_X = ready;
				else if(instr[8:7] == 1)
					wr_Y = ready;
				else
					wr_ACC = ready;
			end
		end
		
		`LOAD: begin
			data_addr_sel = `sel_addrimm;
			reg_from_mem = 1;
			if(instr[9] == 0)
				wr_X = ready;
			else
				wr_Y = ready;
		end
		`STORE: begin
			data_addr_sel = `sel_addrimm;
			if(instr[9] == 0)
				mem_data_wr_sel = `sel_X;
			else
				mem_data_wr_sel = `sel_Y;
			wr_to_data_mem = ready;
		end
		
		`LOADB: begin
			data_addr_sel = `sel_addr_res;
			opsel = `ALU_ADD;
			sel_srcB = `sel_imm;
			reg_from_mem = 1;
			if(instr[9] == 0) begin
				wr_X = ready;
				sel_srcA = `sel_Y;
			end else begin
				wr_Y = ready;
				sel_srcA = `sel_X;
			end
		end
		`STOREB: begin
			data_addr_sel = `sel_addr_res;
			opsel = `ALU_ADD;
			sel_srcB = `sel_imm;
			if(instr[9] == 0) begin
				mem_data_wr_sel = `sel_X;
				sel_srcA = `sel_Y;
			end else begin
				mem_data_wr_sel = `sel_Y;
				sel_srcA = `sel_X;
			end
			wr_to_data_mem = ready;
		end
		
		`MOVI: begin
			opsel = `ALU_SHORT_B;
			sel_srcB = `sel_imm;
			reg_from_mem = 0;
			if(instr[9] == 0)
				wr_X = ready;
			else
				wr_Y = ready;
		end
		`MOVR: begin
			opsel = `ALU_SHORT_B;
			reg_from_mem = 0;
			sel_srcB = instr[7:6];
			if(instr[9:8] == 2'b00) begin
				wr_X = ready;
			end else if (instr[9:8] == 2'b01) begin
				wr_Y = ready;
			end else begin
				wr_ACC = ready;
			end
		end
		
		`RAD: begin
			opsel = `ALU_RAD;
			sel_srcA = `sel_ACC;
			`WR_ALU_RES_TO_ACC_WITH_FLAGS
		end
		`POW: begin
			opsel = `ALU_POW;
			sel_srcA = `sel_ACC;
			sel_srcB = instr[9:8];
			`WR_ALU_RES_TO_ACC_WITH_FLAGS
		end
	
		`BRA: branch = 1;
		`BRE: branch = flags[`ZF];
		`BNE: branch = ~flags[`ZF];
		`BLT: branch = (flags[`NF] != flags[`OF]);
		`BGT: branch = ((flags[`ZF]==0) && (flags[`OF] == flags[`NF]));
		`BLE: branch = ((flags[`ZF]==1) || (flags[`OF] != flags[`NF]));
		`BGE: branch = (flags[`NF] == flags[`OF]);
		`BRC: branch = flags[`CF];
		`BRO: branch = flags[`OF];
		
		`JMP: begin
			push = 1;
			op_stack = 1;
			data_addr_sel = `sel_SPnext;
			mem_data_wr_sel = `sel_PC;
			wr_to_data_mem = ready;
			
			branch = 1;
		end
		`RET: begin
			push = 0;
			op_stack = 1;
			data_addr_sel = `sel_SPreg;
			ret = 1;
		end
		
		/////////// ARITHMETIC/LOGIC INSTRUNCTIONS //////////
		
		`ADDRI: begin
			opsel = `ALU_ADD;
			if(instr[9] == 0)
				sel_srcA = `sel_X;
			else
				sel_srcA = `sel_Y;
			sel_srcB = `sel_imm;
			`WR_ALU_RES_TO_ACC_WITH_FLAGS
		end
		`ADDAI: begin
			opsel = `ALU_ADD;
			sel_srcA = `sel_ACC;
			sel_srcB = `sel_imm;
			`WR_ALU_RES_TO_ACC_WITH_FLAGS
		end
		`ADDRR: begin
			opsel = `ALU_ADD;
			sel_srcA = instr[9:8];
			sel_srcB = instr[7:6];
			`WR_ALU_RES_TO_ACC_WITH_FLAGS
		end
		
		`SUBRI: begin
			opsel = 	`ALU_SUB;
			if(instr[9] == 0)
				sel_srcA = `sel_X;
			else
				sel_srcA = `sel_Y;
			sel_srcB = `sel_imm;
			`WR_ALU_RES_TO_ACC_WITH_FLAGS
		end
		`SUBAI: begin
			opsel = `ALU_SUB;
			sel_srcA = `sel_ACC;
			sel_srcB = `sel_imm;
			`WR_ALU_RES_TO_ACC_WITH_FLAGS
		end
		`SUBRR: begin
			opsel = `ALU_SUB;
			sel_srcA = instr[9:8];
			sel_srcB = instr[7:6];
			`WR_ALU_RES_TO_ACC_WITH_FLAGS
		end
		
		`SHIFT: begin // 6'b:instr  3'b:operation 2'b:op1 1'b:imm 4'b:immval/op2
			opsel = {1'b1,instr[4] | instr[1] | instr[0],instr[9:7]};
			sel_srcA = instr[6:5];
			if(instr[4]==1) begin
				//immediate shift amount
				sel_srcB = `sel_imm;
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
			if(instr[9:8] == 2'b00)
				wr_X = ready;
			else if(instr[9:8] == 2'b01)
				wr_Y = ready;
			else
				wr_ACC = ready;
			reg_from_mem = 0;
			save_flags = ready;
		end
		`DEC: begin
			opsel = `ALU_DEC;
			sel_srcA = instr[9:8];
			if(instr[9:8] == 2'b00)
				wr_X = ready;
			else if(instr[9:8] == 2'b01)
				wr_Y = ready;
			else
				wr_ACC = ready;
			reg_from_mem = 0;
			save_flags = ready;
		end
		
		`MULRR: begin
			opsel = `ALU_MUL;
			sel_srcA = instr[9:8];
			sel_srcB = instr[7:6];
			wr_X = 1;
			extra_write_X = 1;
			`WR_ALU_RES_TO_ACC_WITH_FLAGS
		end
		`MULAI: begin
			opsel = `ALU_MUL;
			sel_srcA = `sel_ACC;  sel_srcB = `sel_imm;
			wr_X = 1;
			extra_write_X = 1;
			`WR_ALU_RES_TO_ACC_WITH_FLAGS
		end
		`DIVRR: begin
			opsel = `ALU_DIV;
			sel_srcA = instr[9:8];
			sel_srcB = instr[7:6];
			wr_X = 1;
			extra_write_X = 1;
			`WR_ALU_RES_TO_ACC_WITH_FLAGS
		end
		`DIVAI: begin
			opsel = `ALU_DIV;
			sel_srcA = `sel_ACC;  sel_srcB = `sel_imm;
			wr_X = 1;
			extra_write_X = 1;
			`WR_ALU_RES_TO_ACC_WITH_FLAGS
		end
		`MODRR: begin
			opsel = `ALU_MOD;
			sel_srcA = instr[9:8];
			sel_srcB = instr[7:6];
			`WR_ALU_RES_TO_ACC_WITH_FLAGS
		end
		`MODAI: begin
			opsel = `ALU_MOD;
			sel_srcA = `sel_ACC;  sel_srcB = `sel_imm;
			`WR_ALU_RES_TO_ACC_WITH_FLAGS
		end
		
		`ANDRR: begin
			opsel = `ALU_AND;
			sel_srcA = instr[9:8];
			sel_srcB = instr[7:6];
			`WR_ALU_RES_TO_ACC_WITH_FLAGS
		end
		`ANDAI: begin
			opsel = `ALU_AND;
			sel_srcA = `sel_ACC;  sel_srcB = `sel_imm;
			`WR_ALU_RES_TO_ACC_WITH_FLAGS
		end
		`ORRR: begin
			opsel = `ALU_OR;
			sel_srcA = instr[9:8];
			sel_srcB = instr[7:6];
			`WR_ALU_RES_TO_ACC_WITH_FLAGS
		end
		`ORAI: begin
			opsel = `ALU_OR;
			sel_srcA = `sel_ACC;  sel_srcB = `sel_imm;
			`WR_ALU_RES_TO_ACC_WITH_FLAGS
		end
		`XORRR: begin
			opsel = `ALU_XOR;
			sel_srcA = instr[9:8];
			sel_srcB = instr[7:6];
			`WR_ALU_RES_TO_ACC_WITH_FLAGS
		end
		`XORAI: begin
			opsel = `ALU_XOR;
			sel_srcA = `sel_ACC;  sel_srcB = `sel_imm;
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
				sel_srcA = `sel_X;
			else
				sel_srcA = `sel_Y;
			sel_srcB = `sel_imm;
			`NO_WR_TO_ACC_WITH_FLAGS
		end
		`CMPAI: begin
			opsel = `ALU_SUB;
			sel_srcA = `sel_ACC;
			sel_srcB = `sel_imm;
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
				sel_srcA = `sel_X;
			else
				sel_srcA = `sel_Y;
			sel_srcB = `sel_imm;
			`NO_WR_TO_ACC_WITH_FLAGS
		end
		`TSTAI: begin
			opsel = `ALU_AND;
			sel_srcA = `sel_ACC;
			sel_srcB = `sel_imm;
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
