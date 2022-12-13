typedef struct instruction {
    char name[9];
    uint16_t (*decode_instruction) (char line[], int nr_linie);
}instruction;

char params[10][128];
int nr_params;

void analize_arguments (char line[]) {
    nr_params = 0;
    char *p;

    p = strtok(line, " ");
    p = strtok(NULL, " ");
    while(p != NULL) {
        strcpy(params[nr_params++], p);
        p = strtok(NULL, " ");

        if(nr_params == 10) {
            break;
        } 
    }
}

uint16_t execute_nop (char line[4096], int nr_line) {

    analize_arguments(line);
    if(nr_params != 0) {
        printf("Error at line %d! NOP doesn't take any parameters!\n", nr_line);
        fail_exit();
    }

    return 0x0000;
}

uint16_t execute_psh (char line[4096], int nr_line) {

    analize_arguments(line);
    if(nr_params != 1) {
        printf("Error at line %d! PSH takes 1 parameter!\n", nr_line);
        fail_exit();
    }

    if(strcmp(params[0], "X") == 0) {
        return 0b0000011000000000;
    }
    else if(strcmp(params[0], "Y") == 0) {
        return 0b0000011010000000;
    }
    else if(strcmp(params[0], "ACC") == 0) {
        return 0b0000011100000000;
    }
    else {
        printf("Error at line %d! Bad parameter %s !\n", nr_line, params[0]);
        fail_exit();
    }
    return 1;
}

uint16_t execute_pop (char line[4096], int nr_line) {

    analize_arguments(line);
    if(nr_params != 1) {
        printf("Error at line %d! POP takes 1 parameter!\n", nr_line);
        fail_exit();
    }

    if(strcmp(params[0], "X") == 0) {
        return 0b0000010000000000;
    }
    else if(strcmp(params[0], "Y") == 0) {
        return 0b0000010010000000;
    }
    else if(strcmp(params[0], "ACC") == 0) {
        return 0b0000010100000000;
    }
    else {
        printf("Error at line %d! Bad parameter %s !\n", nr_line, params[0]);
        fail_exit();
    }
    return 1;
}

uint16_t execute_mov (char line[4096], int nr_line) {

    analize_arguments(line);
    if(nr_params != 2) {
        printf("Error at line %d! MOV takes 2 parameters!\n", nr_line);
        fail_exit();
    }

    if(strcmp(params[0], "X") == 0) {
        if(strcmp(params[1], "Y") == 0)
            return 0b0001110000000000;
        else if(strcmp(params[1], "ACC") == 0)
            return 0b0001110100000000;
        else{
            int imm;
            if(sscanf(params[1], "%d", &imm) == 0){
                printf("Error at line %d! Invalid immediate or register.\n", nr_line);
                fail_exit();
            }
            if(imm < -256 || imm > 255){
                printf("Error at line %d! Immediate out of range.\n", nr_line);
                fail_exit();
            }
            return (0b0001100000000000 | (imm & 0b0000000111111111));
        }
    }
    
    if(strcmp(params[0], "Y") == 0) {
        if(strcmp(params[1], "X") == 0)
            return 0b0001111000000000;
        else if(strcmp(params[1], "ACC") == 0)
            return 0b0001111100000000;
        else{
            int imm;
            if(sscanf(params[1], "%d", &imm) == 0){
                printf("Error at line %d! Invalid immediate or register.\n", nr_line);
                fail_exit();
            }
            if(imm < -256 || imm > 255){
                printf("Error at line %d! Immediate out of range.\n", nr_line);
                fail_exit();
            }
            return (0b0001101000000000 | (imm & 0b0000000111111111));
        }
    }

    if(strcmp(params[0], "ACC") == 0) {
        if(strcmp(params[1], "X") == 0)
            return 0b0001111000000000;
        else if(strcmp(params[1], "Y") == 0)
            return 0b0001111001000000;
        else{
            int imm;
            if(sscanf(params[1], "%d", &imm) == 0){
                printf("Error at line %d! Invalid immediate or register.\n", nr_line);
                fail_exit();
            }
            if(imm < -256 || imm > 255){
                printf("Error at line %d! Immediate out of range.\n", nr_line);
                fail_exit();
            }
            return (0b0001110000000000 | (imm & 0b0000000111111111));
        }
    }

    else {
        printf("Error at line %d! Bad parameter %s !\n", nr_line, params[0]);
        fail_exit();
    }
    return 1;
}

