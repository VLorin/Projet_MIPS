#ifndef __TRANSLATE_H__
#define __TRANSLATE_H__ 

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_LENGTH 100

void translate(char *nom_fichier_source, char *nom_fichier_instruction);
void int_to_binary(char *instruction_binaire,int bit_debut, int bit_fin, int valeur);
#endif