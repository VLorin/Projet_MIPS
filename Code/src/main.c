#include "translate.h"
#include <stdio.h>
#include <stdlib.h>
#include "memory.h"





int main(int argc, char *argv[]){
    translate(argv[1],argv[2]);
    print_gpr();
    return 0;
}