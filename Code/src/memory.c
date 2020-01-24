#include "memory.h"
#include "translate.h"

int gpr[32];
int HI;
int LO;
int PC = 0;

int memory[64];
void print_register(){
    for(int i = 0; i<4; i++){
        for(int j = 0; j<8; j++){
            printf("$%d = \t%d\t",i*8+j,gpr[i*8+j]);
        }
        printf("\n");
    }
    printf("PC = %d\t HI = %08X\t LO = %08X\n",PC,HI,LO);
}

void print_memory(){
    for(int i=0; i<8; i++){
        for(int j=0; j <8 ; j++){
            printf("memory[%d] = %08X\t", i*8+j, memory[i*8+j]);
        }
        printf("\n");
    }
}

int *adresse_gpr(){
    return &gpr[0];
}

int *adresse_HI(){
    return &HI;
}

int *adresse_LO(){
    return &LO;
}

int *adresse_PC(){
    return &PC;
}

int *adresse_memory(){
    return &memory[0];
}

void update_gpr(){
    gpr[0] = 0;
}