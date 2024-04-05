#include <stdio.h>
#include <stdlib.h>

void recebe_Vet(float *num1, float *num2, int tam);
float calcula_Vet(float *num1, float *num2, float *resultado, int tam);
void imprime_resultado(float *resultado, int tam);

int main(){
	
	int tam, i;
	float A[10], B[10];
	float resultado[10];
	
	do{
		
		printf("Digite o tamanho do vetor (max 10): ");
		scanf("%i", &tam);
		fflush(stdin);
		printf("\n");

	}while(tam<0 || tam>10);
	
	recebe_Vet(A,B,tam);
	calcula_Vet(A,B,resultado,tam);
	system("pause");
	system("cls");
	imprime_resultado(resultado, tam);

	
}

void recebe_Vet(float *num1, float *num2, int tam){
	
	int i;
	
	for(i=0; i<tam; i++){
		
		printf("\nDigite o o  vetor A[%i]: ", i);
		scanf("%f", (num1+i));
		fflush(stdin);

		printf("\nDigite o o  vetor B[%i]: ", i);
		scanf("%f", (num2+i));
		fflush(stdin);
	}
	
}

float calcula_Vet(float *num1, float *num2, float *resultado, int tam){
	
	int i;
	
	for(i=0; i<tam; i++){
		
		*(resultado+i) = *(num1+i) + *(num2+i);
	}
}

void imprime_resultado(float *resultado, int tam){
	
	int i;
	
	for(i=0; i<tam; i++){
		
		printf("\n\nValor de C[%i]: %.2f\n", i, *(resultado+i));
	}
}
