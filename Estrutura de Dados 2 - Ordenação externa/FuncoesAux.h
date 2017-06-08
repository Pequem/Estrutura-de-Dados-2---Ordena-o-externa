#ifndef FUNCOESAUX_H_
#define FUNCOESAUX_H_

typedef struct {
	char chave;
	char lixo[27];
}Reg;

int cmpFuncReg(const void **a, const void **b);
int cmpFuncChar(const void** a, const void** b);
int cmpFuncInt(const void **a, const void **b);

void ramdomReg(char *name, int n);
void ramdomInt(char *name, int n);

void printInt();

#endif