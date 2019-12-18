#include "execution.h"
#include "memory.h"


void execution(char *nom_fichier_source){
   
    char *buffer = (char *)malloc(MAX_LENGTH);
    char instruction[10];
    int var1, var2, var3;
    int nb_instruction = nombre_instruction(nom_fichier_source);
    char **tableau_instruction = copy_instruction_in_array(nom_fichier_source, nb_instruction);
    for(int j = 0; j<nb_instruction;j++){
        printf("%s\n",tableau_instruction[j]);
    }
    int *gpr = adresse_gpr();
    int *HI = adresse_HI();
    int *LO = adresse_LO();
    int *PC = adresse_PC();
    if(gpr == NULL){
        printf("ERREUR INIT POINTEUR GPR");
    }
    while((*PC) <= (4*nb_instruction) ){
        //print_register();
        strcpy(buffer,tableau_instruction[(*PC)/4]);
        printf("buffer %d = %s\n",*PC/4,buffer);
        printf("instruction %d = %s\n",*PC/4,tableau_instruction[*PC/4]);
        printf("PC = %d\n",*PC/4);
        sscanf(buffer, "%s ", instruction);
        
        
        if( strcmp( instruction, "ADDI") == 0){ // Add Immediate Word
            sscanf(buffer, "%s $%d,$%d,%d", instruction, &var1, &var2, &var3);
            //printf("PC = %d,inst3 = %s\n",*PC,instruction);
            gpr[var1] = gpr[var2] + var3 ;
        }
        else if( strcmp( instruction, "ADD") == 0){
            
            sscanf(tableau_instruction[(*PC)/4], "%s $%d,$%d,$%d", instruction, &var1, &var2, &var3);
            gpr[var1] = gpr[var3] + gpr[var2];  
        }
        else if( strcmp( instruction, "AND") == 0){
            sscanf(tableau_instruction[(*PC)/4], "%s $%d,$%d,$%d", instruction, &var1, &var2, &var3);
            gpr[var1] = gpr[var2] & gpr[var3];
            
        }
        else if( strcmp( instruction, "BEQ") == 0){ // Branch on Equal
            
            sscanf(tableau_instruction[(*PC)/4], "%s $%d,$%d,%d", instruction, &var1, &var2, &var3);
            if(gpr[var1] == gpr[var2]){
                PC += var3;
            }
        }
        else if( strcmp( instruction, "BGTZ") == 0){ // Branch on Greater Than Zero
            
            sscanf(tableau_instruction[(*PC)/4], "%s $%d,%d", instruction, &var1, &var2);
            if(gpr[var1] > 0){
                *PC += var2;
            }
        }
        else if( strcmp( instruction, "BLEZ") == 0){ // Branch on Less Than or Equal to Zero
            
            sscanf(tableau_instruction[(*PC)/4], "%s $%d,%d", instruction, &var1, &var2);
             if(gpr[var1] <= 0){
                *PC += var2;
            }
        }
        else if( strcmp( instruction, "BNE") == 0){ // Branch on Not Equal
            
            sscanf(tableau_instruction[(*PC)/4], "%s $%d,$%d,%d", instruction, &var1, &var2, &var3);
            if(gpr[var1] != gpr[var2]){
                *PC += var3;
            }
        }
        else if( strcmp( instruction, "DIV") == 0){ // Divide Word
            
            sscanf(tableau_instruction[(*PC)/4], "%s $%d,$%d", instruction, &var1, &var2);
            *LO = gpr[var1] / gpr[var2];
            *HI = gpr[var1] % gpr[var2];
        }
        else if( strcmp( instruction, "JR") == 0){
            
            sscanf(tableau_instruction[(*PC)/4], "%s $%d", instruction, &var1);
           
        }
        else if( strcmp( instruction, "JAL") == 0){
            
            sscanf(tableau_instruction[(*PC)/4], "%s %d", instruction, &var1);
        }
        else if( strcmp( instruction, "J") == 0){
            
            sscanf(tableau_instruction[(*PC)/4], "%s %d", instruction, &var1);
           
        }
        else if( strcmp( instruction, "LUI") == 0){ // Load Upper Immediate
            
            sscanf(tableau_instruction[(*PC)/4], "%s $%d,%d", instruction, &var1, &var2);
        }
        else if( strcmp( instruction, "LW") == 0){ // Load Word
            
            sscanf(tableau_instruction[(*PC)/4], "%s $%d,%d(%d)", instruction, &var1, &var2, &var3);
        }
        else if( strcmp( instruction, "MFHI") == 0){ // Move From HI Register
            
            sscanf(tableau_instruction[(*PC)/4], "%s $%d", instruction, &var1);
        }
        else if( strcmp( instruction, "MFLO") == 0){ // Move From LO Register
            
            sscanf(tableau_instruction[(*PC)/4], "%s $%d", instruction, &var1);
        }
        else if( strcmp( instruction, "ROTR") == 0){
            
            sscanf(tableau_instruction[(*PC)/4], "%s $%d,$%d,$%d", instruction, &var1, &var2, &var3);
        }
        else if( strcmp( instruction, "SLL") == 0){
            
            sscanf(tableau_instruction[(*PC)/4], "%s $%d,$%d,%d", instruction, &var1, &var2, &var3);
           
        }
        else if( strcmp( instruction, "MULT") == 0){ // Multiply Word
            
            sscanf(tableau_instruction[(*PC)/4], "%s $%d,$%d", instruction, &var1, &var2);
           
        }
        else if( strcmp( instruction, "NOP") == 0){ // No Operation
            
            sscanf(tableau_instruction[(*PC)/4], "%s ", instruction);
        }
        else if( strcmp( instruction, "OR") == 0){
            
            sscanf(tableau_instruction[(*PC)/4], "%s $%d,$%d,$%d", instruction, &var1, &var2, &var3);
        }
        else if( strcmp( instruction, "SLT") == 0){
            
            sscanf(tableau_instruction[(*PC)/4], "%s $%d,$%d,$%d", instruction, &var1, &var2, &var3);
        }
        else if( strcmp( instruction, "SRL") == 0){
            
            sscanf(tableau_instruction[(*PC)/4], "%s $%d,$%d,%d", instruction, &var1, &var2, &var3);
        }
        else if( strcmp( instruction, "SUB") == 0){
            
            sscanf(tableau_instruction[(*PC)/4], "%s $%d,$%d,$%d", instruction, &var1, &var2, &var3);
        }
        else if( strcmp( instruction, "SW") == 0){
            
            sscanf(tableau_instruction[(*PC)/4], "%s $%d,%d(%d)", instruction, &var1, &var2, &var2);

        }
        else if( strcmp( instruction, "XOR") == 0){
            
            sscanf(tableau_instruction[(*PC)/4], "%s $%d,$%d,$%d", instruction, &var1, &var2, &var3);
  
           
        }
        else if( strcmp( instruction, "SYSCALL") == 0){
            
            sscanf(tableau_instruction[(*PC)/4], "%s", instruction);
            
        }
        //update_gpr();
        (*PC)+=4;
        
  
    }
}

