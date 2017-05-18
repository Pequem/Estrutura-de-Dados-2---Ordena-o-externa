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

int main(int argc, char **argv)
{
	OrdeneExterno("teste.txt", "final", 2, 3, sizeof(char), cmpfunc);
	return 0;
}