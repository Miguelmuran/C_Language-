#include <stdio.h>
#include <stdlib.h>

void recebe_Temp(float *temp, int tam);
void maior_Temp(float *temp, int tam);
float media_Temp(float *temp, int tam);
int inf_Temp(float *temp, int tam, float media, int *posicao);
void imprime_inf(float *temp, int *posicao, int quantidade);

int main(){
	
	int tam, pos_inf[30], qntd;
	float T[30];
	float media;
	
	printf("Programa de dados meteriologicos.\n\n");
	system("pause");
	printf("\n");
	
	do{
		
		printf("Digite quantos dias do mes voce quer registrar a temperatura(max 30 dias): ");
		scanf("%i", &tam);
		fflush(stdin);
		
	}while(tam<0 || tam>30);

	recebe_Temp(T,tam);
	maior_Temp(T,tam);
	media = media_Temp(T,tam); 
	qntd = inf_Temp(T,tam,media,pos_inf);
	imprime_inf(T,pos_inf,qntd);
	
	return 0;
}

void recebe_Temp(float *temp, int tam){
	
	int i;
	
	printf("Digite a temperatura:\n");
	
	for(i=0; i<tam; i++){
		
		printf("Dia[%i]: ", i+1);
		scanf("%f", &temp[i]);
		fflush(stdin);
	}
}

void maior_Temp(float *temp, int tam){
	
	float maior;
	int i, dia;
	
	maior = temp[0];
	dia = 1;
	
	for(i=1; i<tam; i++){
		
		if(maior < temp[i]){
			
			maior = temp[i];
			dia = i+1;		
		}
	}
	printf("\n");
	printf("A maior temperatura ocorreu no dia %i e foi %.2f°\n", dia, maior);
}

float media_Temp(float *temp, int tam){
	
	int i;
	float media = 0;
	
	for(i=0; i<tam; i++){
		
		media += temp[i];
	}
	
	media = media/tam;
	
	printf("\n");
	printf("A media das temperaturas eh: %.2f°\n", media);
	return media;
}

int inf_Temp(float *temp, int tam, float media, int *posicao){
	
	int i,j=0;
	
	for(i=0; i<tam; i++){
		
		if(temp[i] < media){
			
			posicao[j] = i;
			j++;
		}	
	}
	return j;
}

void imprime_inf(float *temp, int *posicao, int quantidade){
	
	int i;
	
	printf("\nTemperaturas inferiores a media:\n");
	
	for(i=0; i<quantidade; i++){
		
		printf("\nDia %i - temperatura foi de %.2f\n", posicao[i]+1, temp[posicao[i]]);
	}
}
