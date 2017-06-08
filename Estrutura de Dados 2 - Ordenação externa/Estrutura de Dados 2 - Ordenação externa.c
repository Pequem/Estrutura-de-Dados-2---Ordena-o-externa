// Estrutura de Dados 2 - Ordena��o externa.cpp : Define o ponto de entrada para a aplica��o de console.
//
//#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
//#include <crtdbg.h>
#include <stdio.h>
#include "OrdenaExterno.h"
#include "FuncoesAux.h"
#include <time.h>

void* ler(FILE *arquivo) {
	Reg *c = malloc(sizeof(Reg));
	if (arquivo) {
		do {
			fscanf(arquivo, "%c", &(c->chave));
			if (feof(arquivo)) {
				free(c);
			}
		} while (c->chave == '\n' || c->chave == '\r');
	}
	return c;
}

void escreve(FILE *arquivo, void* reg) {
	Reg *aux = reg;
	if (arquivo) {
		fprintf(arquivo, "%c\n", aux->chave);
	}
}

void ramdomRegTexto(char *name, int n) {
	int i, j, valor = 2;
	for (i = 1; i < n; i++) {
		valor = valor * 2;
	}
	char aux;
	FILE *f;
	f = fopen(name, "w");

	for (i = 0; i < valor; i++) {
		do {
			aux = rand();
		} while ((aux == '\n') || (aux == '\r'));
		fprintf(f, "%c\n", aux);
	}
	fclose(f);
}

int main(int argc, char **argv)
{
	//ramdomReg("teste1.bin", 16);
	int i;
	clock_t start, end;
	//for(i = 10; i < 30; i += 2){
		ramdomReg("teste.bin", 20);
		start = clock();
		OrdeneExterno("teste.bin", "final.bin", 2, 1048576, sizeof(Reg), cmpFuncReg, ler, escreve);
		end = clock();
		printf("i:%f\n", (float)(end - start) / CLOCKS_PER_SEC);
	//}
	//_CrtDumpMemoryLeaks();
	return 0;
}
