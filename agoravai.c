#include "stdio.h"
#include "stdlib.h"
#include "math.h"

main(){
int li,co, iteracoes = 1000;
int a,b,iter;
float valor, soma_total, maior, menor, alfa = 0.01, custo;
float **total, *theta, *hipotese, *erro;
double *erro_sqr;
double J, q;
//uma matriz terá dois ponteiros (por ser bidimensional)
float **matriz, *vetordey;
float **erro_transposto, **gradiente_tranposto;
FILE *file;

/* IMPORTA DADOS */
//importa dados do arquivo de texto
    file = fopen("ex1data1.txt", "r");
//primeiros valores referentes a linhas e colunas
    fscanf(file, "%i %i", &li, &co);
//inicialização dinâmica da matriz importada do arquivo de texto
//primeiro ponteiro faz alocação do número de linhas, com elementos de tipo float
    matriz = (float**) malloc(li * sizeof(float*));
    vetordey = (float*) malloc(li * sizeof(float));
    //com índice inicial ZERO, até o número de linhas menos um
    for(a = 0; a <= li; a++){
        //segundo ponteiro faz alocação do número de colunas, com elementos de tipo float
        matriz[a] = (float*) malloc(co * sizeof(float));
            //sabendo que o índice zero será inicializado em 1, começo o índice 1 de colunas
            for(b = 1; b <= co; b++){
                fscanf(file,"%f",&valor);
                if(b == co){
                 vetordey[a] = valor;
                }
                else {
                 matriz[a][b] = valor;
                }
            }
    }
    fclose(file);

/* INDICE ZERO INICIALIZADO EM 1 */
//primeira coluna da matriz, índice ZERO, é inicializada em 1
for(a=0;a<li;a++){
    matriz[a][0] = 1;
}
/* INICIALIZACAO DE HIPOTESE, ERRO E ERRO_SQR */
//inicializacao do vetor hipotese
hipotese = (float*) malloc(li * sizeof(float));
erro = (float*) malloc(li * sizeof(float));
erro_sqr = (double*) malloc(li * sizeof(double));
for(a=0;a<li;a++){
    hipotese[a]=0;
}
/* INICIALIZACAO DOS THETAS */
//inicializacao dos thetas
theta = (float*) malloc(co * sizeof(float));
for(b=0;b<co;b++){
    theta[b]=0.0;
}

/* FUNCAO DE CUSTO */
J = 0.0;
q = 0.0;
//por linha eu tenho uma hipotese
for(a=0;a<=li;a++){
    for(b=0;b<co;b++){
        hipotese[a] += (theta[b] * matriz[a][b]);
    }
    erro[a] = (hipotese[a] - vetordey[a]);
    erro_sqr[a] = pow(erro[a],2);
}
for(a=0;a<li;a++){
q += erro_sqr[a];
}
J = (1.0/(2*li)) * q;

printf("\nJ igual a : %f",J);

/* Matrizes transpostas */
erro_tranposto = (float**) malloc(li * sizeof(float*));
for(a=0;a<li;a++){
    erro_tranposto = (float*) malloc(co * sizeof(float));
    for(b=0;a<co;b++){
        erro_transposto[a][b] = erro[b][a];
    }
}

/* GRADIENTE DESCENDENTE */

for (iter=1;iter<=iteracoes;iter++){
    for(a=0;a<=li;a++){
        for(b=0;b<co;b++){
            hipotese[a] += (theta[b] * matriz[a][b]);
        }
        erro[a] = (hipotese[a] - vetordey[a]);
        //gradiente = ;
    }
}


}

//VERIFICACOES
/*//exibição teste da matriz com os valores importados e inicializados
for(a=0;a<li; a++){
    printf("\n");
    for(b=0;b<co;b++){
        printf("%.1f ",matriz[a][b]);
    }
}
for(a=0;a<li; a++){
    printf("\n");
    printf("%.1f ",vetordey[a]);

}*/
/*Exibição da Matriz Normalizada
printf("\n\n\n");
for(a=0;a<li; a++){
    printf("\n");
    for(b=0;b<co;b++){
        printf("%.1f ",matriz[a][b]);
    }
}*/
