#include "stdio.h"
#include "stdlib.h"
#include "math.h"

int li,co,a,b,iter;
float valor, soma_total, maior, menor;
double **total, *theta, *erro, q, h;
double **matriz, *y, **nova;
void ImportarDados();
void NormalizarDados();
void EscreveDados();

int main(){
int x;
    ImportarDados();
    NormalizarDados();

   for(a=0;a<li;a++){
        for(b=1; b<co;b++){
            if(b==1 || b==2 || b==3){
            nova[a][b] = matriz[a][b];
            }
            else if(b>6 && b<27){
                nova[a][b-3] = matriz[a][b];
            }
        }
    }
     /* for(a=1;a<2;a++){
        for(b =1; b<(co-6);b++){
            //if(b!=4 && b!=5 && b!=6 && b!=27 && b!=28 && b!=29){
            printf("%f ", nova[a][b]);
            //}
        }
        printf("\n");
    } */
    EscreveDados();
    return 0;
}

void ImportarDados(){
    FILE *file;

    file = fopen("teste.txt", "r");
    if(file == NULL) {
            printf("\nOcorreu um erro ao acessar este arquivo.\n");
            exit(1); }
    fscanf(file, "%d %d", &li, &co);
    matriz = (double**) malloc(li * sizeof(double*));
    nova = (double**) malloc(li * sizeof(double*));
    y = (double*) malloc(li * sizeof(double));
     for(a = 0; a < li; a++){
         matriz[a] = (double*) malloc(co * sizeof(double));
         matriz[a][0] = 1.0;
         nova[a] = (double*) malloc((co-6) * sizeof(double));
         nova[a][0] = 1.0;
          for(b = 1; b <= co; b++){
            fscanf(file,"%f",&valor);
                if(b == co){ y[a] = valor; }
                else { matriz[a][b] = valor; }
            }
            for(b=1;b<(co-6);b++){
                nova[a][b]=1.0;
            }
    }
    fclose(file);
}

void NormalizarDados(){
        total = (double**) malloc(3 * sizeof(double*));
        for(a=0;a<3;a++){
            total[a] = (double*) malloc(co * sizeof(double));
            for(b=0;b<co;b++){
                total[a][b]= 0.0;
            }
        }
            for (b=1; b<co; b++){
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
                if( b !=4 && b != 5 && b != 27 && b != 28 && b != 29) {
                    matriz[a][b]=(matriz[a][b]-total[2][b])/(total[1][b]-total[2][b]);
                }
            }
        }
}

void EscreveDados(){
FILE *file;
co = co - 6;
    file = fopen("baseNormalizada.txt", "w");
    for(a=0;a<li;a++){
        for(b=1;b<=co;b++){
            if(b == co){
                fprintf(file,"%f\n",y[a]);
            }
            else {
            fprintf(file, "%f ", nova[a][b]);
            }
        }
    }
    fclose(file);
}
