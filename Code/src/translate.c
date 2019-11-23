#include "translate.h"



void translate(char *nom_fichier){
    FILE *fichier_source = fopen(nom_fichier,"r");
    
    if (fichier_source == NULL){
        printf("Erreur ouverture fichier_source\n");
        exit(0);
    }
    
    char *buffer = (char *)malloc(MAX_LENGTH);
    char instruction[10];
    int var1, var2, var3, nombre_operande;
    while( !feof (fichier_source)){
        fgets (buffer, MAX_LENGTH, fichier_source);
        printf("%s",buffer);
        sscanf(buffer, "%s ", instruction);
        
        if( strcmp( instruction, "ADDI") == 0){ // Add Immediate Word
            nombre_operande = 3;
            sscanf(buffer, "%s $%d,$%d,%d", instruction, &var1, &var2, &var3);
        }
        else if( strcmp( instruction, "ADD") == 0){
            nombre_operande = 3;
            sscanf(buffer, "%s $%d,$%d,$%d", instruction, &var1, &var2, &var3);
        }
        else if( strcmp( instruction, "AND") == 0){
            nombre_operande = 3;
            sscanf(buffer, "%s $%d,$%d,$%d", instruction, &var1, &var2, &var3);
        }
        else if( strcmp( instruction, "BEQ") == 0){ // Branch on Equal
            nombre_operande = 3;
            sscanf(buffer, "%s $%d,$%d,%d", instruction, &var1, &var2, &var3);
        }
        else if( strcmp( instruction, "BGTZ") == 0){ // Branch on Greater Than Zero
            nombre_operande = 2;
            sscanf(buffer, "%s $%d,%d", instruction, &var1, &var2);
        }
        else if( strcmp( instruction, "BLEZ") == 0){ // Branch on Less Than or Equal to Zero
            nombre_operande = 2;
            sscanf(buffer, "%s $%d,%d", instruction, &var1, &var2);
        }
        else if( strcmp( instruction, "BNE") == 0){ // Branch on Not Equal
            nombre_operande = 3;
            sscanf(buffer, "%s $%d,$%d,%d", instruction, &var1, &var2, &var3);
        }
        else if( strcmp( instruction, "DIV") == 0){ // Divide Word
            nombre_operande = 2;
            sscanf(buffer, "%s $%d,$%d", instruction, &var1, &var2);
        }
        else if( strcmp( instruction, "JR") == 0){
            nombre_operande = 1;
            sscanf(buffer, "%s $%d", instruction, &var1);
        }
        else if( strcmp( instruction, "JAL") == 0){
            nombre_operande = 1;
            sscanf(buffer, "%s %d", instruction, &var1);
        }
        else if( strcmp( instruction, "J") == 0){
            nombre_operande = 1;
            sscanf(buffer, "%s %d", instruction, &var1);
        }
        else if( strcmp( instruction, "LUI") == 0){ // Load Upper Immediate
            nombre_operande = 2;
            sscanf(buffer, "%s $%d,%d", instruction, &var1, &var2);
        }
        else if( strcmp( instruction, "LW") == 0){ // Load Word
            nombre_operande = 2;
            sscanf(buffer, "%s $%d,%d", instruction, &var1, &var2);
        }
        else if( strcmp( instruction, "MFHI") == 0){ // Move From HI Register
            nombre_operande = 1;
            sscanf(buffer, "%s $%d", instruction, &var1);
        }
        else if( strcmp( instruction, "MFLO") == 0){ // Move From LO Register
            nombre_operande = 1;
            sscanf(buffer, "%s $%d", instruction, &var1);
        }
        else if( strcmp( instruction, "ROTR") == 0){
            nombre_operande = 3;
            sscanf(buffer, "%s $%d,$%d,$%d", instruction, &var1, &var2, &var3);
        }
        else if( strcmp( instruction, "SLL") == 0){
            nombre_operande = 3;
            sscanf(buffer, "%s $%d,$%d,%d", instruction, &var1, &var2, &var3);
        }
        else if( strcmp( instruction, "MULT") == 0){ // Multiply Word
            nombre_operande = 2;
            sscanf(buffer, "%s $%d,$%d", instruction, &var1, &var2);
        }
        else if( strcmp( instruction, "NOP") == 0){ // No Operation
            nombre_operande = 0;
            sscanf(buffer, "%s ", instruction);
        }
        else if( strcmp( instruction, "OR") == 0){
            nombre_operande = 3;
            sscanf(buffer, "%s $%d,$%d,$%d", instruction, &var1, &var2, &var3);
        
        else if( strcmp( instruction, "SLT") == 0){
            nombre_operande = 3;
            sscanf(buffer, "%s $%d,$%d,$%d", instruction, &var1, &var2, &var3);
        }
        else if( strcmp( instruction, "SRL") == 0){
            nombre_operande = 3;
            sscanf(buffer, "%s $%d,$%d,%d", instruction, &var1, &var2, &var3);
        }
        else if( strcmp( instruction, "SUB") == 0){
            nombre_operande = 3;
            sscanf(buffer, "%s $%d,$%d,$%d", instruction, &var1, &var2, &var3);
        }
        else if( strcmp( instruction, "SW") == 0){
            nombre_operande = 2;
            sscanf(buffer, "%s $%d,%d", instruction, &var1, &var2);
        }
        else if( strcmp( instruction, "XOR") == 0){
            nombre_operande = 3;
            sscanf(buffer, "%s $%d,$%d,$%d", instruction, &var1, &var2, &var3);
        }
        else if( strcmp( instruction, "SYSCALL") == 0){
            nombre_operande = 0;
            sscanf(buffer, "%s", instruction);
        }
        
        printf("instruction = %s, var1 = %d, var2 = %d, var3 = %d \n", instruction, var1, var2, var3);
    }
    
}

