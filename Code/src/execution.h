#ifndef __EXECUTION_H__
#define __EXECUTION_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100


void execution(char *nom_fichier_source);
int nombre_instruction(char *nom_fichier_source);
char **copy_instruction_in_array(char *nom_fichier_source, int nb_instruction);
#endif