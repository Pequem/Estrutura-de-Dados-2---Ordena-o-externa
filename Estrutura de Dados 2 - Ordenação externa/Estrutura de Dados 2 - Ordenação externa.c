// Estrutura de Dados 2 - Ordenação externa.cpp : Define o ponto de entrada para a aplicação de console.
//
#include "arq.h"
#include "bloco.h"
#include <stdlib.h>
#define numRegistros 3
#define true 1
#define false 0
#define OrdemIntercalacao 2

void OrdeneExterno(char*);

typedef FILE* ArqEntradaTipo;

int main(int argc, char **argv)
{
	OrdeneExterno("teste.txt");
	return 0;
}

void AbreArqEntrada(ArqEntradaTipo* ArrArqEnt, int Low, int Lim)
{
	char name[10];
	int j = 0;
	for (int i = Low; i <= Lim; i++)
	{
		itoa(i, name, 10);
		ArrArqEnt[j] = fopen(name , "r+");
		j++;
	}
}

int cmpfunc (const void* a, const void* b)
{
   return ( *(char*)a - *(char*)b );
}

ArqEntradaTipo AbrirArquivoDeEntrada(char *arquivoNome) {
	return fopen(arquivoNome, "r+");
}

int EnchePaginas(int NBlocos, ArqEntradaTipo arquivo, char *Buffer, int *blocosLidos) {
	int i;
	char c;
	*blocosLidos = 0;
	for (i = 0; i < numRegistros; i++) {
		fread(&c, sizeof(char), 1, arquivo);
		if (feof(arquivo)) {
			Buffer[i] = '\0';
			return true;
		}
		Buffer[i] = c;
		(*blocosLidos)++;
	}
	if (feof(arquivo)) {
		return true;
	}
	return false;
}

ArqEntradaTipo AbreArqSaida(int NBlocos) {
	char bloco[10];
	itoa(NBlocos, bloco, 10);
	return fopen(bloco, "w");
}

void DescarregaPaginas(ArqEntradaTipo ArqSaida, char *Buffer) {
	int i;
	char c;
	for (i = 0; i < numRegistros; i++) {
		if (Buffer[i] == '\0') return;
		c = Buffer[i];
		fprintf(ArqSaida, "%c", c);
	}
}

char getMenorElemento(char *c, int tam, int *posicao) {
	int i = 0;
	//utilizar null;
	char menor = 127;
	for (i = 0; i <= tam; i++) {
		if (menor > c[i]) {
			menor = c[i];
			*posicao = i;
		}
	}
	c[*posicao] = 127;
	return menor;
}

void Intercale(ArqEntradaTipo *ArrArqEnt, int Low, int Lim, ArqEntradaTipo ArqSaida)
{
	const int tam = Lim - Low;
	int i, j = 0, posicao;
	char c[OrdemIntercalacao], c1;
	int blocosFinalizados = 0;
	for (i = 0; i <= tam; i++) {
		fread(&c1, sizeof(char), 1, ArrArqEnt[i]);
		c[j] = c1;
		j++;
	}
	do{
		c1 = getMenorElemento(c, tam, &posicao);
		fwrite(&c1, sizeof(char), 1, ArqSaida);
		fread(&c1, sizeof(char), 1, ArrArqEnt[posicao]);
		if (feof(ArrArqEnt[posicao])) {
			blocosFinalizados++;
		}
		else {
			c[posicao] = c1;
		}
	}while (blocosFinalizados != OrdemIntercalacao);
}

int Minimo(int Low, int High)
{
	if (Low > High)
	{
		return High;
	}
	return Low;
}

void Apague_Arquivo(int i) {
	char name[10];
	itoa(i, name, 10);
	remove(name);
}

void OrdeneExterno(char *arquivo) {
	//int OrdemIntercalacao = 2; movido para definições
	int NBlocos = 0;
	ArqEntradaTipo ArqEntrada, ArqSaida;
	ArqEntradaTipo ArrArqEnt[OrdemIntercalacao];
	short Fim;
	int Low, High, Lim, blocosLidos = 0, i, j;
	char buffer[numRegistros];
	ArqEntrada = AbrirArquivoDeEntrada(arquivo);
	do   /*Formacao inicial dos NBlocos ordenados */
	{
		Fim = EnchePaginas(NBlocos, ArqEntrada, buffer, &blocosLidos);
		if (buffer[0] == '\0') break;
		NBlocos++;
		qsort(buffer, blocosLidos, sizeof(char), cmpfunc);
		ArqSaida = AbreArqSaida(NBlocos - 1);
		DescarregaPaginas(ArqSaida, buffer);
		fclose(ArqSaida);
	} while (!Fim);
	fclose(ArqEntrada);
	Low = 0;
	High = NBlocos - 1;
	while (Low < High) /* Intercalacao dos NBlocos ordenados */
	{
		Lim = Minimo(Low + OrdemIntercalacao - 1, High);
		AbreArqEntrada(ArrArqEnt, Low, Lim);
		High++;
		ArqSaida = AbreArqSaida(High);
		Intercale(ArrArqEnt, Low, Lim, ArqSaida);
		fclose(ArqSaida);
		for (i = Low, j = 0; i <= Lim; i++ , j++) {
			fclose(ArrArqEnt[j]);
			Apague_Arquivo(i);
		}
		Low += OrdemIntercalacao;
	}   //Mudar o nome do arquivo High para o nome fornecido pelo usuario;

}



