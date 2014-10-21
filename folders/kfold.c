#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define folders 10.0
int li,co,a,b;
float valor;
double **matriz, *y, *theta_change;

/** Gerar k-fold baseado em matriz de dados */
void ImportarDados();
void GerarFolders();
main(){

    ImportarDados();
    GerarFolders();
}

void ImportarDados(){
    FILE *file;

    file = fopen("../testeNormalizado2.txt", "r");
    if(file == NULL) {
            printf("\nOcorreu um erro ao acessar este arquivo.\n");
            exit(1); }

    fscanf(file, "%d %d", &li, &co);
    matriz = (double**) malloc(li * sizeof(double*));
    y = (double*) malloc(li * sizeof(double));
     for(a = 0; a < li; a++){
         matriz[a] = (double*) malloc(co * sizeof(double));
          for(b = 0; b < co; b++){
            fscanf(file,"%f",&valor);
            matriz[a][b] = valor;
            }
    }
    fclose(file);
}

void GerarFolders(){
float li_por_folder;
int lim, ult_a = 0, n;
char fold_number[4], fold_name[15];
char escrevelinha[150] = {};
char convertestring[25] = {};
FILE *file;

    li_por_folder = li / folders;
for(n=1;n<=10;n++){
    strcpy(fold_name, "folder");
    sprintf(fold_number, "%d", n);
    strcat(fold_name,fold_number);
    strcat(fold_name,".txt");
    file = fopen(fold_name, "w");

    for(a=ult_a;a<(li_por_folder*n);a++){
       for(b=0;b<co;b++){
        sprintf(convertestring, "%.2f", matriz[a][b]);
        strcat(escrevelinha,convertestring);
            if(b!=co-1){
                strcat(escrevelinha," ");
            }
        }
        strcat(escrevelinha, "\0");
        //if(n==1){ printf("\n%s",escrevelinha);}
        fprintf(file, "%s\n",escrevelinha);

        strcpy(escrevelinha,"");
        strcpy(convertestring,"");
    }

    ult_a = a;
    fclose(file);
}

}
