#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void aloca(float **ptr, int tam);
void maior_temp(float *ptr, int tam, float *pmaior, int *pdia);
float calcula_media(float *ptr, int tam, float *media);
void inf_media(float *ptr, int tam, float *media);

int main(){
	
	float *p = NULL, maior;
	int tam=0, dia;
	char op;
	float media;
		
	do{
		
		aloca(&p,tam);
		maior_temp(p,tam,&maior,&dia);
			
		printf("Deseja continuar <S/N>: ");
		scanf(" %c", &op);
		
		if(op!='n' && op!='N'){
			tam++;
		}
	}while(op!='n' && op!='N');
	
	calcula_media(p,tam,&media);
	inf_media(p,tam,&media);
}

void aloca(float **ptr, int tam){
	
	if((*ptr=(float*)realloc(*ptr,(tam+1)*sizeof(float)))== NULL){
		printf("ERRO DE ALOCACAO!");
		exit(1);
	}
}

void maior_temp(float *ptr, int tam, float *pmaior, int *pdia){
	
	int i;
	
	printf("Insira as temperaturas abaixo:\n");
	
        printf("Dia[%i]: ", tam+1);
		scanf("%f", &(ptr+tam));
		
		if(tam==0 || *(ptr+tam) > *pmaior){
			
			*pmaior = ptr[tam];
			*pdia = tam+1;
			
		}
	  printf("Maior: %.2f -- Dia: %i\n", *pmaior, *pdia);
}

float calcula_media(float *ptr, int tam, float *media){
	
	int i;
	
	*media=0;
	
	for(i=0; i<tam; i++){
		
		*media += *(ptr+i);
	}
	
	 *media /= tam;
	
	printf("Valor da media: %.2f", *media);
}

void inf_media(float *ptr, int tam, float *media){
	
	int i;
	
	printf("\n\nDias com temperaturas menores que a media:\n ");
	
	for (i = 0; i < tam; i++) {
        
		if ((ptr+i) < *media) {
            printf("\n\nDia %d: %.2f\n", i + 1, *(ptr+i));
        }
    }
}
