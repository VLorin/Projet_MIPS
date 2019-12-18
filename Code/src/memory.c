#include "memory.h"
#include "translate.h"

int gpr[32];
int HI;
int LO;

void print_gpr(){
    for(int i = 0; i<4; i++){
        for(int j = 0; j<8; j++){
            printf("gpr[%d] = %d\t",i*8+j,gpr[i*8+j]);
        }
        printf("\n");
    }
}