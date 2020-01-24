#include "translate.h"
#include <stdio.h>
#include <stdlib.h>
#include "memory.h"
#include "execution.h"





int main(int argc, char *argv[]){
    translate(argv[1],argv[2]);
    execution(argv[1]);
    printf("\nFin de l'execution\nEtat de la mémoire : \n");
    print_memory();
    return 0;
}