uint16_t execute_rad (char line[4096], int nr_line) {

    analize_arguments(line);
    if(nr_params != 0) {
        printf("Error at line %d! RAD doesn't take any parameters!\n", nr_line);
        fail_exit();
    }

    return 0b0010000000000000;
}

uint16_t execute_pow (char line[4096], int nr_line) {

    analize_arguments(line);
    if(nr_params != 1) {
        printf("Error at line %d! RAD takes 1 parameter!\n", nr_line);
        fail_exit();
    }

    if(strcmp(params[0], "X") == 0){
        return 0b0010010000000000;
    }
    else if(strcmp(params[0], "Y") == 0){
        return 0b0010010100000000;
    }
    else if(strcmp(params[0], "ACC") == 0){
        return 0b0010011000000000;
    }
    else {
        printf("Error at line %d! Bad parameter %s !\n", nr_line, params[0]);
        fail_exit();
    }
    return 1;
}

uint16_t execute_add (char line[4096], int nr_line) {

    analize_arguments(line);
    if(nr_params != 2) {
        printf("Error at line %d! ADD takes 2 parameters!\n", nr_line);
        fail_exit();
    }

    if(strcmp(params[0], "X") == 0){
        if(strcmp(params[1], "X") == 0)
            return 0b1000100000000000;
        else if(strcmp(params[1], "Y") == 0)
            return 0b1000100001000000;
        else if(strcmp(params[1], "ACC") == 0)
            return 0b1000100010000000;
        else{
            int imm;
            if(sscanf(params[1], "%d", &imm) == 0){
                printf("Error at line %d! Invalid immediate.\n", nr_line);
                fail_exit();
            }
            if(imm < -256 || imm > 255){
                printf("Error at line %d! Immediate out of range.\n", nr_line);
                fail_exit();
            }
            return (0b1000000000000000 | (imm & 0b0000000111111111));
        }
    }

    if(strcmp(params[0], "Y") == 0){
        if(strcmp(params[1], "X") == 0)
            return 0b1000100100000000;
        else if(strcmp(params[1], "Y") == 0)
            return 0b1000100101000000;
        else if(strcmp(params[1], "ACC") == 0)
            return 0b1000100110000000;
        else{
            int imm;
            if(sscanf(params[1], "%d", &imm) == 0){
                printf("Error at line %d! Invalid immediate.\n", nr_line);
                fail_exit();
            }
            if(imm < -256 || imm > 255){
                printf("Error at line %d! Immediate out of range.\n", nr_line);
                fail_exit();
            }
            return (0b1000001000000000 | (imm & 0b0000000111111111));
        }
    }

    if(strcmp(params[0], "ACC") == 0){
        if(strcmp(params[1], "X") == 0)
            return 0b1000101000000000;
        else if(strcmp(params[1], "Y") == 0)
            return 0b1000101001000000;
        else if(strcmp(params[1], "ACC") == 0)
            return 0b1000101010000000;
        else{
            int imm;
            if(sscanf(params[1], "%d", &imm) == 0){
                printf("Error at line %d! Invalid immediate.\n", nr_line);
                fail_exit();
            }
            if(imm < -256 || imm > 255){
                printf("Error at line %d! Immediate out of range.\n", nr_line);
                fail_exit();
            }
            return (0b1000010000000000 | (imm & 0b0000000111111111));
        }
    }
    
    return 1;
}

