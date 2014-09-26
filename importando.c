#include "stdio.h"
#include "stdlib.h"
char **linhas, **colunas;
float **tabela;
int i,j;
void ImportaLinhas();
void ImportaColunas();
main(){

    ImportaLinhas();
    ImportaColunas();

}

void ImportaLinhas(){
FILE *file;
    file = fopen("sideInfoRowsMovielens.txt", "r");
    if(file == NULL) {
            printf("\nOcorreu um erro ao acessar este arquivo.\n");
            exit(1); }
    linhas = (char**) malloc(943 * sizeof(char*));
    for(i=0;i<=943;i++){
        linhas[i] = (char*) malloc(100 * sizeof(char));
        fscanf(file, "%s", &linhas[i][0]);
    }
    fclose(file);
}

void ImportaColunas(){
FILE *file;
    file = fopen("sideInfoColumnsMovielens.txt", "r");
    if(file == NULL) {
            printf("\nOcorreu um erro ao acessar este arquivo.\n");
            exit(1); }
    colunas = (char**) malloc(1682 * sizeof(char*));
    for(i=0;i<=1682;i++){
        colunas[i] = (char*) malloc(100 * sizeof(char));
        fscanf(file, "%s", &colunas[i][0]);
    }
    fclose(file);
}

void ImportaTabela(){
FILE *file;
    file = fopen("ratingsMovielens.txt", "r");
    if(file == NULL) {
            printf("\nOcorreu um erro ao acessar este arquivo.\n");
            exit(1); }
    tabela = (float**) malloc(943 * sizeof(float*));
    for(i=0;i<=943;i++){
        tabela[i] = (float*) malloc(1682 * sizeof(float));
        for(j=0;j<=1682;j++){
            fscanf(file, "%f", &tabela[i][j]);
        }
    }
    fclose(file);
}
