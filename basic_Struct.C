#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct livro{
	
	char nome[100];
	char autor[100];
	float valor;
};

struct grupo{
	
	struct livro gibi;
	struct livro manga;
};

int main(){
	
	struct grupo grupo1;
	
	printf("\nDigite o nome do gibi: ");
	scanf("%s", &(grupo1.gibi.nome));
	fflush(stdin);
	
	printf("\nDigite o nome do autor do gibi: ");
	scanf("%s", &(grupo1.gibi.autor));
	fflush(stdin);
	
	printf("\nDigite o valor do gibi: ");
	scanf("%f", &(grupo1.gibi.valor));
	fflush(stdin);
	
	printf("\nNome do gibi: %s\n", grupo1.gibi.nome);
	printf("\nAutor do gibi: %s\n", grupo1.gibi.autor);
	printf("\nValor do gibi: %.2f\n", grupo1.gibi.valor);
	
	printf("\nDigite o nome do manga: ");
	scanf("%s", &(grupo1.manga.nome));
	fflush(stdin);
	
	printf("\nDigite o nome do autor do manga: ");
	scanf("%s", &(grupo1.manga.autor));
	fflush(stdin);
	
	printf("\nDigite o valor do manga: ");
	scanf("%f", &(grupo1.manga.valor));
	fflush(stdin);
	
	printf("\nNome do manga: %s\n", grupo1.manga.nome);
	printf("\nAutor do manga: %s\n", grupo1.manga.autor);
	printf("\nValor do manga: %.2f\n", grupo1.manga.valor);
}
