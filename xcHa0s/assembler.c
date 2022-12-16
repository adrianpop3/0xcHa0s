#include<stdlib.h>
#include<stdio.h>
#include<stdint.h>
#include<string.h>
#include<ctype.h>

uint16_t result[1024];
int nr_op = 0;

typedef struct{
	char name[256];
	int address;
}variable;
variable variables [512];
int nr_variables,cr_data_addr = 0;

typedef struct{
    char name[256];
    int address;
}label;
label labels [1024];
int nr_labels;

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

int main(int argc, char *argv[])
{
    char line[4096];
    int nr_lines=0; 

    if(argc < 2){
        read_file = fopen("main.asm", "rt");
    }else{
        read_file = fopen(argv[1], "rt");
    }
    if(read_file == NULL) {
        printf("Eroare la deschiderea fisierului!");
        return 1;
    }

    write_file = fopen("main.bin", "wt");
    if(write_file == NULL) {
        printf("Eroare la deschiderea fisierului!");
    }

    while(fgets(line, 4096, read_file)) {
        nr_lines++;
        char *s = line;
        while (*s) {*s = toupper((unsigned char) *s);    s++;}
        while(isspace(*line) && *line){
            s=line;
            while(*s){*s=*(s+1);s++;}
        }
        
        
        if(line[0] < 'A' || line[0] > 'Z') {
            continue;
        }
        line[strcspn(line,"\n")] = '\0';

        char word[256];
        sscanf(line, "%s", word);

        int found_instr = 0; 
		
		if(strchr(word,' ')==NULL && strchr(word,'\t')==NULL && strchr(word,'\r')==NULL){
		    //no spaces
		    if(word[strlen(word)-1] == ':'){
		        //LABEL:
		        word[strlen(word)-1]='\0';
    		    for(int i=0; i<nr_labels; i++){
    			    if(strcmp(labels[i].name,word)==0){
                        printf("Error at line %d! Label already declared.\n", nr_lines);
                        fail_exit();
    			    }
    			}
		        strcpy(labels[nr_labels].name,word);
		        labels[nr_labels].address = nr_op;
		        nr_labels++;
		        continue;
		    }
		    
		}
		
		if(strcmp(word, "DATA") == 0){
			analize_arguments(line);
			for(int i=0; i<nr_variables; i++){
			    if(strcmp(variables[i].name,params[0])==0){
                    printf("Error at line %d! Variable already declared.\n", nr_lines);
                    fail_exit();
			    }
			}
			
			variables[nr_variables].address = cr_data_addr;
			strcpy(variables[nr_variables].name,params[0]);
			nr_variables++;
			if(nr_params == 1){
			    cr_data_addr++;
			}else if(nr_params == 2){
			    int imm;
                if(sscanf(params[1], "%d", &imm) == 0 || imm < 1){
                    printf("Error at line %d! Invalid vector size value.\n", nr_lines);
                    fail_exit();
                }
                cr_data_addr += imm;
			}else{
			    printf("Error. Too many parameters for data declaration.\n");
                fail_exit();
			}
			if(cr_data_addr > 512){
                printf("Error. Too many variables.\n");
                fail_exit();
			}
			continue;
		}
		
        for(int i=0; ;i++) {
            if(instructions[i].decode_instruction == NULL) {
                break;
            }
			
            if(strcmp(instructions[i].name, word) == 0) {
                found_instr = 1;
                uint16_t opcode = instructions[i].decode_instruction(line, nr_lines);
                if(nr_op >= 1024){
                    printf("Error! The code doesn't fit in ROM.\n");
                    fail_exit();
                }
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
    
    
	FILE *mapfile = fopen("mem_map.txt","wt");
	if(mapfile != NULL){
    	for(i=0;i<nr_variables;i++){
    		fprintf(mapfile,"%15s @ %d\n",variables[i].name,variables[i].address);
    	}
    	fprintf(mapfile,"\n");
    	for(i=0;i<nr_labels;i++){
    		fprintf(mapfile,"%15s & %d\n",labels[i].name,labels[i].address);
    	}
	}

    fclose(read_file);
    fclose(write_file);
    return 0;
}