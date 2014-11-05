#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "omp.h"
#define NUM_THREADS 4
#define iteracoes 3000
#define alfa 0.1
int li,co,a,b,iter;
float valor, soma_total, maior, menor;
double **total, *theta, *erro, q, h;
double **matriz, *y, *theta_change, *gradiente;
void ImportarDados();
void InicializarVariaveisGradiente();
void NormalizarDados();
void GradienteDescendente();
double FuncaoCusto();
double mse();
int main(){

    ImportarDados();
    InicializarVariaveisGradiente();
    //NormalizarDados();
    printf("\nCusto inicial igual a : %f", mse());
    GradienteDescendente();
    printf("\nCusto final igual a : %f", mse());
    printf("\nTheta zero: %f e theta 1: %f",theta[0],theta[1]);

    return 0;
}

void ImportarDados(){
    FILE *file;

    file = fopen("baseNormalizada.txt", "r");
    if(file == NULL) {
            printf("\nOcorreu um erro ao acessar este arquivo.\n");
            exit(1); }

    fscanf(file, "%d %d", &li, &co);
    matriz = (double**) malloc(li * sizeof(double*));
    y = (double*) malloc(li * sizeof(double));
     for(a = 0; a < li; a++){
         matriz[a] = (double*) malloc(co * sizeof(double));
         matriz[a][0] = 1.0;
          for(b = 1; b <= co; b++){
            fscanf(file,"%f",&valor);
                if(b == co){ y[a] = valor; }
                else { matriz[a][b] = valor; }
            }
    }

    fclose(file);
}

double FuncaoCusto(){
        q = 0;
        for(a=0;a<li;a++){
            h=0;
            for(b=0;b<co;b++){
                h += (theta[b] * matriz[a][b]);
            }
            q += pow((h-y[a]),2);
        }
        return ((1.0/(2.0*li)) * q);
}

double mse(){
        q = 0;
        for(a=0;a<li;a++){
            h=0;
            for(b=0;b<co;b++){
                h += (theta[b] * matriz[a][b]);
            }
            q += pow((h-y[a]),2);
        }
        return (q/li);
}

void InicializarVariaveisGradiente(){
        erro = (double*) malloc(li * sizeof(double));
        gradiente = (double*) malloc (co * sizeof(double));
        theta = (double*) malloc(co * sizeof(double));
        theta_change = (double*) malloc(co * sizeof(double));
        for(b=0;b<co;b++){
            theta[b]=0.0;
            theta_change[b]=0.0;
        }
}

void GradienteDescendente(){
double h = 0;
double red = 0;
    for (iter=1;iter<=iteracoes;iter++){
           //#pragma omp parallel for reduction(+:h) private(a) shared(theta,matriz) num_threads(8)
           for(a=0;a<li;a++){
            for(b=0;b<co;b++){
                h += (theta[b] * matriz[a][b]);
            }
            erro[a] = (h - y[a]);
            h=0;
           }

        for(b=0;b<co;b++){
            gradiente[b] = 0;
            #pragma omp parallel for reduction(+:red) num_threads(NUM_THREADS)
            for(a=0;a<li;a++){
                red+= matriz[a][b] * erro[a];
            }
            gradiente[b] = red;
            red = 0;
            theta_change[b] = 0;
            theta_change[b] = alfa * ((1.0/li)* gradiente[b]);
            theta[b]=theta[b]-theta_change[b];
        }
    }
}

void NormalizarDados(){
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
                        maior = matriz[a][b]; }
                    if(matriz[a][b] < menor){
                        menor = matriz[a][b]; }
                }
                total[0][b]= soma_total;
                total[1][b]= maior;
                total[2][b]= menor;
            }
        for(a=0;a<li;a++){
            for(b=1;b<co;b++){
                matriz[a][b]=(matriz[a][b]-total[2][b])/(total[1][b]-total[2][b]); }
        }
}
