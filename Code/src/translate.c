#include "translate.h"



void translate(char *nom_fichier){
    FILE *fichier_source = fopen(nom_fichier,"r");
    
    if (fichier_source == NULL){
        printf("Erreur ouverture fichier_source\n");
        exit(0);
    }
    
    char *buffer = (char *)malloc(MAX_LENGTH);
    while( !feof (fichier_source)){
        fgets (buffer, MAX_LENGTH, fichier_source);
        printf("%s",buffer);
    }
    
}