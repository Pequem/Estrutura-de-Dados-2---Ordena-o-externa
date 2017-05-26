// Estrutura de Dados 2 - Ordena��o externa.cpp : Define o ponto de entrada para a aplica��o de console.
//
#include <stdlib.h>
#include <stdio.h>
#include "OrdenaExterno.h"

typedef struct {
	int chave;
	char lixo[27];
}Reg;

int cmpfuncchar(const void** a, const void** b)
{
	char **a1, **b1;
	a1 = (char**) a;
	b1 = (char**) b;
	return (**a1-**b1);
}

int cmpfuncreg(const void **a, const void **b) {
	Reg **a1, **b1;
	a1 = a;
	b1 = b;
	return (**a1).chave - (**b1).chave;
}

int cmpfuncint(const void **a, const void **b) {
	int **a1, **b1;
	a1 = a;
	b1 = b;
	return (**a1) - (**b1);
}

void ramdomreg(char *name, int n) {
	int i, j, valor = 2;
	for (i = 1; i < n; i++) {
		valor = valor * 2;
	}
	Reg aux;
	FILE *f;
	f = fopen(name, "w");

	for (i = 0; i < valor; i++) {
		aux.chave = rand();
		for (j = 0; j < 27; j++) {
			aux.lixo[j] = rand();
		}
		fwrite(&aux, sizeof(Reg), 1, f);
	}
	fclose(f);
}

void ramdomint(char *name, int n) {
	int i, valor = 2;
	for (i = 1; i < n; i++) {
		valor = valor * 2;
	}
	int aux;
	FILE *f;
	f = fopen(name, "w");
	srand(1);
	for (i = 0; i < valor; i++) {
		aux = rand();
		fwrite(&aux, sizeof(int), 1, f);
	}
	fclose(f);
}

int printint() {
	FILE *f;
	int x;
	f = fopen("43690", "r");
	do {
		fread(&x, sizeof(int), 1, f);
		printf("%i\n", x);
	} while (!feof(f));
}

int main(int argc, char **argv)
{
	//ramdomreg("teste1.bin", 16);
	OrdeneExterno("teste1.bin", "final", 5, 50, sizeof(Reg), cmpfuncreg);
	return 0;
}