int nombre_instruction(char *nom_fichier_source){
    FILE *fichier_source_compte = fopen(nom_fichier_source,"r");
    if (fichier_source_compte == NULL){
        printf("Erreur ouverture fichier_source_compte : %s\n",nom_fichier_source);
        exit(0);
    }
    int nb_line = 0;
    char *buffer_compteur = (char *)malloc(MAX_LENGTH);
     while( !feof (fichier_source_compte)){
        fgets (buffer_compteur, MAX_LENGTH, fichier_source_compte);
        nb_line++;
     }
     printf("Il y a %d instruction\n",nb_line);
     fclose(fichier_source_compte);
     return nb_line;
     
}

char **copy_instruction_in_array(char *nom_fichier_source, int nb_instruction){
    FILE *fichier_source_copy = fopen(nom_fichier_source,"r");
    if (fichier_source_copy == NULL){
        printf("Erreur ouverture fichier_source_compte : %s\n",nom_fichier_source);
        exit(0);
    }
    
    int i=0;
    char **tableau_instruction = (char **)malloc(nb_instruction*100*sizeof(char *));
    char *buffer_copy = (char *)malloc(MAX_LENGTH);
    while( !feof (fichier_source_copy)){
        fgets (buffer_copy, MAX_LENGTH, fichier_source_copy);
        strcpy(tableau_instruction[i],buffer_copy);
        printf("i = %d\t",i);
        printf("%s\n",tableau_instruction[i]);
        i++;
        
     }



     fclose(fichier_source_copy);
     
     for(int j = 0; j<nb_instruction;j++){
        printf("j = %d\t %s\n",j,tableau_instruction[j]);
    }
     return tableau_instruction;
}