uint16_t execute_sub (char line[4096], int nr_line) {

    analize_arguments(line);
    if(nr_params != 2) {
        printf("Error at line %d! SUB takes 2 parameters!\n", nr_line);
        fail_exit();
    }

    if(strcmp(params[0], "X") == 0){
        if(strcmp(params[1], "X") == 0)
            return 0b1001100000000000;
        else if(strcmp(params[1], "Y") == 0)
            return 0b1001100001000000;
        else if(strcmp(params[1], "ACC") == 0)
            return 0b1001100010000000;
        else{
            int imm;
            if(sscanf(params[1], "%d", &imm) == 0){
                printf("Error at line %d! Invalid immediate.\n", nr_line);
                fail_exit();
            }
            if(imm < -256 || imm > 255){
                printf("Error at line %d! Immediate out of range.\n", nr_line);
                fail_exit();
            }
            return (0b1001000000000000 | (imm & 0b0000000111111111));
        }
    }

    if(strcmp(params[0], "Y") == 0){
        if(strcmp(params[1], "X") == 0)
            return 0b1001100100000000;
        else if(strcmp(params[1], "Y") == 0)
            return 0b1001100101000000;
        else if(strcmp(params[1], "ACC") == 0)
            return 0b1001100110000000;
        else{
            int imm;
            if(sscanf(params[1], "%d", &imm) == 0){
                printf("Error at line %d! Invalid immediate.\n", nr_line);
                fail_exit();
            }
            if(imm < -256 || imm > 255){
                printf("Error at line %d! Immediate out of range.\n", nr_line);
                fail_exit();
            }
            return (0b1001001000000000 | (imm & 0b0000000111111111));
        }
    }

    if(strcmp(params[0], "ACC") == 0){
        if(strcmp(params[1], "X") == 0)
            return 0b1001101000000000;
        else if(strcmp(params[1], "Y") == 0)
            return 0b1001101001000000;
        else if(strcmp(params[1], "ACC") == 0)
            return 0b1001101010000000;
        else{
            int imm;
            if(sscanf(params[1], "%d", &imm) == 0){
                printf("Error at line %d! Invalid immediate.\n", nr_line);
                fail_exit();
            }
            if(imm < -256 || imm > 255){
                printf("Error at line %d! Immediate out of range.\n", nr_line);
                fail_exit();
            }
            return (0b1001010000000000 | (imm & 0b0000000111111111));
        }
    }
    
    return 1;
}

uint16_t execute_MulDivModAndOrXor (char line[4096], int nr_line) {
    int opcode;
    int data;
    char word[256];
    sscanf(line, "%s", word);

    analize_arguments(line);
    if(nr_params != 2) {
        printf("Error at line %d! %s takes 2 parameters!\n", nr_line, word);
        fail_exit();
    }

    if(strcmp(word, "MUL") == 0)
        opcode = 0b101100;
    else if(strcmp(word, "DIV") == 0)
        opcode = 0b101110;
    else if(strcmp(word, "MOD") == 0)
        opcode = 0b110000;
    else if(strcmp(word, "AND") == 0)
        opcode = 0b110010;
    else if(strcmp(word, "OR") == 0)
        opcode = 0b110100;
    else if(strcmp(word, "XOR") == 0)
        opcode = 0b110110;

    if(strcmp(params[0], "X") == 0){
        if(strcmp(params[1], "X") == 0)
            data = 0b0000000000;
        else if(strcmp(params[1], "Y") == 0)
            data = 0b0001000000;
        else if(strcmp(params[1], "ACC") == 0)
            data = 0b0010000000;
        else {
            printf("Error at line %d! Bad parameter %s !\n", nr_line, params[0]);
            fail_exit();
        }
    }

    else if(strcmp(params[0], "Y") == 0){
        if(strcmp(params[1], "X") == 0)
            data = 0b0100000000;
        else if(strcmp(params[1], "Y") == 0)
            data = 0b0101000000;
        else if(strcmp(params[1], "ACC") == 0)
            data = 0b0110000000;
        else {
            printf("Error at line %d! Bad parameter %s !\n", nr_line, params[0]);
            fail_exit();
        }
    }

    else if(strcmp(params[0], "ACC") == 0){
        if(strcmp(params[1], "X") == 0)
            data = 0b1000000000;
        else if(strcmp(params[1], "Y") == 0)
            data = 0b1001000000;
        else if(strcmp(params[1], "ACC") == 0)
            data = 0b1010000000;
        else{
            int imm;
            if(sscanf(params[1], "%d", &imm) == 0){
                printf("Error at line %d! Invalid immediate.\n", nr_line);
                fail_exit();
            }
            if(imm < -256 || imm > 255){
                printf("Error at line %d! Immediate out of range.\n", nr_line);
                fail_exit();
            }
            data = imm & 0b0111111111;
            opcode ++;
        }
    }
    else {
            printf("Error at line %d! Bad parameter %s !\n", nr_line, params[0]);
            fail_exit();
    }
    
    return ((opcode<<10) | data);
}

