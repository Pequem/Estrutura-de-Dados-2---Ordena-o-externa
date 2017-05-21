// Estrutura de Dados 2 - Ordenação externa.cpp : Define o ponto de entrada para a aplicação de console.
//
#include <stdlib.h>
#include <stdio.h>
#include "OrdenaExterno.h"

int cmpfunc(const void** a, const void** b)
{
	char **a1, **b1;
	a1 = a;
	b1 = b;
	return (**a1-**b1);
}

void criaArquivoTeste() {
	FILE *f;
	unsigned long long i, j;
	char aux;
	i = pow(2, 2);
	f = fopen("teste.txt", "w+");
	for (j = 0; j < i; j++) {
		aux = rand() * 254;
		fwrite(&aux, sizeof(char), 1, f);
	}
	fclose(f);
}

int main(int argc, char **argv)
{
	printf("Criando arquivo de teste");
	//criaArquivoTeste();
	printf("Ordenando");
	OrdeneExterno("teste.txt", "final", 7, 2, sizeof(char), cmpfunc);
	return 0;
}