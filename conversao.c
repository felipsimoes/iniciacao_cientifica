#include "stdio.h"
#include "stdlib.h"
#include "string.h"
FILE *file;
int li, co, i, j, a;
double **matriz;
char buff[] = {};
void ImportaDados();
main(){

    matriz = (double**) malloc(li * sizeof(double*));
    for(i=0;i<li;li++){
    matriz[i] = (double*) malloc(co * sizeof(double));
        for(j=0;j<co;j++){
        matriz[i][j] = 0.0;
        }
    }
    ImportaDados();
    printf("%f", matriz[0][0]);
}
void ImportaDados(){
double valor;

file = fopen("teste.txt", "r");
fscanf(file, "%d %d", &li, &co);
for(i=0;i<li;i++){
    for(j=0;j<co;j++){
    fscanf(file, "%f", &valor);
    matriz[i][j] = valor;}
}

fclose(file);
}
/**
void ImportaDados(){
file = fopen("teste.txt", "r");
fscanf(file, "%d %d", &li, &co);
matriz = (double**) malloc(li * sizeof(double*));
for(i=0;i<li;i++){
    matriz[i] = (double*) malloc(co * sizeof(double));
    for(j=0;j<co-1;j++){
        //fscanf(file,"%s",&buff);
        fscanf(file,"%f",&matriz[i][j]);

    }
}
fclose(file);
} */
/**
void ImportaDados(){
float t;
char d = ' ', c = ';', *ptr;
char *ret;


file = fopen("pontovirgula.txt", "r");
fscanf(file, "%d %d", &li, &co);
for(i=0;i<li;i++){
    fscanf(file, "%s", &buff);
    ptr=buff;
    for(;*ptr!='\0';ptr++){
        if(*ptr==c)
        *ptr=d;
    }
}


fclose(file);
}
*/
