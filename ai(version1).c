#include "stdio.h"
#include "stdlib.h"

float matriz[3][4] = { 1, 15, 20, 30,
                     1, 18, 26, 31,
                     1, 26, 13, 26};
float soma[3][4]= { 1, 1, 1, 1,
                  1, 1, 1, 1,
                  1, 1, 1, 1};
main(){
//M - linhas da matriz de dados ou quantidade de amostras
//X - variaveis independentes ou colunas da matriz de dados
int li, co, M = 3, X = 4;
FILE *file;
float soma_total, maior, menor;
float total[3][4];
int cont_lin;

    file = fopen("BaseDeDados.txt", "r");
    fscanf(file, "%i %i", &li, &co);
    printf("%d %d", li, co);

    fclose(file);

//primeira coluna de total é inicializada em 1
for(li=0;li<=2;li++){
    total[li][0] = 1;
}
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
printf("\n\nMatriz de total");
//exibe a matriz de total
for(li=0;li<=M; li++){
        printf("\n");
    for(co=0;co<=X;co++){
        printf("%.1f ",total[li][co]);
    }
}

M=M+1;
//Normalização entre 0 e 1
for(li=0;li<=M;li++){
    for(co=1;co<=X;co++){
        matriz[li][co]=(matriz[li][co]-total[2][co])/(total[1][co]-total[2][co]);
    }
}
M=M-1;
printf("\n\nMatriz de dados");
//exibe a matriz de dados completa
for(li=0;li<=M; li++){
        printf("\n");
    for(co=0;co<=X;co++){
        printf("%.5f ",matriz[li][co]);
    }
}
}
