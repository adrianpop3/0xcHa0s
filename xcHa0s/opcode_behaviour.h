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

instruction instructions[64] = {
    {"NOP", execute_nop},
    {"PSH", execute_psh},
    {"POP", execute_pop},
};