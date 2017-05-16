#pragma once
#ifndef ARQ_H
#define ARQ_H	
#include <stdio.h>
#include "arq.h"
#include "bloco.h";

FILE* openFile(char*);

reg* readBloco(FILE*, int*);

void writeBloco(FILE*, reg*);

reg readReg(FILE*);

void writeReg(FILE*, reg*);

#endif