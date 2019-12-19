#ifndef __MEMORY_H__
#define __MEMORY_H__ 

#include <stdio.h>
#include <stdlib.h>


void print_register();
int *adresse_gpr();
int *adresse_HI();
int *adresse_LO();
int *adresse_PC();
int *adresse_memory();

void update_gpr();


#endif