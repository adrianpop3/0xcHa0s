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
            return 0b0001110001000000;
        else if(strcmp(params[1], "ACC") == 0)
            return 0b0001110010000000;
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
            return 0b0001110100000000;
        else if(strcmp(params[1], "ACC") == 0)
            return 0b0001110110000000;
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
            printf("Error at line %d! Bad parameter %s !\n", nr_line, params[0]);
            fail_exit();
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

uint16_t execute_load(char line[4096], int nr_line) {
    analize_arguments(line);
    if (nr_params != 2) {
        printf("Error at line %d! LOAD takes 2 parameters!\n", nr_line);
        fail_exit();
    }

    if(strcmp(params[0], "X") == 0) {
        int adr_target=-1;
        for(int i=0; i<nr_variables; i++){
            if(strcmp(params[1],variables[i].name) == 0){
                adr_target = variables[i].address;
                return 0b0000100000000000 | adr_target;
            }
        }
        printf("Error at line %d! Undeclared variable '%s'.\n", nr_line,params[1]);
        fail_exit();
        return 1;
    }

    if(strcmp(params[0], "Y") == 0) {
        int adr_target=-1;
        for(int i=0; i<nr_variables; i++){
            if(strcmp(params[1],variables[i].name) == 0){
                adr_target = variables[i].address;
                return 0b0000101000000000 | adr_target;
            }
        }
        printf("Error at line %d! Undeclared variable '%s'.\n", nr_line,params[1]);
        fail_exit();
        return 1;
    }
    return 1;
}


uint16_t execute_store(char line[4096], int nr_line) {
    analize_arguments(line);
    if (nr_params != 2) {
        printf("Error at line %d! STORE takes 2 parameters!\n", nr_line);
        fail_exit();
    }

    if(strcmp(params[0], "X") == 0) {
        int adr_target=-1;
        for(int i=0; i<nr_variables; i++){
            if(strcmp(params[1],variables[i].name) == 0){
                adr_target = variables[i].address;
                return 0b0000110000000000 | adr_target;
            }
        }
        printf("Error %d at line %d! Undeclared variable '%s'.\n",nr_variables, nr_line,params[1]);
        fail_exit();
        return 1;
    }

    if(strcmp(params[0], "Y") == 0) {
        int adr_target=-1;
        for(int i=0; i<nr_variables; i++){
            if(strcmp(params[1],variables[i].name) == 0){
                adr_target = variables[i].address;
                return 0b0000111000000000 | adr_target;
            }
        }
        printf("Error at line %d! Undeclared variable '%s'.\n", nr_line,params[1]);
        fail_exit();
        return 1;
    }
    return 1;
}


uint16_t execute_loadb(char line[4096], int nr_line) {
    analize_arguments(line);
    if (nr_params != 2) {
        printf("Error at line %d! LOADB takes 2 parameters!\n", nr_line);
        fail_exit();
    }

    if(strcmp(params[0], "X") == 0) {
        int adr_target=-1;
        for(int i=0; i<nr_variables; i++){
            if(strcmp(params[1],variables[i].name) == 0){
                adr_target = variables[i].address;
                return 0b0001000000000000 | adr_target;
            }
        }
        printf("Error at line %d! Undeclared variable '%s'.\n", nr_line,params[1]);
        fail_exit();
        return 1;
    }

    if(strcmp(params[0], "Y") == 0) {
        int adr_target=-1;
        for(int i=0; i<nr_variables; i++){
            if(strcmp(params[1],variables[i].name) == 0){
                adr_target = variables[i].address;
                return 0b0001001000000000 | adr_target;
            }
        }
        printf("Error at line %d! Undeclared variable '%s'.\n", nr_line,params[1]);
        fail_exit();
        return 1;
    }
    return 1;
}


uint16_t execute_storeb(char line[4096], int nr_line) {
    analize_arguments(line);
    if (nr_params != 2) {
        printf("Error at line %d! STOREB takes 2 parameters!\n", nr_line);
        fail_exit();
    }

    if(strcmp(params[0], "X") == 0) {
        int adr_target=-1;
        for(int i=0; i<nr_variables; i++){
            if(strcmp(params[1],variables[i].name) == 0){
                adr_target = variables[i].address;
                return 0b0001010000000000 | adr_target;
            }
        }
        printf("Error at line %d! Undeclared variable '%s'.\n", nr_line,params[1]);
        fail_exit();
        return 1;
    }

    if(strcmp(params[0], "Y") == 0) {
        int adr_target=-1;
        for(int i=0; i<nr_variables; i++){
            if(strcmp(params[1],variables[i].name) == 0){
                adr_target = variables[i].address;
                return 0b0001011000000000 | adr_target;
            }
        }
        printf("Error at line %d! Undeclared variable '%s'.\n", nr_line,params[1]);
        fail_exit();
        return 1;
    }
    return 1;
}