uint16_t execute_NotNeg (char line[4096], int nr_line) {
    int opcode;
    int data;
    char word[256];
    sscanf(line, "%s", word);

    analize_arguments(line);
    if(nr_params != 1) {
        printf("Error at line %d! %s takes 1 parameter!\n", nr_line, word);
        fail_exit();
    }

    
    if(strcmp(word, "NOT") == 0)
        opcode = 0b111000;
    else if(strcmp(word, "NEG") == 0)
        opcode = 0b111001;

    if(strcmp(params[0], "X") == 0)
            data = 0b00;
    
    else if(strcmp(params[0], "Y") == 0)
            data = 0b01;

    else if(strcmp(params[0], "ACC") == 0)
        data = 0b10;

    else {
            printf("Error at line %d! Bad parameter %s !\n", nr_line, params[0]);
            fail_exit();
    }
    
    return ((opcode<<10) | (data<<8));
}

uint16_t execute_inc(char line[4096], int nr_line) {

    analize_arguments(line);
    if (nr_params != 1) {
        printf("Error at line %d! INC takes 1 parameter!\n", nr_line);
        fail_exit();
    }

    if (strcmp(params[0], "X") == 0) {
        return 0b1010100000000000;
    } else if (strcmp(params[0], "Y") == 0) {
        return 0b1010100100000000;
    } else if (strcmp(params[0], "ACC") == 0) {
        return 0b1010101000000000;
    } else {
        printf("Error at line %d! Bad parameter %s !\n", nr_line, params[0]);
        fail_exit();
    }

    return 1;
}

uint16_t execute_dec(char line[4096], int nr_line) {

    analize_arguments(line);
    if (nr_params != 1) {
        printf("Error at line %d! DEC takes 1 parameter!\n", nr_line);
        fail_exit();
    }

    if (strcmp(params[0], "X") == 0) {
        return 0b1010110000000000;
    } else if (strcmp(params[0], "Y") == 0) {
        return 0b1010110100000000;
    } else if (strcmp(params[0], "ACC") == 0) {
        return 0b1010111000000000;
    } else {
        printf("Error at line %d! Bad parameter %s !\n", nr_line, params[0]);
        fail_exit();
    }

    return 1;
}

uint16_t execute_cmp(char line[4096], int nr_line) {

    analize_arguments(line);
    if (nr_params != 2) {
        printf("Error at line %d! CMP takes 2 parameters!\n", nr_line);
        fail_exit();
    }

    if(strcmp(params[0], "X") == 0) {
        if(strcmp(params[1], "Y") == 0)
            return 0b1111000001000000;
        else if(strcmp(params[1], "ACC") == 0)
            return 0b1111000010000000;
        else{
            int imm;
            if(sscanf(params[1], "%d", &imm) == 0){
                printf("Error at line %d! Invalid immediate or register.\n", nr_line);
                fail_exit();
            }
            if(imm < -256 || imm > 255){
                printf("Error at line %d! Immediate out of range.\n", nr_line);
                fail_exit();
            }
            return (0b1110100000000000 | (imm & 0b0000000111111111));
        }
    }

    if(strcmp(params[0], "Y") == 0) {
        if(strcmp(params[1], "X") == 0)
            return 0b1111000100000000;
        else if(strcmp(params[1], "ACC") == 0)
            return 0b1111000110000000;
        else{
            int imm;
            if(sscanf(params[1], "%d", &imm) == 0){
                printf("Error at line %d! Invalid immediate or register.\n", nr_line);
                fail_exit();
            }
            if(imm < -256 || imm > 255){
                printf("Error at line %d! Immediate out of range.\n", nr_line);
                fail_exit();
            }
            return (0b1110101000000000 | (imm & 0b0000000111111111));
        }
    }

    if(strcmp(params[0], "ACC") == 0) {
        if(strcmp(params[1], "X") == 0)
            return 0b1111001000000000;
        else if(strcmp(params[1], "Y") == 0)
            return 0b1111001001000000;
        else{
            int imm;
            if(sscanf(params[1], "%d", &imm) == 0){
                printf("Error at line %d! Invalid immediate or register.\n", nr_line);
                fail_exit();
            }
            if(imm < -256 || imm > 255){
                printf("Error at line %d! Immediate out of range.\n", nr_line);
                fail_exit();
            }
            return (0b1110110000000000 | (imm & 0b0000000111111111));
        }
    }

    else {
        printf("Error at line %d! Bad parameter %s !\n", nr_line, params[0]);
        fail_exit();
    }
    return 1;
}

