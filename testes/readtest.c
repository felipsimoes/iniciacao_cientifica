#include "stdio.h"
#include "stdlib.h"

main(){
FILE *file;
float a,b;

file = fopen("BaseDeDados.txt","r");
fscanf(file, "%f",&a);
fscanf(file, "%f",&b);
printf("%f %f",a,b);
fclose(file);

}
