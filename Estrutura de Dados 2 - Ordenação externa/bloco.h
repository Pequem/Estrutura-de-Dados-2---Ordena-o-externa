#pragma once
#ifndef BLOCO_H
#define BLOCO_H
#define n 3
#include <stdio.h>

struct r{
	char letter;
	int lixo[7];
};

typedef r reg;

reg* ordenaBloco(reg*);

void intercala(FILE*, FILE*);


#endif