#ifndef ORDERNAEXTERNO_H_
#define ORDERNAEXTERNO_H_

#include <stdio.h>

typedef FILE* ArqEntradaTipo;
#define true 1
#define false 0

void OrdeneExterno(char* arquivo, char* arquivoFinal, int OrdemDeIntercalacao, int numRegistros, int tamReg,int(*callback)(void*, void*));

#endif
