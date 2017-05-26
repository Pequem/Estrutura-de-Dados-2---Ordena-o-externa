// Estrutura de Dados 2 - Ordena��o externa.cpp : Define o ponto de entrada para a aplica��o de console.
//
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <stdio.h>
#include "OrdenaExterno.h"
#include "FuncoesAux.h"

int main(int argc, char **argv)
{
	//teste
	ramdomReg("teste1.bin", 16);
	OrdeneExterno("teste1.bin", "final.bin", 5, 50, sizeof(Reg), cmpFuncReg, NULL, NULL);
	_CrtDumpMemoryLeaks();
	return 0;
}
