#include<stdio.h>
#include<cstdlib>
#include<math.h>
#define totBetas 2
#define tam 97
#define iteracoes 2000
#define alfa 0.01
float entrada[tam][totBetas];
float beta[totBetas];
float y[tam];
void importaArquivo();
void inicializaBetas();
void gradienteDescendente();
float calculaFuncaoCusto();
int main(){

    importaArquivo();
    inicializaBetas();
    printf("Valor para funcao de custo com beta igual a zero: %f\n",calculaFuncaoCusto());
    gradienteDescendente();
    printf("Valores de beta: %f, %f\n",beta[0],beta[1]);
  return 0;
}
void importaArquivo(){
FILE *arquivo;

if((arquivo = fopen("ex1data1.txt","r")) == NULL)
  {
    printf("Erro ao abrir arquivo!!!\n");
    exit(1);
  }


  float attr1,attr2;
  int result, tot=0;
  int i=0,j=0;
  while( (fscanf(arquivo,"%f %f \n", &attr1, &attr2))!=EOF ){
	        tot++;
	        entrada[i][j]=1;
	        entrada[i][j+1]=attr1;
	        y[i]=attr2;
	 	//	printf("%f %f %f\n", entrada[i][j], entrada[i][j+1], y[i]);
	        i++;
  }
 // printf("Total de registros importados: %d\n",tot);
  fclose(arquivo);

}

void inicializaBetas(){
    for(int i=0;i<totBetas;i++){
           beta[i]=0.0;
    }
}

void gradienteDescendente(){
        float temp_beta[2];
		for(int i=0;i<iteracoes;i++){
		     	temp_beta[0]=0.0;
		     	temp_beta[1]=0.0;
		     	for(int j=0;j<tam;j++){
                      temp_beta[0]=temp_beta[0]+(beta[0]+(beta[1]*entrada[j][1])-y[j]);
                      temp_beta[1]=temp_beta[1]+(beta[0]+(beta[1]*entrada[j][1])-y[j])*entrada[j][1];
		     	}
		        beta[0]=beta[0]-alfa * (1.0/tam) * temp_beta[0];
		        beta[1]=beta[1]-alfa * (1.0/tam) * temp_beta[1];
		        printf("%d %f\n", (i+1), calculaFuncaoCusto());

		}
}
float calculaFuncaoCusto(){
     	//	J=1/(2*m) * (sum(((X*theta)-y)^2));
		float custo=0;
		float h;
		for(int i=0;i<tam;i++){
			h=0;
			for(int j=0;j<totBetas;j++){
				h+=entrada[i][j]*beta[j];
			}
			custo+=pow((h-y[i]),2);
		}
		return ((1.0/(2*tam))*custo);
	}
