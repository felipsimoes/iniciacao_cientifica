#include "stdio.h"
#include "stdlib.h"

main(){
//M - linhas da matriz de dados ou quantidade de amostras
//X - variaveis independentes ou colunas da matriz de dados
int li,co;
int a,b;
float valor;
//uma matriz terá dois ponteiros (por ser bidimensional)
float **matriz;
FILE *file;
//importa dados do arquivo de texto
    file = fopen("BaseDeDados.txt", "r");
//primeiros valores referentes a linhas e colunas
    fscanf(file, "%i %i", &li, &co);
    printf("%d %d", li, co);
//adicionado um elemento para coluna, o índice ZERO, que será inicializado em 1
    co = co + 1;
//inicialização dinâmica da matriz importada do arquivo de texto
//primeiro ponteiro faz alocação do número de linhas, com elementos de tipo float
    matriz = (float**) malloc(li * sizeof(float*));
    //com índice inicial ZERO, até o número de linhas menos um
    for(a = 0; a < li; a++){
        //segundo ponteiro faz alocação do número de colunas, com elementos de tipo float
        matriz[a] = (float*) malloc(co * sizeof(float));
            //sabendo que o índice zero será iniciliazado em 1, começo o índice 1 de colunas
            for(b = 1; b < co; b++){
                fscanf(file,"%f",&valor);
                matriz[a][b] = valor ;
            }
    }
    fclose(file);
//primeira coluna da matriz, índice ZERO, é inicializada em 1
for(a=0;a<li;a++){
    matriz[a][0] = 1;
}
//exibição teste da matriz com os valores importados
for(a=0;a<li; a++){
    printf("\n");
    for(b=0;b<co;b++){
        printf("%.1f ",matriz[a][b]);
    }
}
/*
 //a cada linha da matriz de dados analisados
    M = M - 1; // o índice começa em zero, portanto, reduzimos um do valor de M
    X = X - 1; // o índice começa em zero, portanto, reduzimos um do valor de X
    for (co=1; co <= X; co++){
        maior = matriz[0][co];
        menor = matriz[0][co];
        soma_total = 0;
        printf("\n\nEstou na linha de indice %d",co);
        for (li=0; li<=M; li++){
            printf("\n%.1f", matriz[li][co]);
            soma_total = soma_total + matriz[li][co];
            if(matriz[li][co] > maior){
                maior = matriz[li][co];
            }
            if(matriz[li][co] < menor){
                menor = matriz[li][co];
            }
        }
        total[0][co]= soma_total;
        total[1][co]= maior;
        total[2][co]= menor;
        printf("\nSoma desta coluna: %1.f", total[0][co]);
        printf("\nMaior desta coluna: %1.f", total[1][co]);
        printf("\nMenor desta coluna: %1.f", total[2][co]);

    }
for(a=0;a<li;a++){
    for(b=0;b<co;b++)
    matriz[a][b]=(matriz[a][b]-total[2][b])/(total[1][b]-total[2][b]);
}
*/
}

