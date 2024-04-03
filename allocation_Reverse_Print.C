#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void aloca(float **ptr, int tam);
void recebe_valor(float *ptr, int *tam);
void imprime_inverso(float *ptr, int tam);

int main(){
	
	float *p = NULL;
	int tam=0;
	char op;
	
	aloca(&p,tam+1);
	recebe_valor(p,&tam);
	imprime_inverso(p,tam);	
	
}

void aloca(float **ptr, int tam){
	
	if((*ptr = (float*)realloc(*ptr, tam*sizeof(float)))==NULL){
		printf("ERRO DE ALOCACAO!");
		exit(1);
	}
}

void recebe_valor(float *ptr, int *tam){
	
	char op;
	
	printf("Digite os valores dos vetores: ");
	
	do{
		printf("\n\nvetor[%i]: ",*tam);
		scanf("%f", &ptr[*tam]);	
		fflush(stdin);
		
		printf("\nDeseja continuar <S/N>: ");
		scanf(" %c", &op);
		fflush(stdin);
		
		if(op!='n' && op!='N'){
			(*tam)++;
		}	
	}while(op!='n' && op!='N');
}

void imprime_inverso(float *ptr, int tam){
	
	int i;
	
	for(i=tam-1; i>=0; i--){
		printf("endereço: %i - Valor: %.2f\n\n", (void*)(ptr+i), *(ptr+i));
	}
}
