#include "scratch.h"

int reg_table[] = {1,1,1,1,1,1,1};
int reg_cnt = 7;

int scratch_alloc(){
    for(int i = 0; i < reg_cnt; i++){
        if(reg_table[i] == 1){
            reg_table[i] = 0;
            return i;
        }
    }
    printf("error: out of registers\n");
    exit(1);
    return -1;
}

void scratch_free(int r){
    if(r<0 || r>reg_cnt){
        printf("error: freeing invalid register\n");
        exit(1);
    }
    reg_table[r] = 1;
}

const char* scratch_name(int r){
    if(r<0 || r>reg_cnt){
        printf("error: getting invalid register name\n");
        exit(1);
    }
    switch(r){
        case 0: return "%rbx";
        case 1: return "%r10";
        case 2: return "%r11";
        case 3: return "%r12";
        case 4: return "%r13";
        case 5: return "%r14";
        case 6: return "%r15";
        default: {
            printf("error: register index is invalid\n");
            exit(1);
        }
    }
}