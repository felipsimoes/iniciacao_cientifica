#include "stdio.h"
#include "stdlib.h"

main(){
//li - linhas da matriz de dados ou quantidade de amostras
//co - variaveis independentes ou colunas da matriz de dados
int li,co;
int a,b;
float valor, soma_total, maior, menor;
double *theta;
float **total;
//uma matriz ter� dois ponteiros (por ser bidimensional)
float **matriz;
FILE *file;
//importa dados do arquivo de texto
    file = fopen("BaseDeDados.txt", "r");
//primeiros valores referentes a linhas e colunas
    fscanf(file, "%i %i", &li, &co);
    printf("%d %d", li, co);
//adicionado um elemento para coluna, o �ndice ZERO, que ser� inicializado em 1
    co = co + 1;
//inicializa��o din�mica da matriz importada do arquivo de texto
//primeiro ponteiro faz aloca��o do n�mero de linhas, com elementos de tipo float
    matriz = (float**) malloc(li * sizeof(float*));
    //com �ndice inicial ZERO, at� o n�mero de linhas menos um
    for(a = 0; a < li; a++){
        //segundo ponteiro faz aloca��o do n�mero de colunas, com elementos de tipo float
        matriz[a] = (float*) malloc(co * sizeof(float));
            //sabendo que o �ndice zero ser� iniciliazado em 1, come�o o �ndice 1 de colunas
            for(b = 1; b < co; b++){
                fscanf(file,"%f",&valor);
                matriz[a][b] = valor ;
            }
    }
    fclose(file);
//primeira coluna da matriz, �ndice ZERO, � inicializada em 1
for(a=0;a<li;a++){
    matriz[a][0] = 1;
}
//exibi��o teste da matriz com os valores importados e inicializados
for(a=0;a<li; a++){
    printf("\n");
    for(b=0;b<co;b++){
        printf("%.1f ",matriz[a][b]);
    }
}

//matriz bidimensional dinamicamente inicializada, contendo sempre 3 elementos de linhas.
//total[0] -> soma_total, total[1] -> maior, total[2] -> menor
total = (float**) malloc(3 * sizeof(float*));
for(a=0;a<3;a++){
    //os elementos de colunas correspondem ao n�mero de colunas da matriz importadas, considerando o �ndice zero inicializado em 1
    total[a] = (float*) malloc(co * sizeof(float*));
    for(b=0;b<co;b++){
        //todos os valores s�o previamente inicializados 1.0
        total[a][b]= 1.0;
    }
}
    //a matriz de dados � percorrida para identificar o maior e o menor valor de cada coluna
    //enquanto s�o percorridos os valores de cada coluna, � realizada a soma_total
    //percorridas as colunas a partir do �ndice 1, onde est�o os primeiros valores importados
    for (b=1; b < co; b++){
        //inicialmente atribuimos o primeiro valor da coluna como maior e menor da s�rie de valores
        //que serao comparados. a soma_total tamb�m � inicializada em ZERO.
        maior = matriz[0][b];
        menor = matriz[0][b];
        soma_total = 0;
        for (a=0; a<li; a++){
            //a cada valor percorrido por linha, adicionamos a soma_total
            soma_total = soma_total + matriz[a][b];
            //caso o valor atual seja maior que o anterior, ele se torna o novo maior
            if(matriz[a][b] > maior){
                maior = matriz[a][b];
            }
            //caso o valor atual seja menor que o anterior, ele se torna o novo menor
            if(matriz[a][b] < menor){
                menor = matriz[a][b];
            }
        }
        //percorridos todos os valores da coluna s�o atribuidos os respectivos �ndices
        //na matriz total, como definido previamente.
        total[0][b]= soma_total;
        total[1][b]= maior;
        total[2][b]= menor;
        printf("\nSoma desta coluna: %1.f", total[0][b]);
        printf("\nMaior desta coluna: %1.f", total[1][b]);
        printf("\nMenor desta coluna: %1.f", total[2][b]);
    }
//Normaliza��o entre ZERO e UM
for(a=0;a<li;a++){
    for(b=1;b<co;b++){
        //total[2] -> menor, total[1] -> maior
        matriz[a][b]=(matriz[a][b]-total[2][b])/(total[1][b]-total[2][b]);
    }
}
//Exibi��o da Matriz Normalizada
printf("\n\n\n");
for(a=0;a<li; a++){
    printf("\n");
    for(b=0;b<co;b++){
        printf("%.1f ",matriz[a][b]);
    }
}

theta = (double*) malloc((co) * sizeof(double*));

for(b=0;b<co;b++){
    theta[b] = theta[b] - alfa * (1/(co-1)) *
}

}

