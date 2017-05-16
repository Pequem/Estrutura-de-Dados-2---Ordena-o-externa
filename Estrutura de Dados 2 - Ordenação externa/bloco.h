#ifndef BLOCO_H
#define BLOCO_H
#define n 3
#include <stdio.h>

typedef struct registro{
	char letter;
	int lixo[7];
}reg;

reg* ordenaBloco(reg*);

void intercala(FILE*, FILE*);


#endif