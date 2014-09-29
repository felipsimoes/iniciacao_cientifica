#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define teste3

int matriz[3][3];
int i,j,conv;
FILE *file;
char pega[3];
#ifdef teste1
main(){
file = fopen("teste.txt", "r");
for(i=0;i<3;i++){
    for(j=0;j<3;j++){
       fgets(pega, 3, file);
       //printf("\n %d %s", j, pega);
        conv = atoi(pega);
        printf("%d", conv);
        //matriz[i][j] = conv - 0;
       //fscanf(file,"%s", matriz[i][j]);
    }
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

#ifdef teste3
main(){
char teste1[3][10] = {"Meu nome:","My name:","Call me:"};
char teste2[3][10] = {"Felipe","Phill","Lipe"};
char res[3][30] = {};
int a;

for(a=0;a<3;a++){
strcpy(res[a],"");
strcat(res[a],teste1[a]);
strcat(res[a],teste2[a]);
}
printf("%s", res[2]);
}
#endif // teste3