uint16_t execute_tst(char line[4096], int nr_line) {

    analize_arguments(line);
    if (nr_params != 2) {
        printf("Error at line %d! TST takes 2 parameters!\n", nr_line);
        fail_exit();
    }

    if(strcmp(params[0], "X") == 0) {
        if(strcmp(params[1], "Y") == 0)
            return 0b1111110001000000;
        else if(strcmp(params[1], "ACC") == 0)
            return 0b1111110010000000;
        else{
            int imm;
            if(sscanf(params[1], "%d", &imm) == 0){
                printf("Error at line %d! Invalid immediate or register.\n", nr_line);
                fail_exit();
            }
            if(imm < -256 || imm > 255){
                printf("Error at line %d! Immediate out of range.\n", nr_line);
                fail_exit();
            }
            return (0b1111010000000000 | (imm & 0b0000000111111111));
        }
    }

    if(strcmp(params[0], "Y") == 0) {
        if(strcmp(params[1], "X") == 0)
            return 0b1111110100000000;
        else if(strcmp(params[1], "ACC") == 0)
            return 0b1111110110000000;
        else{
            int imm;
            if(sscanf(params[1], "%d", &imm) == 0){
                printf("Error at line %d! Invalid immediate or register.\n", nr_line);
                fail_exit();
            }
            if(imm < -256 || imm > 255){
                printf("Error at line %d! Immediate out of range.\n", nr_line);
                fail_exit();
            }
            return (0b1111011000000000 | (imm & 0b0000000111111111));
        }
    }

    if(strcmp(params[0], "ACC") == 0) {
        if(strcmp(params[1], "X") == 0)
            return 0b1111111000000000;
        else if(strcmp(params[1], "Y") == 0)
            return 0b1111111001000000;
        else{
            int imm;
            if(sscanf(params[1], "%d", &imm) == 0){
                printf("Error at line %d! Invalid immediate or register.\n", nr_line);
                fail_exit();
            }
            if(imm < -256 || imm > 255){
                printf("Error at line %d! Immediate out of range.\n", nr_line);
                fail_exit();
            }
            return (0b1111100000000000 | (imm & 0b0000000111111111));
        }
    }

    else {
        printf("Error at line %d! Bad parameter %s !\n", nr_line, params[0]);
        fail_exit();
    }
    return 1;
}

instruction instructions[64] = {
    {"NOP", execute_nop},
    {"PSH", execute_psh},
    {"POP", execute_pop},
    {"MOV", execute_mov},
    {"RAD", execute_rad},
    {"POW", execute_pow},
    {"ADD", execute_add},
    {"SUB", execute_sub},
    {"MUL", execute_MulDivModAndOrXor},
    {"DIV", execute_MulDivModAndOrXor},
    {"MOD", execute_MulDivModAndOrXor},
    {"AND", execute_MulDivModAndOrXor},
    {"OR", execute_MulDivModAndOrXor},
    {"XOR", execute_MulDivModAndOrXor},
    {"NOT", execute_NotNeg},
    {"NEG", execute_NotNeg},
    {"INC", execute_inc},
    {"DEC", execute_dec},
    {"CMP", execute_cmp},
    {"TST", execute_tst},
};