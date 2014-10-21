#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define teste1

float matriz[3][3] = {{15.0, 20.5, 16.5},{13.5, 152.0, 11.1},{123.0,22.5,0.4}};
int i,j,conv;
FILE *file;
char pega[3];
char escrevelinha[30] = {};
char convertestring[8] = {};
#ifdef teste1
main(){

file = fopen("teste.txt", "w");
for(i=0;i<3;i++){
    for(j=0;j<3;j++){
        sprintf(convertestring, "%.2f", matriz[i][j]);
        strcat(escrevelinha,convertestring);
        if(j!=2){
            strcat(escrevelinha," ");
        }
    }
    strcat(escrevelinha, "\0");
    fprintf(file, "%s\n",escrevelinha);

    strcpy(escrevelinha,"");
    strcpy(convertestring,"");
}
fclose(file);

}
#endif

#ifdef teste2
void PegaDados();
void EscreveDados();
main(){
    PegaDados();
    EscreveDados();
}
void EscreveDados(){

    file = fopen("novo.txt", "w");
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
        fprintf(file, "%d ", matriz[i][j]);
        }
        fprintf(file, "\n");}
    fclose(file);
}

void PegaDados(){
    file = fopen("teste.txt", "r");
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
           fgets(pega, 3, file);
           //printf("\n %d %s", j, pega);
            conv = atoi(pega);
            printf("%d", conv);
            matriz[i][j] = conv;
           //fscanf(file,"%s", matriz[i][j]);
        }
    }
}
#endif // teste2
