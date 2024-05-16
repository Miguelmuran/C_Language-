#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aluno{
char nome[80];
char RA[7];
float nota[2]; 
float media; 
};

void cadastro_Aluno(struct aluno alunos[], int total_aluno);
void controle_Aluno(struct aluno alunos[], int total_aluno);

int main(){
	
	int op, total_aluno = 0;
	struct aluno alunos[10];
	
	printf("<PROGRAMA ESCOLAR>\n");
	printf("<SEJA BEM-VINDO>\n");
	
	do{
		printf("\nDigite a opcao que deseja realizar:\n\n");
		printf("[1] Cadastro\n");
		printf("[2] Controle de Notas\n");
		printf("[3] Fechar programa\n");
		scanf("%i", &op);
		
		switch (op){
			
			case 1:
			cadastro_Aluno(alunos,total_aluno);
			total_aluno++;
			break;
			
			case 2:
			controle_Aluno(alunos,total_aluno);
			break;
			
			case 3:
			printf("SAINDO...");
			break;
		}
		
	}while(op!=3);
}

void cadastro_Aluno(struct aluno alunos[], int total_aluno){
	
	if(total_aluno<10){
		
		printf("\nDigite seu nome: ");
		scanf("%s", &(alunos[total_aluno].nome));
		fflush(stdin);
		printf("\nDigite seu RA estudantil: ");
		scanf("%s", &(alunos[total_aluno].RA));
		fflush(stdin);
		printf("\nDigite a primeira nota: ");
		scanf("%f", &(alunos[total_aluno].nota[0]));
		fflush(stdin);
		printf("\nDigte a segunda nota: ");
		scanf("%f", &(alunos[total_aluno].nota[1]));
		fflush(stdin);
	}
}

void controle_Aluno(struct aluno alunos[], int total_aluno){
	
	int i;
	char confere[7];
	
	printf("<Controle de Notas>\n");
	printf("\nDigite seu RA para entrar: ");
	scanf("%s", &confere);
	
	for(i=0; i<total_aluno; i++){
		
		if(strcmp(alunos[i].RA,confere)==0){

			printf("\nNome: %s\n", alunos[i].nome);
			printf("\nNota 1: %.2f\n", alunos[i].nota[0]);
			printf("\nNota 2: %.2f\n", alunos[i].nota[1]);
			
			printf("\n<Calculo Das medias aritimetricas>\n");
			
			alunos[i].media = (alunos[i].nota[0]+alunos[i].nota[1])/2;
			
			printf("\nMedia do %s eh: %.2f\n\n", alunos[i].nome, alunos[i].media);

      if(alunos[i].media > 6){
				printf("\nAluno Aprovado!\n\n");
			}
			
			else{
				printf("\nAluno Reprovado!\n\n");
			}
		}
	}
} 
