#include "memory.h"
#include "translate.h"

int gpr[32];
int HI;
int LO;
int PC = 0;

void print_register(){
    for(int i = 0; i<4; i++){
        for(int j = 0; j<8; j++){
            printf("gpr[%d] = %d\t",i*8+j,gpr[i*8+j]);
        }
        printf("\n");
    }
    printf("PC = %d\tHI = %08X\tLO = %08X\n",PC,HI,LO);
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

void update_gpr(){
    gpr[0] = 0;
}