uint16_t execute_shift(char line[4096], int nr_line) {
    int oper = 0;
    int cine = 0;
    int iq   = 0;
    char word[256];
    sscanf(line, "%s", word);

    analize_arguments(line);
    if(nr_params != 2) {
        printf("Error at line %d! %s takes 2 parameters!\n", nr_line, word);
        fail_exit();
    }
    
    if(word[0]=='L') oper |= 0b001;
    if(word[2]=='L') oper |= 0b000;
    if(word[2]=='A') oper |= 0b010;
    if(word[2]=='R') oper |= 0b100;
    if(word[2]=='C') oper |= 0b110;

    if(strcmp(params[0], "X") == 0){
        cine = 0b00;
    }else if(strcmp(params[0], "Y") == 0){
        cine = 0b01;
    }else if(strcmp(params[0], "ACC") == 0){
        cine = 0b10;
    }else {
        printf("Error at line %d! Bad parameter %s !\n", nr_line, params[0]);
        fail_exit();
    }
    
    //I QQQQ = 1 QQQQ = 0 AAMX
    if(strcmp(params[1], "X") == 0){
        iq = 0b00000;
        if(strchr(word,'M')) iq |= 0b00010;
    }else if(strcmp(params[1], "Y") == 0){
        iq = 0b00100;
        if(strchr(word,'M')) iq |= 0b00010;
    }else if(strcmp(params[1], "ACC") == 0){
        iq = 0b01000;
        if(strchr(word,'M')) iq |= 0b00010;
    }else {
        int imm;
        if(sscanf(params[1], "%d", &imm) == 0){
            printf("Error at line %d! Invalid immediate or register.\n", nr_line);
            fail_exit();
        }
        if(imm < 1 || imm > 15){
            printf("Error at line %d! Immediate out of range.\n", nr_line);
            fail_exit();
        }
        iq = 0b10000 | (imm & 0b1111);
    }
    return ((0b101000<<10) | (oper<<7) | (cine<<5) | iq);
}

uint16_t execute_branch (char line[4096], int nr_line) {
    int opcode;
    int data;
    char word[256];
    sscanf(line, "%s", word);

    analize_arguments(line);
    if( ((strcmp(word, "RET") == 0) && nr_params != 0) || ((strcmp(word, "RET") != 0) && nr_params != 1) ) {
        printf("Error at line %d! %s takes %d parameter(s)!\n", nr_line, word,(strcmp(word, "RET") == 0)?0:1);
        fail_exit();
    }

    if(strcmp(word, "BRA") == 0)        opcode = 0b010000;
    else if(strcmp(word, "BRE") == 0)   opcode = 0b010001;
    else if(strcmp(word, "BRZ") == 0)   opcode = 0b010001;
    else if(strcmp(word, "BNE") == 0)   opcode = 0b010010;
    else if(strcmp(word, "BRN") == 0)   opcode = 0b010011;
    else if(strcmp(word, "BLT") == 0)   opcode = 0b010011;
    else if(strcmp(word, "BRP") == 0)   opcode = 0b010100;
    else if(strcmp(word, "BGT") == 0)   opcode = 0b010100;
    
    else if(strcmp(word, "BLE") == 0)   opcode = 0b010101;
    else if(strcmp(word, "BGE") == 0)   opcode = 0b010110;
    else if(strcmp(word, "BRC") == 0)   opcode = 0b010111;
    else if(strcmp(word, "BRO") == 0)   opcode = 0b011000;
    
    else if(strcmp(word, "JMP") == 0)   opcode = 0b011110;
    else if(strcmp(word, "RET") == 0){
		opcode = 0b011111;
		return (opcode<<10);
	}
    
    int adr_target=-1;
    for(int i=0; i<nr_labels; i++){
        if(strcmp(params[0],labels[i].name) == 0){
            adr_target = labels[i].address;
            return ((opcode<<10) | adr_target);
        }
    }
    printf("Error at line %d! Undeclared label '%s'.\n", nr_line,params[0]);
    fail_exit();
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
    {"LOAD", execute_load},
    {"STORE", execute_store},
    {"LOADB", execute_loadb},
    {"STOREB", execute_storeb},
    {"STOREB", execute_storeb},
    
    {"RSLM", execute_shift},
    {"LSLM", execute_shift},
    {"RSAM", execute_shift},
    {"LSAM", execute_shift},
    {"RSRM", execute_shift},
    {"LSRM", execute_shift},
    {"RSCM", execute_shift},
    {"LSCM", execute_shift},
    
    {"RSL", execute_shift},
    {"LSL", execute_shift},
    {"RSA", execute_shift},
    {"LSA", execute_shift},
    {"RSR", execute_shift},
    {"LSR", execute_shift},
    {"RSC", execute_shift},
    {"LSC", execute_shift},
    
    {"BRA", execute_branch},
    {"BRE", execute_branch},
    {"BRZ", execute_branch},
    {"BNE", execute_branch},
    {"BRN", execute_branch},
    {"BLT", execute_branch},
    {"BRP", execute_branch},
    {"BGT", execute_branch},
    {"BLE", execute_branch},
    {"BGE", execute_branch},
    {"BRC", execute_branch},
    {"BRO", execute_branch},
    
    {"JMP", execute_branch},
    {"RET", execute_branch},
};
