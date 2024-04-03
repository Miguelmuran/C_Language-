#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void aloca_programa(float **p, int tam);
float somar_vetor(float *p, int tam);

int main(){
	
	float *ptr = NULL;
	int tam=0;
	char op;
	
	do{
		aloca_programa(&ptr,tam+1);
		
		printf("Digite o valor do vetor: ");
		scanf("%f", &ptr[tam]);
		fflush(stdin);
		
		printf("Deseja continuar (S/N): ");
		scanf("%c", &op);
		fflush(stdin);
		
		if(op!='n' || op!='N'){
			tam++;
		}
	
	}while(op!='n' && op!='N');
	
	somar_vetor(ptr,tam);
}

void aloca_programa(float **p, int tam){
	
	if((*p=(float*)realloc(*p, tam*sizeof(float)))==NULL){
		exit(1);
	}
}

float somar_vetor(float *p, int tam){
	
	int i; 
	float soma[80];
	
	for(i=0; i<tam; i++){
		soma[i] = p[i]+30;
		printf("Valor final: %.2f\n", soma[i]);
	}	
}
