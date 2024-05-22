#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct hospede{
	int quarto;			
	char nome[80];
	int acompanhante;		
	char categoria;		
	int dias;		
}hospede;

typedef struct quarto{
	int num;			
	char categoria;	
	char status;			
}quarto;

void aloca_hospede(hospede **pth, int tam);
void aloca_quarto(quarto **ptq, int tam);
void cadastra_quarto(quarto *ptq, int tam);
void cadastra_hospede(hospede *pth, quarto *ptq);
int busca_quarto(quarto *ptq, char categ);
void check_out(hospede *pth, int tam, quarto *ptq);
int busca_vago(hospede *pth, int tam, int q);

int main(){
	
	hospede *ph=NULL;
	quarto *pq=NULL;
	int tam=0, opcao,posicao;
	
	aloca_quarto(&pq,15);
	cadastra_quarto(pq,15);
	
	printf("<PROGRAMA DE HOSPEDAGEM>\n");
	printf("<SEJA BEM-VINDO>\n\n");
	system("pause");
	
	do{
		system("cls");
		printf("DIGITE UMA DAS OPCOES ABAIXO:\n\n");
		printf("[1] Check-in\n");
		printf("[2] Check-out\n");
		printf("[3] Sair\n");
		printf("OPCAO: ");
		scanf("%i", &opcao);
		fflush(stdin);
		
		switch(opcao){
			
			case 1:
			posicao=busca_vago(ph,tam,-1);
			if(posicao==-1){	
				aloca_hospede(&ph,tam+1);
				posicao=tam;
				tam++;
				}
			cadastra_hospede(ph+posicao,pq); //cadastra o hospede com os dados dele na posicao de memoria do quarto.
			break;
			
			case 2:
			check_out(ph,tam,pq);
			break;
			
			case 3:
			printf("SAINDO...");
			break;		
		}
	}while(opcao!=3);
}

void aloca_hospede(hospede **pth, int tam){
	if((*pth=(hospede*)realloc(*pth,tam*sizeof(hospede)))==NULL){
		printf("ERRO DE ALOCACAO!");
		exit(1);
	}
}

void aloca_quarto(quarto **ptq, int tam){
	if((*ptq=(quarto*)realloc(*ptq,tam*sizeof(quarto)))==NULL){
		printf("ERRO DE ALOCAO");
		exit(1);
	}
}

void cadastra_quarto(quarto *ptq, int tam){
	
	int i;
	
	for(i=0; i<tam; i++){
		(ptq+i)->num = i+1;
		(ptq+i)->status='L';
		
		if(i<5){
			(ptq+i)->categoria='S';
		}
		else{
			(ptq+i)->categoria='F';
		}
	}
}

void cadastra_hospede(hospede *pth, quarto *ptq){
	
	int qpessoas, num_quarto;
	char categ;
	
	do{
		printf("QUANTOS ACOMPANHANTES <MAX 4>: ");
		scanf("%i", &qpessoas);
		fflush(stdin);
	}while(qpessoas<1 || qpessoas>4);
	
	if(qpessoas==1){
		categ='S';
	}
	else if(qpessoas>1){
		categ='F';
	}
	num_quarto=busca_quarto(ptq,categ); //Atribui o numero do quarto.
	
	if(num_quarto==-1){
		printf("\nNAO HA QUARTOS LIVRES!\n");
	}
	
	else{
		
		pth->quarto=num_quarto;
		pth->acompanhante=qpessoas-1;
		
		printf("\nDIGITE O NOME: ");
		scanf("%s", &(pth->nome));
		fflush(stdin);
		
		printf("\nQUANTOS DIAS IRA SE HOSPEDAR: ");
		scanf("%i", &(pth->dias));
		fflush(stdin);
		
		printf("\n\nCADASTRO REALIZADO!\n\n");
		printf("\nNUMERO DO QUARTO:%i\n", pth->quarto);
	}
	system("pause");
}

int busca_quarto (quarto *ptq, char categ){
	
	int i;
	
	for(i=0; i<15; i++){
		
		if((ptq+i)->categoria==categ && (ptq+i)->status=='L'){
			(ptq+i)->status = 'O';  //Mudou para ocupado.
			return ((ptq+i)->num);
		}
	}
	return -1;
}

void check_out(hospede *pth, int tam, quarto *ptq){
	
	int num_quarto, i;
	
	printf("\nDIGITE QUAL SEU QUARTO\n");
	printf("QUARTO: ");
	scanf("%i", &num_quarto);
	fflush(stdin);
	
	(ptq+num_quarto-1)->status='L';
	
	for(i=0; i<tam; i++){
		if((pth+i)->quarto==num_quarto){
			
			printf("\nNOME: %s\n", (pth+i)->nome);
			
			if((pth+i)->acompanhante==0){
				printf("\nTOTAL A PAGAR: %.2f\n", (pth+i)->dias*85);
			}
			else if((pth+i)->acompanhante>0){
				printf("\nTOTAL A PAGAR: %.2f\n", (pth+i)->dias*(((pth+i)->acompanhante)+1)*45);
			}
			system("pause");
			(pth+i)->quarto=-1;
		}
	}	
}

int busca_vago(hospede *pth, int tam, int q){
	
	int i;
	
	for(i=0; i<tam; i++){
		if((pth+i)->quarto==q){
			
			return i;        //esse i esta retornando o numero do quarto.
		}
	}
	return -1;
}
