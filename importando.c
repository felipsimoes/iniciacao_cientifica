#include "stdio.h"
#include "stdlib.h"
#include "string.h"
char **linhas, **colunas;
char relaciona[100000][200] = {};
float **tabela, **treinamento;
char buff;
int i,j;
void ImportaLinhas();
void ImportaColunas();
void ImportaTabela();
void EscreveDados();
void MatrizTreinamento();

int main(){

    ImportaLinhas();
    ImportaColunas();
    ImportaTabela();
    MatrizTreinamento();
    EscreveDados();

    return 0;
}

void ImportaLinhas(){
FILE *file;
    file = fopen("datasets/sideInfoRowsMovielens.txt", "r");
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
    file = fopen("datasets/sideInfoColumnsMovielens.txt", "r");
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
char limite[5];
float conv;
    file = fopen("datasets/ratingsMovielens.txt", "r");
    if(file == NULL) {
            printf("\nOcorreu um erro ao acessar este arquivo.\n");
            exit(1); }
    tabela = (float**) malloc(943 * sizeof(float*));
    for(i=0;i<943;i++){
        tabela[i] = (float*) malloc(1682 * sizeof(float));
        for(j=0;j<1682;j++){
            fgets(limite,5,file);
            conv = atoi(limite);
            tabela[i][j] = conv;
        }
    }
    fclose(file);
}

void MatrizTreinamento(){
char escreve[200] = {};
int cont = 0, a = 0;

    for(i=0;i<943;i++){
        for(j=0;j<1682;j++){
            if(tabela[i][j] > 0){
                cont++;
            }
        }
    }
    for(i=0;i<943;i++){
        for(j=0;j<1682;j++){
            if(tabela[i][j] > 0){
                    strcat(escreve, linhas[i]);
                    strcat(escreve, colunas[j]);
                    strcpy(relaciona[a],escreve);
                    strcpy(escreve, "");
                    a++;
            }
        }
    }

}

void EscreveDados(){
FILE *file;
    file = fopen("teste.txt", "w");
    for(i=0;i<100000;i++){
        fprintf(file, "%s \n", relaciona[i]);
        }
        //fprintf(file, "\n");
    fclose(file);
}
