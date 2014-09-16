#include "stdio.h"
#include "stdlib.h"

main(){
//li - linhas da matriz de dados ou quantidade de amostras
//co - variaveis independentes ou colunas da matriz de dados
int li,co, iteracoes = 1000;
int a,b,i;
float valor, soma_total, maior, menor, alfa = 0.01, hipotese, custo;
float **total, *theta, erro;
//uma matriz ter� dois ponteiros (por ser bidimensional)
float **matriz, *vetordey;
FILE *file;
//importa dados do arquivo de texto
    file = fopen("ex1data1.txt", "r");
//primeiros valores referentes a linhas e colunas
    fscanf(file, "%i %i", &li, &co);
    printf("%d %d", li, co);
//adicionado um elemento para coluna, o �ndice ZERO, que ser� inicializado em 1
   // co = co + 1;
//inicializa��o din�mica da matriz importada do arquivo de texto
//primeiro ponteiro faz aloca��o do n�mero de linhas, com elementos de tipo float
    matriz = (float**) malloc(li * sizeof(float*));
    vetordey = (float*) malloc(li * sizeof(float));
    //com �ndice inicial ZERO, at� o n�mero de linhas menos um
    for(a = 0; a <= li; a++){
        //segundo ponteiro faz aloca��o do n�mero de colunas, com elementos de tipo float
        matriz[a] = (float*) malloc(co * sizeof(float));
            //sabendo que o �ndice zero ser� inicializado em 1, come�o o �ndice 1 de colunas
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
//primeira coluna da matriz, �ndice ZERO, � inicializada em 1
for(a=0;a<li;a++){
    matriz[a][0] = 1;
}
//inicializacao dos thetas
theta = (float*) malloc(li * sizeof(float));
for(a=0;a<co;a++){
    theta[a]=0;
}


for(i=0;i<20;i++){
        erro = 0.0;
        //por linha eu tenho uma hipotese
        for(a=0;a<=li;a++){
            hipotese = 0;
            for(b=0;b<co;b++){
                hipotese = hipotese + (theta[b] * matriz[a][b]);
        }
            erro = erro + (hipotese - vetordey[a]);


        }

        //atualiza thetas, gradiente descendente
        custo = 0;
        for(b=0;b<co;b++){
            a = b;

        //theta[b] = theta[b] - alfa * (1.0/(2.0*li)) * erro * matriz[a][b];
        custo += theta[b];

        }
        printf("\nNa iteracao %d custo foi de : %f",i,custo);

        //

    }
}

//VERIFICACOES
/*//exibi��o teste da matriz com os valores importados e inicializados
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
/*Exibi��o da Matriz Normalizada
printf("\n\n\n");
for(a=0;a<li; a++){
    printf("\n");
    for(b=0;b<co;b++){
        printf("%.1f ",matriz[a][b]);
    }
}*/
