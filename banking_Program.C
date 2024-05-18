#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cliente{
	char nome[30];
	int conta;
	float saldo;
}cliente;

void aloca_usuario(cliente **ptr, int tam);
void cadastra_usuario(cliente *ptr, int tam);
void deposito_usuario(cliente *ptr, int tam);
void retirada_usuario(cliente *ptr, int tam);

int main(){
	
	int opcao, tam = 0;
	cliente *p=NULL;
	char op;
	
	printf("PROGRAMA DE CONTA BANCARIA!\n");
	printf("BEM-VINDO!\n");
	
	do{
		printf("\nDeseja continuar <S/N>:");
		scanf(" %c", &op);
		
		if(op!='n' && op!='N'){
				
			printf("\nDigite uma opcao:\n");
			printf("[1] Cadastro\n");
			printf("[2] Deposito\n");
			printf("[3] Retirada\n");
			scanf("%i", &opcao);
			fflush(stdin);
			
			switch(opcao){
				
				case 1:
				tam++;
				aloca_usuario(&p,tam);
				cadastra_usuario(p,tam-1);
				break;
				
				case 2:
				deposito_usuario(p,tam);
				break;
				
				case 3: 
				retirada_usuario(p,tam);
				break;
				
				default:
				printf("\nOPCAO INVALIDA!\n");
			}
		}
		
	}while(op!='n' && op!='N');
}

void aloca_usuario(cliente **ptr, int tam){
	
	if((*ptr=(cliente*)realloc(*ptr,tam*sizeof(cliente)))==NULL){
		printf("ERRO DE ALOCACAO!");
		exit(1);
	}
}

void cadastra_usuario(cliente *ptr, int tam){
	
	static int chave_usuario = 21;
	
	printf("\nDIGITE SEU NOME: ");
	scanf("%s", &((ptr+tam)->nome));
	fflush(stdin);
	
	(ptr+tam)->conta=chave_usuario;
	chave_usuario++;
	
	printf("\nCHAVE DE ACESSO: %i\n", (ptr+tam)->conta);
	
	printf("\nDIGITE O SALDO INICIAL: ");
	scanf("%f", &((ptr+tam)->saldo));
	fflush(stdin);
	
	printf("\nCliente cadastrado!\n");
}

void deposito_usuario(cliente *ptr, int tam){
	
	int confere, i;
	float deposito;
	
	printf("\nCHAVE DE ACESSO: ");
	scanf("%i", &confere);
	fflush(stdin);
	
	for(i=0; i<tam; i++){
		if(confere==(ptr+i)->conta){
			
			printf("\nCONTA ENCONTRADA!\n");
			
			printf("\n\nNOME: %s\n", (ptr+i)->nome);
			printf("\nSALDO: %.2f\n", (ptr+i)->saldo);
			
			printf("\nQuanto deseja depositar?\n");
			printf("DEPOSITO: ");
			scanf("%f", &deposito);
			
			(ptr+i)->saldo+=deposito;
			
			printf("\nSALDO ATUAL DO %s: %.2f\n", (ptr+i)->nome, (ptr+i)->saldo);
		}
	}
}

void retirada_usuario(cliente *ptr, int tam){
	
	int confere, i;
	float retirada;
	
	printf("CHAVE DE ACESSO: ");
	scanf("%i", &confere);
	
	for(i=0; i<tam; i++){
		if(confere==(ptr+i)->conta){
			
			printf("\nCONTA ENCONTRADA!\n");
			
			printf("\nNOME: %s\n", (ptr+i)->nome);
			printf("\nSALDO: %.2f\n", (ptr+i)->saldo);
			
			printf("\nQuanto deseja retirar?\n");
			printf("RETIRADA: ");
			scanf("%f", &retirada);
			
			if(retirada < (ptr+i)->saldo){
				(ptr+i)->saldo-=retirada;
				
				printf("\nSALDO ATUAL DE %s: %.2f\n", (ptr+i)->nome, (ptr+i)->saldo);
			}
			else if(retirada > (ptr+i)->saldo){
				printf("\nSALDO INSUFICIENTE\n");
			}
		}
	}
}
