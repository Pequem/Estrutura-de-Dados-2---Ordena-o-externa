// Estrutura de Dados 2 - Ordenação externa.cpp : Define o ponto de entrada para a aplicação de console.
//
#include <stdlib.h>
#include <stdio.h>
#include "OrdenaExterno.h"

int cmpfunc(const void** a, const void** b)
{
	char **a1, **b1;
	a1 = (char**) a;
	b1 = (char**) b;
	return (**a1-**b1);
}


int main(int argc, char **argv)
{
	printf("Ordenando");
	OrdeneExterno("teste.txt", "final", 20, 1000, sizeof(char), cmpfunc);
	return 0;
}