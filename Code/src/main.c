#include "translate.h"
#include <stdio.h>
#include <stdlib.h>
#include "memory.h"
#include "execution.h"





int main(int argc, char *argv[]){
    translate(argv[1],argv[2]);
    execution(argv[1]);
    printf("\nEtat final des registres :\n");
    print_register();
    print_memory();
    //printf("%d\n",9 | 2);
    return 0;
}