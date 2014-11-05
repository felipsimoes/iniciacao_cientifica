#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#define iteracoes 1500
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
        theta = (double*) malloc(co * sizeof(double));
        theta_change = (double*) malloc(co * sizeof(double));
        for(b=0;b<co;b++){
            theta[b]=0.0;
            theta_change[b]=0.0;
        }
        erro = (double*) malloc(li * sizeof(double));
        gradiente = (double*) malloc (co * sizeof(double));
}

void GradienteDescendente(){

    for (iter=1;iter<=iteracoes;iter++){
        for(a=0;a<li;a++){
            h=0;
            for(b=0;b<co;b++){
                h += (theta[b] * matriz[a][b]);
            }
            for(b=0;b<co;b++){
            theta[b] = theta[b] - (alfa * ((1.0/li)* ( matriz[a][b] * (h - y[a]))));
            }
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
