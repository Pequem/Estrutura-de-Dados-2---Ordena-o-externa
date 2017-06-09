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
	//teste2222
	ramdomReg("teste1.bin", 20);
	clock_t start = clock();
	OrdeneExterno("teste1.bin", "final.bin", 2, 262144, sizeof(Reg), cmpFuncReg, NULL, NULL);
	clock_t end = clock();
	printf("%f",(float) (end - start)/CLOCKS_PER_SEC );
	_CrtDumpMemoryLeaks();
	return 0;
}
