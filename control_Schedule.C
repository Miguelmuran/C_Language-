#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct agenda{
	int reg;
	char nome[80];
	float nota;
}agenda;

void aloca_usuario(agenda **ptr, int tam);
void cadastro_usuario(agenda *ptr, int tam);
void ver_cadastro(agenda *ptr, int tam);

int main(){
	
	agenda *p = NULL;
	int tam = 0, opcao;
	char op;
	
	
	
	printf("<PROGRAMA DE AGENDA CADASTRAL>\n\n");
	
	do{
		printf("\nDeseja continuar <S/N>: ");
		scanf(" %c", &op);
		fflush(stdin);
		
		if(op=='s' || op=='S'){
			
			
			printf("\nQUAL OPCAO DESEJA:\n");
			printf("[1] CADASTRAR\n");
			printf("[2] VER CADASTRO\n");
			scanf("%i", &opcao);
			fflush(stdin);
			
			switch(opcao){
				
				case 1:
				tam++;
				aloca_usuario(&p,tam);
				cadastro_usuario(p,tam);
				printf("\nUSUARIO CADASTRADO!\n");
				break;
				
				case 2:
				ver_cadastro(p,tam);
				break;
		
				default:
				printf("OPCAO INVALIDA...\n");
				break;
			}	
		}	
	}while(op!='n' && op!='N');
	
	return 0;
}

void aloca_usuario(agenda **ptr, int tam){
	
	if((*ptr=(agenda*)realloc(*ptr,tam*sizeof(tam)))==NULL){
		printf("ERRO DE ALOCAO!");
		exit(1);
	}
}

void cadastro_usuario(agenda *ptr, int tam){
	
	int i;
	
	static int reg_usuario = 1000;
	
	printf("\nDigite o nome: ");
	scanf("%s", &((ptr+tam)->nome));
	fflush(stdin);
	
	(ptr+tam)->reg = reg_usuario;
	reg_usuario++;
	
	printf("\nregistro: %i", (ptr+tam)->reg);
	
	printf("\n\nDigite uma nota:");
	scanf("%f", &((ptr+tam)->nota));
	fflush(stdin);
}

void ver_cadastro(agenda *ptr, int tam){
	
	int confere, i;
	int encontrado=0;
	
	
	printf("Digite o registro: ");
	scanf("%i", &confere);
	fflush(stdin);
		
	for(i=0; i<=tam; i++){
		
		if(confere==(ptr+i)->reg){
		
			printf("NOME: %s\n", (ptr+i)->nome);
			printf("NOTA: %.2f\n", (ptr+i)->nota);
			encontrado=1;
		}
	}
	if(!encontrado){
			printf("USUARIO NAO ENCONTRADO!");
	}	
}
