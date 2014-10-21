#include<omp.h>
#include<stdio.h>
#include<cstdlib>
#include<math.h>
#include<sys/time.h>
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
double dtime();
int main(){
    double tstart, tstop;
    importaArquivo();
    inicializaBetas();
printf("Valor para funcao de custo com beta igual a zero: %f\n",calculaFuncaoCusto());
    tstart=dtime();
    gradienteDescendente();
    tstop=dtime();
         printf("Tempo gasto com o gradiente descendente %f\n",(tstop-tstart));

    printf("Valores de beta: %f, %f %f\n",beta[0],beta[1], calculaFuncaoCusto());
  return 0;
}
void importaArquivo(){
FILE *arquivo;

if((arquivo = fopen("teste.txt","r")) == NULL)
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
        int i,j;

  #pragma omp parallel
  {
        #pragma omp for private (j,temp_beta)
 		for(i=0;i<iteracoes;i++){
		     	temp_beta[0]=0.0;
		     	temp_beta[1]=0.0;
		     	for(j=0;j<tam;j++){
                      temp_beta[0]=temp_beta[0]+(beta[0]+(beta[1]*entrada[j][1])-y[j]);
                      temp_beta[1]=temp_beta[1]+(beta[0]+(beta[1]*entrada[j][1])-y[j])*entrada[j][1];
		     	}
		     	#pragma omp critical

		        beta[0]=beta[0]-alfa * (1.0/tam) * temp_beta[0];
		        beta[1]=beta[1]-alfa * (1.0/tam) * temp_beta[1];
		        printf("%d %f\n", (i+1), calculaFuncaoCusto());

		}
  }
}
float calculaFuncaoCusto(){

    float custo=0;
		float h;
		int i,j;
   // #pragma offload target(mic) in(tam) in(entrada:length(size))
   #pragma omp parallel
  {

     	//	J=1/(2*m) * (sum(((X*theta)-y)^2));
      //  #pragma omp for  private (h,j)
      #pragma omp parallel for reduction(+:custo)
		for(i=0;i<tam;i++){
			h=0;
			for(j=0;j<totBetas;j++){
				h+=entrada[i][j]*beta[j];
			}
			//#pragma omp critical
			custo+=pow((h-y[i]),2);
		}
  }
		return ((1.0/(2*tam))*custo);

}
double dtime(){
      double tseconds =0.0;
      struct timeval mytime;
      gettimeofday(&mytime,(struct timezone*)0);
      tseconds =(double)(mytime.tv_sec + mytime.tv_usec*1.0e-6);
      return (tseconds);
}
