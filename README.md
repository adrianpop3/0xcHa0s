# Pocket Calculator w/ GPP - Team: 0xcHa0s - FIC PROIECT 2022      

## HW Design:
![Captură de ecran din 2023-01-19 la 22 41 28](https://user-images.githubusercontent.com/33669868/213580387-d91c486d-c5ce-4990-abe1-efb3ca0bb965.png)

## Members:
* Ploscaru Carla
* Podean Roxana-Andreea
* Pop Adrian
* Pop Alexandru
* Plăvăț Vlad
* Pop Tudor-Antoniu
![0xcHa0s - Chart](https://user-images.githubusercontent.com/33669868/196945744-92fc6371-6e7e-41b3-879b-69a125951664.png)

## References:
### Project topic related:
* https://www.sciencedirect.com/topics/computer-science/general-purpose-processor
* https://en.wikibooks.org/wiki/Embedded_Control_Systems_Design/Processors
* https://www.fpga4student.com/2017/04/verilog-code-for-16-bit-risc-processor.html
* https://github.com/vprabhu28/16-Bit-CPU-using-Verilog
* https://www.european-processor-initiative.eu/general-purpose-processor/
* https://www.quora.com/What-is-a-difference-between-general-purpose-processor-and-single-purpose-processor
* https://en.wikipedia.org/wiki/History_of_general-purpose_CPUs

### Other useful links:
* https://docs.github.com/en/get-started/writing-on-github/working-with-advanced-formatting/organizing-information-with-tables
* https://docs.github.com/en/get-started/writing-on-github/getting-started-with-writing-and-formatting-on-github/basic-writing-and-formatting-syntax

## Milestones:
Sesiunea 3 - S6 (2p):
- [X] Alegerea temei de proiect / set de instructiuni
- [X] Specificarea echipei
- [X] Impartirea rolurilor in echipa
- [X] Nume echipa
- [X] Bibliografie

Sesiunea 6 - S12 (maxim nota 7):
- [X] Design Hardware & Documentatie GP (2p)
- [X] Implementare General Purpose Processor (2p)
- [X] Testare General Purpose Processor (1p)

Sesiunea 7 - S14 (maxim nota 10):
- [X] Design & Implementare GP processor + ASIP; (1p)
- [X] Testare ASIP (1p)
- [X] Prezentarea finala a proiectului - prezentare, documentatie (1p)

## Important general aspects:
Registers:
* 16-bit Accumulator;
* 2 16-bit general purpose (GP) registers: X and Y;
* 4-bit Flag register: Zero, Negative, Carry, Overflow
* 16-bit stack pointer
* Program Counter

Instruction size: 16-bit (6-bit opcode & 1-bit Register address & 9-bit Immediate size)</br>Word size: 16-bit</br>Stack grows inverse in memory.
</br>CALL & JMP push PC on stack while RET pops PC from stack.</br>All procedure parameters and return values are passed using stack.</br>Only arithmetic and logic instructions should update the Flag register!

## Minimum required CPU Components:
* 2 general purpose registers: X, Y, and one accumulator A
* ALU
* Control Unit
* Instruction and Data memory (includes Stack)
* Sign Extend unit
* Processor registers: PC, SP, Flag

## Core instruction set:

### Memory instructions: 
LOAD, STORE into registers X or Y

### Branch instructions:
* BRZ = branch if zero
* BRN = branch if negative
* BRC = branch if carry
* BRO = branch if overflow
* BRA = branch always (unconditional branch)
* JMP = call procedure
* RET = return from procedure

### Arithmetic and Logic Instructions:
ADD, SUB, LSR, LSL, RSR, RSL, MOV, MUL, DIV, MOD</br>AND, OR, XOR, NOT, CMP, TST, INC, DEC

|Instr. Type|Opcode|Register Adress|Immediate|
|-----------|------|---------------|---------|
|Memory|6 bit|1 bit|9 bit|
|Branch|6 bit|10 bit|-|
|ALU|6 bit|1 bit|9 bit|
