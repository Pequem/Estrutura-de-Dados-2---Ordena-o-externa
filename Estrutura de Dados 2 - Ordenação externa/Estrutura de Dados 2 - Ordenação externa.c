// Estrutura de Dados 2 - Ordenação externa.cpp : Define o ponto de entrada para a aplicação de console.
//
#include "arq.h";
#include "bloco.h"
#define numRegistros 3

void OrdeneExterno(char*);

typedef FILE* ArqEntradaTipo;

int main(int argc, char **argv)
{
	OrdeneExterno(argv[1]);
	return 0;
}

ArqEntradaTipo AbrirArquivoDeEntrada(char *arquivoNome) {
	ArqEntradaTipo arquivo;
	arquivo = fopen(arquivoNome, "r+");
	if (arquivo) {

	}
	return arquivo;
}

int EnchePaginas(int NBlocos, ArqEntradaTipo arquivo, char *Buffer) {
	int i;
	for (i = 0; i < numRegistros; i++) {
		Buffer[i] = fscanf(arquivo, "%c");
		if (Buffer[i] == EOF) {
			return true;
		}
	}
	return false;
}

ArqEntradaTipo AbreArqSaida(int NBlocos) {
	char bloco[2];
	bloco[0] = NBlocos;
	bloco[1] = '\0';
	return fopen(bloco, "w");
}

void DescarregaPaginas(ArqEntradaTipo ArqSaida, char *Buffer) {
	int i;
	for (i = 0; i < numRegistros; i++) {
		if (Buffer[i] == EOF) return;;
		fprintf(ArqSaida, "%c", &Buffer[i]);
	}
}

void OrdeneExterno(char *arquivo) {
	const int OrdemIntercalacao = 2;
	int NBlocos = 0;
	ArqEntradaTipo ArqEntrada, ArqSaida;
	ArqEntradaTipo ArrArqEnt[OrdemIntercalacao];
	short Fim;
	int Low, High, Lim;
	char buffer[numRegistros];
	NBlocos = 0;
	ArqEntrada = AbrirArquivoDeEntrada(arquivo);
	do   /*Formacao inicial dos NBlocos ordenados */
	{
		NBlocos++;
		Fim = EnchePaginas(NBlocos, ArqEntrada, buffer);
		//OrdeneInterno;
		ArqSaida = AbreArqSaida(NBlocos);
		DescarregaPaginas(ArqSaida, buffer);
		fclose(ArqSaida);
	} while (!Fim);
	fclose(ArqEntrada);
	Low = 0;
	High = NBlocos - 1;
	//while (Low < High) /* Intercalacao dos NBlocos ordenados */
	//{
	//	Lim = Minimo(Low + OrdemIntercalacao - 1, High);
	//	AbreArqEntrada(ArrArqEnt, Low, Lim);
	//	High++;
	//	ArqSaida = AbreArqSaida(High);
	//	Intercale(ArrArqEnt, Low, Lim, ArqSaida);
	//	fclose(ArqSaida);
	//	for (i = Low; i < Lim; i++) {
	//		fclose(ArrArqEnt[i]);
	//		Apague_Arquivo(ArrArqEnt[i]);
	//	}
	//	Low += OrdemIntercalacao;
	//}   Mudar o nome do arquivo High para o nome fornecido pelo usuario;

}
