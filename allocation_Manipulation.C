#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void aloca(float **ptr, int tam);
void recebe_valor(float *ptr, int *tam);
void imprime_inverso(float *ptr, int tam);
float calcula_media(float *ptr, int tam);

int main(){
	
	float *p = NULL;
	int tam=0;
	char op;
	
	aloca(&p,tam+1);
	
  recebe_valor(p,&tam);
	
  imprime_inverso(p,tam);
  system("pause");
  system("cls");
	
  calcula_media(p,tam);
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
		scanf("%f", (ptr + *tam));	
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
	
	for(i=tam; i>=0; i--){
		printf("endereco: %i - Valor: %.2f\n\n", (ptr+i), *(ptr+i));
	}
}

float calcula_media(float *ptr, int tam){
	
	int i;
	float media;
	
	for(i=0; i<tam; i++){
		
		media += *(ptr+i);
	}
	media = media/tam;
	
	printf("\nValor da media eh: %.2f", media);
}
