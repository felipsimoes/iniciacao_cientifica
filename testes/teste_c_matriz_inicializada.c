#include "stdio.h"
int matriz[3][4] = { 1, 15, 20, 30,
                     1, 18, 26, 31,
                     1, 26, 13, 26};
int soma[3][4]= { 1, 1, 1, 1,
                  1, 1, 1, 1,
                  1, 1, 1, 1};
main(){
//M - linhas da matriz de dados ou quantidade de amostras
//X - variaveis independentes ou colunas da matriz de dados
int li, co, M = 3, X = 4;
int soma_total, maior, menor;
int total[3][4];


for(li=0;li<M;li++){
    for(co=0;co<X;co++){
        if(co==X-1){
            break;
        }
        printf("\n%d",matriz[li][co]);
    }
}
//primeira coluna de total é inicializada em 1
//for(li=0;li<=2;li++){
//    total[li][0] = 1;
//}

/*
    //a cada linha da matriz de dados analisados
    M = M - 1; // o índice começa em zero, portanto, reduzimos um do valor de M
    X = X - 1; // o índice começa em zero, portanto, reduzimos um do valor de X
    for (co=1; co <= X; co++){
        maior = matriz[0][co];
        menor = matriz[0][co];
        soma_total = 0;
        //printf("\n\nEstou na linha de indice %d",co);
        for (li=0; li<=M; li++){
            printf("\n%d", matriz[li][co]);
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
       // printf("\nSoma desta coluna: %d", total[0][co]);
       // printf("\nMaior desta coluna: %d", total[1][co]);
      //  printf("\nMenor desta coluna: %d", total[2][co]);

    } */
}
