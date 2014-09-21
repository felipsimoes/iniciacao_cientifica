#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#define iteracoes 750
#define alfa 0.1
main(){
int li,co,a,b,iter;
float valor, soma_total, maior, menor, custo;
double **total, *theta, *hipotese, *erro, *erro_sqr, J, q;
double **matriz, *vetordey, *theta_change, **gradiente, soma_gradiente;
FILE *file;

/* IMPORTA DADOS */
    file = fopen("ex1data1.txt", "r");
    fscanf(file, "%i %i", &li, &co);
    matriz = (double**) malloc(li * sizeof(double*));
    vetordey = (double*) malloc(li * sizeof(double));
     for(a = 0; a <= li; a++){
         matriz[a] = (double*) malloc(co * sizeof(double));
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
for(a=0;a<li;a++){
    matriz[a][0] = 1;
}

/* INICIALIZACAO DE HIPOTESE, ERRO E ERRO_SQR */
hipotese = (double*) malloc(li * sizeof(double));
erro = (double*) malloc(li * sizeof(double));
erro_sqr = (double*) malloc(li * sizeof(double));
for(a=0;a<li;a++){
    hipotese[a]=0;
}
/* INICIALIZACAO DOS THETAS */
theta = (double*) malloc(co * sizeof(double));
theta_change = (double*) malloc(co * sizeof(double));
for(b=0;b<co;b++){
    theta[b]=0.0;
    theta_change[b]=0.0;
}
/* INICIALIZACAO DO GRADIENTE */
gradiente = (double**) malloc (li * sizeof(double*));
for(a=0;a<=li;a++){
   gradiente[a] = (double*) malloc (co * sizeof(double));
   for(b=0;b<co;b++){
    gradiente[a][b]=0.0;
   }
}

////////////
/* NORMALIZACAO DE DADOS */
total = (double**) malloc(3 * sizeof(double*));
for(a=0;a<3;a++){
    total[a] = (double*) malloc(co * sizeof(double));
    for(b=0;b<co;b++){
        total[a][b]= 0.0;
    }
}

    for (b=1; b < co; b++){
        maior = matriz[0][b];
        menor = matriz[0][b];
        soma_total = 0;
        for (a=0; a<li; a++){
            soma_total = soma_total + matriz[a][b];
            if(matriz[a][b] > maior){
                maior = matriz[a][b];
            }
            if(matriz[a][b] < menor){
                menor = matriz[a][b];
            }
        }
        total[0][b]= soma_total;
        total[1][b]= maior;
        total[2][b]= menor;
    }
//Normalização entre ZERO e UM
for(a=0;a<li;a++){
    for(b=1;b<co;b++){
        matriz[a][b]=(matriz[a][b]-total[2][b])/(total[1][b]-total[2][b]);
    }
}
///////////

/* FUNCAO DE CUSTO */
J = 0.0;
q = 0.0;
for(a=0;a<=li;a++){
    hipotese[a]=0;
    for(b=0;b<co;b++){
        hipotese[a] += (theta[b] * matriz[a][b]);
    }
    erro[a] = (hipotese[a] - vetordey[a]);
    erro_sqr[a] = pow(erro[a],2);
}
for(a=0;a<li;a++){
q += erro_sqr[a];
}
J = (1.0/(2.0*li)) * q;

printf("\nJ inicial igual a : %f",J);


/* GRADIENTE DESCENDENTE */
for (iter=1;iter<=iteracoes;iter++){
    for(a=0;a<li;a++){
        hipotese[a]=0.0;
        for(b=0;b<co;b++){
            hipotese[a] += (theta[b] * matriz[a][b]);
        }
        erro[a] = (hipotese[a] - vetordey[a]);
    }
    for(b=0;b<co;b++){
        for(a=0;a<=li;a++){
            if(a==0){soma_gradiente=0.0;}
            if(a==li){gradiente[a][b] = soma_gradiente; break;}
            gradiente[a][b] = matriz[a][b] * erro[a];
            soma_gradiente += gradiente[a][b];
        }
    }
    for(b=0;b<co;b++){
        theta_change[b]=0.0;
        theta_change[b] = alfa * ((1.0/li)* gradiente[li][b]);
        theta[b]=theta[b]-theta_change[b];
    }
}

/* FUNCAO DE CUSTO */
J = 0.0;
q = 0.0;
for(a=0;a<=li;a++){
    hipotese[a]=0.0;
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

printf("\nJ final igual a : %f",J);
printf("\nTheta zero: %f e theta 1: %f",theta[0],theta[1]);

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
