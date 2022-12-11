#include<stdlib.h>
#include<stdio.h>
#include<stdint.h>
#include<string.h>

uint16_t result[1024];
int nr_op = 0;

FILE *read_file, *write_file;

void fail_exit() {
    fclose(read_file);
    fclose(write_file);
    remove("main.bin");
    exit(1);
}

#include"opcode_behaviour.h"

void print_binary(uint16_t bin) {
    for(int i=15; i>=0; i--) {
        fprintf(write_file, "%d", (bin >> i) & 1);
    }
    fprintf(write_file, "\n");
}

int main()
{
    char line[4096];
    int nr_lines=0; 

    read_file = fopen("main.asm", "rt");
    if(read_file == NULL) {
        printf("Eroare la deschiderea fisierului!");
    }

    write_file = fopen("main.bin", "wt");
    if(write_file == NULL) {
        printf("Eroare la deschiderea fisierului!");
    }

    while(fgets(line, 4096, read_file)) {
        if(line[0] < 'A' || line[0] > 'Z') {
            continue;
        }
        line[strcspn(line,"\n")] = '\0';

        nr_lines++; 
        char word[256];
        sscanf(line, "%s", word);

        int found_instr = 0; 
        for(int i=0; ;i++) {
            if(instructions[i].decode_instruction == NULL) {
                break;
            }

            if(strcmp(instructions[i].name, word) == 0) {
                found_instr = 1;
                uint16_t opcode = instructions[i].decode_instruction(line, nr_lines);
                result[nr_op++] = opcode;
                break;
            }
        }

        if(!found_instr) {
            printf("Error at line: %d. Instruction '%s' not recognized.\n", nr_lines, word);
            fail_exit();
        }
    }

    int i;
    for(i=0; i<1024; i++) {
        print_binary(result[i]);
    }

    fclose(read_file);
    fclose(write_file);
    return 0;
}