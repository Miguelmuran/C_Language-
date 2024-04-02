#include <stdio.h>
#include <stdlib.h>

void recebe_Nota(float notas[0][2], int tam);
float calcula_Media(float notas[0][2], float *media, int tam);
void imprime_media(float *media, int tam);

int main(){
	
	int tam;
	float nota[40][2];
	float resultado[40];
	
	do{
		printf("Digite o total de alunos na sala(max 40): ");
		scanf("%i", &tam);
		
	}while(tam<0 || tam>40);
	
	recebe_nota(nota,tam);
	system("pause");
	system("cls");
	
	calcula_Media(nota, resultado,tam);
	imprime_media(resultado,tam);	
}

void recebe_nota(float notas[][2], int tam){
	
	int i, j;
	
	for(i=0; i<tam; i++){
		for(j=0; j<2; j++){
		
			printf("\nDigite a nota %i do aluno %i:", j+1, i+1);
			scanf("%f", &notas[i][j]);
		}
	}
}

float calcula_Media(float notas[][2], float *media, int tam){
	
	int i,j;
	
	for(i=0; i<tam; i++){	
			
		media[i] = (notas[i][0] + notas[i][1])/2.0;
	}
}

void imprime_media(float *media, int tam){
	
	int i;
	
	for(i=0; i<tam; i++){
		
		printf("\nMedia do aluno %i: %.2f", i+1, media[i]);
	
	
	if(media[i]>7){
		printf("\nAPROVADO!");
	}
	
	else if(media[i]>4 && media[i]<7){
		printf("\nRECUPERACAO!");
	}
	
	else if(media[i]<4){
		printf("REPROVADO!");
	}
  }
}
