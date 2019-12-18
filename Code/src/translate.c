#include "translate.h"



void translate(char *nom_fichier_source, char *nom_fichier_instruction){
    /* Opening of files */
    FILE *fichier_source = fopen(nom_fichier_source,"r");
    FILE *fichier_instruction = fopen(nom_fichier_instruction,"w");
    if (fichier_source == NULL){
        printf("Erreur ouverture fichier_source : %s\n",nom_fichier_source);
        exit(0);
    }
    if (fichier_instruction == NULL){
        printf("Erreur ouverture fichier_instruction : %s\n",nom_fichier_instruction);
        exit(0);
    }
    
    char *buffer = (char *)malloc(MAX_LENGTH);
    char instruction[10];
    char instruction_binaire[32]; // 32 bits
    char instruction_binaire_inverse[32];
    long instruction_hexa; // 4 octets
    int var1, var2, var3;
    while( !feof (fichier_source)){
        fgets (buffer, MAX_LENGTH, fichier_source);
        //printf("%s\n",buffer);
        sscanf(buffer, "%s ", instruction);
        
        if( strcmp( instruction, "ADDI") == 0){ // Add Immediate Word
            
            sscanf(buffer, "%s $%d,$%d,%d", instruction, &var1, &var2, &var3);
            instruction_binaire[32]='\n';
            instruction_binaire[31]='0';
            instruction_binaire[30]='0';
            instruction_binaire[29]='1';
            instruction_binaire[28]='0';
            instruction_binaire[27]='0';
            instruction_binaire[26]='0';
            int_to_binary(instruction_binaire,21,25,var2);
            int_to_binary(instruction_binaire,16,20,var1);
            int_to_binary_signed(instruction_binaire,0,15,var3);
            
           
        }
        else if( strcmp( instruction, "ADD") == 0){
            
            sscanf(buffer, "%s $%d,$%d,$%d", instruction, &var1, &var2, &var3);
            instruction_binaire[32]='\n';
            int_to_binary(instruction_binaire,26,31,0); // 000000 => SPECIAL
            int_to_binary(instruction_binaire,21,25,var2);
            int_to_binary(instruction_binaire,16,20,var3);
            int_to_binary(instruction_binaire,11,15,var1);
            int_to_binary(instruction_binaire,6,10,0);  // 0 => 00000
            int_to_binary(instruction_binaire,0,5,32); // 32 => 100000
            
           
        }
        else if( strcmp( instruction, "AND") == 0){
            
            sscanf(buffer, "%s $%d,$%d,$%d", instruction, &var1, &var2, &var3);
            instruction_binaire[32]='\n';
            int_to_binary(instruction_binaire,26,31,0); // 000000 => SPECIAL
            int_to_binary(instruction_binaire,21,25,var2);
            int_to_binary(instruction_binaire,16,20,var3);
            int_to_binary(instruction_binaire,11,15,var1);
            int_to_binary(instruction_binaire,6,10,0);  // 0 => 00000
            int_to_binary(instruction_binaire,0,5,36); // 36 => 100100
            
           
        }
        else if( strcmp( instruction, "BEQ") == 0){ // Branch on Equal
            
            sscanf(buffer, "%s $%d,$%d,%d", instruction, &var1, &var2, &var3);
            instruction_binaire[32]='\n';
            int_to_binary(instruction_binaire,26,31,4); 
            int_to_binary(instruction_binaire,21,25,var1);
            int_to_binary(instruction_binaire,16,20,var2);
            int_to_binary_signed(instruction_binaire,0,15,var3); // var3 = OFFSET 16 bits
            
           
        }
        else if( strcmp( instruction, "BGTZ") == 0){ // Branch on Greater Than Zero
            
            sscanf(buffer, "%s $%d,%d", instruction, &var1, &var2);
            instruction_binaire[32]='\n';
            int_to_binary(instruction_binaire,26,31,7); 
            int_to_binary(instruction_binaire,21,25,var1);
            int_to_binary(instruction_binaire,16,20,0);
            int_to_binary_signed(instruction_binaire,0,15,var2); // var2 = OFFSET 16 bits
            
           
        }
        else if( strcmp( instruction, "BLEZ") == 0){ // Branch on Less Than or Equal to Zero
            
            sscanf(buffer, "%s $%d,%d", instruction, &var1, &var2);
            instruction_binaire[32]='\n';
            int_to_binary(instruction_binaire,26,31,6);
            int_to_binary(instruction_binaire,21,25,var1);
            int_to_binary(instruction_binaire,16,20,0);
            int_to_binary_signed(instruction_binaire,0,15,var2); //var2 = OFFSET 16 bits
            
           
        }
        else if( strcmp( instruction, "BNE") == 0){ // Branch on Not Equal
            
            sscanf(buffer, "%s $%d,$%d,%d", instruction, &var1, &var2, &var3);
            instruction_binaire[32]='\n';
            int_to_binary(instruction_binaire,26,31,5);
            int_to_binary(instruction_binaire,21,25,var1);
            int_to_binary(instruction_binaire,16,20,var2);
            int_to_binary_signed(instruction_binaire,0,15,var3); //var3 = OFFSET 16 bits
            
           
        }
        else if( strcmp( instruction, "DIV") == 0){ // Divide Word
            
            sscanf(buffer, "%s $%d,$%d", instruction, &var1, &var2);
            instruction_binaire[32]='\n';
            int_to_binary(instruction_binaire,26,31,0);
            int_to_binary(instruction_binaire,21,25,var1);
            int_to_binary(instruction_binaire,16,20,var2);
            int_to_binary(instruction_binaire,6,15,0); 
            int_to_binary(instruction_binaire,0,5,26); // 26 => 011010
            
           
        }
        else if( strcmp( instruction, "JR") == 0){
            
            sscanf(buffer, "%s $%d", instruction, &var1);
            instruction_binaire[32]='\n';
            int_to_binary(instruction_binaire,26,31,0);
            int_to_binary(instruction_binaire,21,25,var1);
            int_to_binary(instruction_binaire,11,20,0);
            int_to_binary(instruction_binaire,6,10,0); //bits hint à 0, voir doc
            int_to_binary(instruction_binaire,0,5,8);
            
           
        }
        else if( strcmp( instruction, "JAL") == 0){
            
            sscanf(buffer, "%s %d", instruction, &var1);
            instruction_binaire[32]='\n';
            int_to_binary(instruction_binaire,26,31,3);
            int_to_binary(instruction_binaire,0,25,var1); //var1 = instr_index
            
           
        }
        else if( strcmp( instruction, "J") == 0){
            
            sscanf(buffer, "%s %d", instruction, &var1);
            instruction_binaire[32]='\n';
            int_to_binary(instruction_binaire,26,31,2);
            int_to_binary(instruction_binaire,0,25,var1); //var1 = instr_index
            
           
        }
        else if( strcmp( instruction, "LUI") == 0){ // Load Upper Immediate
            
            sscanf(buffer, "%s $%d,%d", instruction, &var1, &var2);
            instruction_binaire[32]='\n';
            int_to_binary(instruction_binaire,26,31,15);
            int_to_binary(instruction_binaire,21,25,0);
            int_to_binary(instruction_binaire,16,20,var1);
            int_to_binary_signed(instruction_binaire,0,15,var2);
            
           
        }
        else if( strcmp( instruction, "LW") == 0){ // Load Word
            
            sscanf(buffer, "%s $%d,%d(%d)", instruction, &var1, &var2, &var3);
            instruction_binaire[32]='\n';
            int_to_binary(instruction_binaire,26,31,35);
            int_to_binary(instruction_binaire,21,25,var3); //var3 = base
            int_to_binary(instruction_binaire,16,20,var1);
            int_to_binary_signed(instruction_binaire,0,15,var2); 
            
           
        }
        else if( strcmp( instruction, "MFHI") == 0){ // Move From HI Register
            
            sscanf(buffer, "%s $%d", instruction, &var1);
            instruction_binaire[32]='\n';
            int_to_binary(instruction_binaire,26,31,0);
            int_to_binary(instruction_binaire,16,25,0);
            int_to_binary(instruction_binaire,11,15,var1);
            int_to_binary(instruction_binaire,6,10,0);
            int_to_binary(instruction_binaire,0,5,32); // 32 => 010000
            
           
        }
        else if( strcmp( instruction, "MFLO") == 0){ // Move From LO Register
            
            sscanf(buffer, "%s $%d", instruction, &var1);
            instruction_binaire[32]='\n';
            int_to_binary(instruction_binaire,26,31,0);
            int_to_binary(instruction_binaire,16,25,0);
            int_to_binary(instruction_binaire,11,15,var1);
            int_to_binary(instruction_binaire,6,10,0);
            int_to_binary(instruction_binaire,0,5,34); // 32 => 010010
            
           
        }
        else if( strcmp( instruction, "ROTR") == 0){
            
            sscanf(buffer, "%s $%d,$%d,$%d", instruction, &var1, &var2, &var3);
            instruction_binaire[32]='\n';
            int_to_binary(instruction_binaire,21,31,1); // le bit R1 est mis à 1 ici, à verifier plus tard
            int_to_binary(instruction_binaire,16,20,var2);
            int_to_binary(instruction_binaire,11,15,var1);
            int_to_binary(instruction_binaire,6,10,var3);
            int_to_binary(instruction_binaire,0,5,2); // 2 => 000010
            
           
        }
        else if( strcmp( instruction, "SLL") == 0){
            
            sscanf(buffer, "%s $%d,$%d,%d", instruction, &var1, &var2, &var3);
            instruction_binaire[32]='\n';
            int_to_binary(instruction_binaire,21,31,0);
            int_to_binary(instruction_binaire,16,20,var2);
            int_to_binary(instruction_binaire,11,15,var1);
            int_to_binary(instruction_binaire,6,10,var3);
            int_to_binary(instruction_binaire,0,5,0); 
            
           
        }
        else if( strcmp( instruction, "MULT") == 0){ // Multiply Word
            
            sscanf(buffer, "%s $%d,$%d", instruction, &var1, &var2);
            instruction_binaire[32]='\n';
            int_to_binary(instruction_binaire,26,31,0);
            int_to_binary(instruction_binaire,21,25,var1);
            int_to_binary(instruction_binaire,16,20,var2);
            int_to_binary(instruction_binaire,6,15,0);
            int_to_binary(instruction_binaire,0,5,24); // 24 => 011000
            
           
        }
        else if( strcmp( instruction, "NOP") == 0){ // No Operation
            
            sscanf(buffer, "%s ", instruction);
            instruction_binaire[32]='\n';
            int_to_binary(instruction_binaire,0,31,0);
            
           
        }
        else if( strcmp( instruction, "OR") == 0){
            
            sscanf(buffer, "%s $%d,$%d,$%d", instruction, &var1, &var2, &var3);
            instruction_binaire[32]='\n';
            int_to_binary(instruction_binaire,26,31,0);
            int_to_binary(instruction_binaire,21,25,var2);
            int_to_binary(instruction_binaire,16,20,var3);
            int_to_binary(instruction_binaire,11,15,var1);
            int_to_binary(instruction_binaire,6,10,0);
            int_to_binary(instruction_binaire,0,5,37); // 37 => 100101
            
           
        }
        else if( strcmp( instruction, "SLT") == 0){
            
            sscanf(buffer, "%s $%d,$%d,$%d", instruction, &var1, &var2, &var3);
            instruction_binaire[32]='\n';
            int_to_binary(instruction_binaire,26,31,0);
            int_to_binary(instruction_binaire,21,25,var2);
            int_to_binary(instruction_binaire,16,20,var3);
            int_to_binary(instruction_binaire,11,15,var1);
            int_to_binary(instruction_binaire,6,10,0);
            int_to_binary(instruction_binaire,0,5,42); // 42 => 101010
            
           
        }
        else if( strcmp( instruction, "SRL") == 0){
            
            sscanf(buffer, "%s $%d,$%d,%d", instruction, &var1, &var2, &var3);
            instruction_binaire[32]='\n';
            int_to_binary(instruction_binaire,21,31,0); // bit R0 mis à 0, à verifier plus tard
            int_to_binary(instruction_binaire,16,20,var2);
            int_to_binary(instruction_binaire,11,15,var1);
            int_to_binary(instruction_binaire,6,10,var3);
            int_to_binary(instruction_binaire,0,5,2); 
            
           
        }
        else if( strcmp( instruction, "SUB") == 0){
            
            sscanf(buffer, "%s $%d,$%d,$%d", instruction, &var1, &var2, &var3);
            instruction_binaire[32]='\n';
            int_to_binary(instruction_binaire,26,31,0);
            int_to_binary(instruction_binaire,21,25,var2);
            int_to_binary(instruction_binaire,16,20,var3);
            int_to_binary(instruction_binaire,11,15,var1);
            int_to_binary(instruction_binaire,6,10,0);
            int_to_binary(instruction_binaire,0,5,34); // 34 => 100010
            
           
        }
        else if( strcmp( instruction, "SW") == 0){
            
            sscanf(buffer, "%s $%d,%d(%d)", instruction, &var1, &var2, &var2);
            instruction_binaire[32]='\n';
            int_to_binary(instruction_binaire,26,31,43); // 43 => 101011
            int_to_binary(instruction_binaire,21,25,var3);
            int_to_binary(instruction_binaire,16,20,var1);
            int_to_binary_signed(instruction_binaire,0,15,var2);
            
           
        }
        else if( strcmp( instruction, "XOR") == 0){
            
            sscanf(buffer, "%s $%d,$%d,$%d", instruction, &var1, &var2, &var3);
            instruction_binaire[32]='\n';
            int_to_binary(instruction_binaire,26,31,0);
            int_to_binary(instruction_binaire,21,25,var2);
            int_to_binary(instruction_binaire,16,20,var3);
            int_to_binary(instruction_binaire,11,15,var1);
            int_to_binary(instruction_binaire,6,10,0); 
            int_to_binary(instruction_binaire,0,5,38); // 38 => 100110
            
           
        }
        else if( strcmp( instruction, "SYSCALL") == 0){
            
            sscanf(buffer, "%s", instruction);
            instruction_binaire[32]='\n';
            int_to_binary(instruction_binaire,26,31,0);
            int_to_binary(instruction_binaire,6,25,0); // code field is available for use as software parameters
            int_to_binary(instruction_binaire,0,5,12); 
            
           
        }
        
        //printf("instruction liste = %s, var1 = %d, var2 = %d, var3 = %d \n", instruction, var1, var2, var3);
        /*
        printf("binaire dans l'order = ");
        for(int i = 31; i>=0; i--){
            printf("%c",instruction_binaire[i]);
        }
        printf("\n"); 
        */
        
        
        for(int i = 0; i<=31 ; i++){
            instruction_binaire_inverse[i]=instruction_binaire[31-i];
        }
        instruction_binaire_inverse[32] = '\n';
        instruction_hexa = strtol(instruction_binaire_inverse, NULL, 2); // binaire => decimal
        fprintf(fichier_instruction,"%08lX\n",instruction_hexa); // decimal => hexa
    }
    fclose(fichier_source);      //We close the FILE
    fclose(fichier_instruction);
    
}

