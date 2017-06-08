// Estrutura de Dados 2 - Ordena��o externa.cpp : Define o ponto de entrada para a aplica��o de console.
//
//#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
//#include <crtdbg.h>
#include <stdio.h>
#include "OrdenaExterno.h"
#include "FuncoesAux.h"
#include <time.h>

int main(int argc, char **argv)
{
	int f, e;
	printf("m/4\n");
	for (f = 2; f <= 4; f++)
	{
		for (e = 20; e <= 22; e++)
		{
			ramdomReg("teste1.bin", e);
			clock_t start = clock();
			OrdeneExterno("teste1.bin", "final.bin", f, pow(2, e) / 4, sizeof(Reg), cmpFuncReg, NULL, NULL);
			clock_t end = clock();
			float seconds = (float)(end - start) / CLOCKS_PER_SEC;
			printf("f = %d, 2^%d: %f seconds\n", f, e, seconds);
		}
	}

	printf("m/16\n");
	for (f = 2; f <= 4; f++)
	{
		for (e = 20; e <= 22; e++)
		{
			ramdomReg("teste1.bin", e);
			clock_t start = clock();
			OrdeneExterno("teste1.bin", "final.bin", f, pow(2, e) / 16, sizeof(Reg), cmpFuncReg, NULL, NULL);
			clock_t end = clock();
			float seconds = (float)(end - start) / CLOCKS_PER_SEC;
			printf("f = %d, 2^%d: %f seconds\n", f, e, seconds);
		}
	}

	printf("m/256\n");
	for (f = 2; f <= 4; f++)
	{
		for (e = 20; e <= 22; e++)
		{
			ramdomReg("teste1.bin", e);
			clock_t start = clock();
			OrdeneExterno("teste1.bin", "final.bin", f, pow(2, e) / 256, sizeof(Reg), cmpFuncReg, NULL, NULL);
			clock_t end = clock();
			float seconds = (float)(end - start) / CLOCKS_PER_SEC;
			printf("f = %d, 2^%d: %f seconds\n", f, e, seconds);
		}
	}

	system("pause");
	return 0;
}
