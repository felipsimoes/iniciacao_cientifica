#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"
#define iteracoes 2000
#define alfa 0.1
int li,co,a,b,iter,k;
float valor, soma_total, maior, menor;
double **total, *theta, *erro_treino, *erro_teste, q, h, erro_medio_treino = 0, erro_medio_teste = 0;
double **matriz_treinamento, **matriz_teste, *y_treinamento, *y_teste, *theta_change, *gradiente;
void ImportarDados();
void ZerarThetas();
void InicializarVariaveisGradiente();
void NormalizarDados();
void GradienteDescendente();
double FuncaoCustoTrein();
double FuncaoCustoTeste();
void InicializarMatrizes();

int main(){

    InicializarMatrizes();
    InicializarVariaveisGradiente();

for(k=1;k<11;k++){
    ImportarDados();
    //NormalizarDados();
    printf("\nPara k: %d", k);
    printf("\nCusto inicial igual a : %f", FuncaoCustoTrein());
    GradienteDescendente();
    printf("\nCusto final igual a : %f", FuncaoCustoTrein());
    erro_treino[k-1] = FuncaoCustoTrein();
    erro_teste[k-1] = FuncaoCustoTeste();
    ZerarThetas();
}
    for(a=0;a<10;a++){
        erro_medio_treino = erro_medio_treino + erro_treino[a];
        erro_medio_teste = erro_medio_teste + erro_teste[a];
    }
    erro_medio_treino = erro_medio_treino/10;
    erro_medio_teste = erro_medio_teste/10;
    printf("\n\nErro medio de treinamento igual a : %f", erro_medio_treino);
    printf("\nErro medio de teste igual a : %f", erro_medio_teste);

    return 0;
}
void InicializarMatrizes(){
FILE *file;
erro_treino = (double*) malloc(10 * sizeof(double));
erro_teste = (double*) malloc(10 * sizeof(double));
file = fopen("testeNormalizado2.txt", "r");
    if(file == NULL) {
            printf("\nOcorreu um erro ao acessar este arquivo.\n");
            exit(1); }
fscanf(file, "%d %d", &li, &co);
fclose(file);
/**inicializar matrizes */
        matriz_treinamento = (double**) malloc((0.9 * li) * sizeof(double*));
        matriz_teste = (double**) malloc((0.1 * li) * sizeof(double*));
        y_treinamento = (double*) malloc((0.9 * li) * sizeof(double));
        y_teste = (double*) malloc((0.1 * li) * sizeof(double));
         for(a = 0; a < (0.9 * li); a++){
             matriz_treinamento[a] = (double*) malloc(co * sizeof(double));
             matriz_treinamento[a][0] = 1.0;
         }
         for(a = 0; a < (0.1 * li); a++){
             matriz_teste[a] = (double*) malloc(co * sizeof(double));
             matriz_teste[a][0] = 1.0;
         }
}

void ImportarDados(){
    FILE *file;
    int f, cont = 0;
    char pasta[30] = {};
    char num_pasta[5] = {};

        /**percorre pastas e carrega valores das matrizes */
        for(f = 1; f < 11; f++){
            strcpy(pasta,"folders/folder");
            sprintf(num_pasta,"%d",f);
            strcat(pasta,num_pasta);
            strcat(pasta, ".txt");

            /** armazena valores de teste */
            if(f==k){
            file = fopen(pasta, "r");
                for(a=0;a<(li*0.1);a++){
                    for(b = 1; b <= co; b++){
                        fscanf(file,"%f",&valor);
                        if(b == co){ y_teste[a] = valor; }
                        else { matriz_teste[a][b] = valor; }
                    }
                }
            fclose(file);
            }

            /** armazena valores de treinamento */
            else {
            file = fopen(pasta, "r");
                for(a=0;a<(li*0.1);a++){
                    for(b = 1; b <= co; b++){
                        fscanf(file,"%f",&valor);
                        if(b == co){ y_treinamento[cont] = valor; }
                        else { matriz_treinamento[cont][b] = valor; }
                    }
                cont++;
                }
            cont = cont -1;
            fclose(file);
            }
            strcpy(pasta,"");
        }
}

double FuncaoCustoTrein(){
        q = 0;
        for(a=0;a<(li*0.9);a++){
            h=0;
            for(b=0;b<co;b++){
                h += (theta[b] * matriz_treinamento[a][b]);
            }
            q += pow((h-y_treinamento[a]),2);
        }
        return ((1.0/(li)) * q);
}

double FuncaoCustoTeste(){
        q = 0;
        for(a=0;a<(li*0.1);a++){
            h=0;
            for(b=0;b<co;b++){
                h += (theta[b] * matriz_teste[a][b]);
            }
            q += pow((h-y_teste[a]),2);
        }
        return ((1.0/(li)) * q);
}

void InicializarVariaveisGradiente(){
        theta = (double*) malloc(co * sizeof(double));
        theta_change = (double*) malloc(co * sizeof(double));
        for(b=0;b<co;b++){
            theta[b]=0.0;
            theta_change[b]=0.0;
        }
        gradiente = (double*) malloc (co * sizeof(double));
}

void ZerarThetas(){
        for(b=0;b<co;b++){
            theta[b]=0.0;
            theta_change[b]=0.0;
        }
}

void GradienteDescendente(){
int linhas;
linhas = li*0.9;
    for (iter=1;iter<=iteracoes;iter++){
        for(a=0;a<linhas;a++){ //armazena hipoteses e erros por linhas
            h=0;
            for(b=0;b<co;b++){
                h += (theta[b] * matriz_treinamento[a][b]);
            }
            for(b=0;b<co;b++){
            theta[b] = theta[b] - (alfa * ((1.0/linhas)* ( matriz_treinamento[a][b] * (h - y_treinamento[a]))));
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
                maior = matriz_treinamento[0][b];
                menor = matriz_treinamento[0][b];
                soma_total = 0;
                for (a=0; a<li; a++){
                    soma_total = soma_total + matriz_treinamento[a][b];
                    if(matriz_treinamento[a][b] > maior){
                        maior = matriz_treinamento[a][b]; }
                    if(matriz_treinamento[a][b] < menor){
                        menor = matriz_treinamento[a][b]; }
                }
                total[0][b]= soma_total;
                total[1][b]= maior;
                total[2][b]= menor;
            }
        for(a=0;a<li;a++){
            for(b=1;b<co;b++){
                matriz_treinamento[a][b]=(matriz_treinamento[a][b]-total[2][b])/(total[1][b]-total[2][b]); }
        }
}