void int_to_binary_signed(char *instruction_binaire,int bit_debut, int bit_fin, int valeur){
    if(valeur>=0){
        for(int i = bit_debut; i<=bit_fin-1; i++){
            instruction_binaire[i] = (valeur % 2) + '0';
            valeur=valeur/2;
        }
        instruction_binaire[bit_fin]= 0 + '0';
    }   
    else if(valeur<0){
        valeur=abs(valeur);
        for(int i = bit_debut; i<=bit_fin - 1; i++){
            instruction_binaire[i] = (valeur % 2) + '0'; 
            valeur=valeur/2;
            if(instruction_binaire[i] == '0'){
                instruction_binaire[i] = '1';
            }
            else{
                instruction_binaire[i] = '0';
            }
        }
        instruction_binaire[bit_fin]= 1 + '0';
        
        
        int retenu = 1;
        int i=bit_debut;
        
        while((retenu == 1) && (i < bit_fin)){
            if(instruction_binaire[i] == '0'){
                instruction_binaire[i] = '1';
                retenu = 0;
            }
            else{
                instruction_binaire[i] = '0';
            }
            i++; 
        }
        if(i == bit_fin){
            printf("Attention valeur trop négative, cf int_to_binary\n");
        }
    }
}

void int_to_binary(char *instruction_binaire,int bit_debut, int bit_fin, int valeur){
    for(int i = bit_debut; i<=bit_fin; i++){
            instruction_binaire[i] = (valeur % 2) + '0';
            valeur=valeur/2;
    }
}



