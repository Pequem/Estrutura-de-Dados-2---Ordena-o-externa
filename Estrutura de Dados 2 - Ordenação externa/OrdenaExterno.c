#include "OrdenaExterno.h"

void AbreArqEntrada(ArqEntradaTipo* ArrArqEnt, int Low, int Lim)
{
	char name[10];
	int j = 0;
	for (int i = Low; i <= Lim; i++)
	{
		itoa(i, name, 10);
		ArrArqEnt[j] = fopen(name, "r+");
		j++;
	}
}

ArqEntradaTipo AbrirArquivoDeEntrada(char *arquivoNome) {
	return fopen(arquivoNome, "r+");
}

ArqEntradaTipo AbreArqSaida(int NBlocos) {
	char bloco[10];
	itoa(NBlocos, bloco, 10);
	return fopen(bloco, "w");
}

int EnchePaginas(int NBlocos, ArqEntradaTipo arquivo, void **Buffer, int *blocosLidos, int numRegistros, int tamReg) {
	int i;
	void *c;
	*blocosLidos = 0;
	for (i = 0; i < numRegistros; i++) {
		c = malloc(tamReg);
		fread(c, tamReg, 1, arquivo);
		if (feof(arquivo)) {
			Buffer[i] = NULL;
			free(c);
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

void DescarregaPaginas(ArqEntradaTipo ArqSaida, void **Buffer, int numRegistros, int tamReg) {
	int i;
	for (i = 0; i < numRegistros; i++) {
		if (Buffer[i] == NULL) return;
		fwrite(Buffer[i], tamReg, 1, ArqSaida);
		free(Buffer[i]);
	}
}

void* getMenorElemento(void **c, int tam, int *posicao, int(*callback)(void*, void*)) {
	int i = 0;
	void *menor;
	*posicao = 0;
	for (i = 0; i <= tam; i++) {
		if (c[i] == NULL) continue;
		menor = c[i];
		*posicao = i;
	}
	for (i = 0; i <= tam; i++) {
		if (c[i] == NULL) continue;
		if (callback(&menor, &c[i]) > 0) {
			menor = c[i];
			*posicao = i;
		}
	}
	c[*posicao] = NULL;
	return menor;
}

void Intercale(ArqEntradaTipo *ArrArqEnt, int Low, int Lim, ArqEntradaTipo ArqSaida, int OrdemIntercalacao, int tamReg, int(*callback)(void*, void*))
{
	char *a;

	const int tam = Lim - Low;
	int i, j, posicao;
	void *c1;
	void **c = malloc(sizeof(void*)*OrdemIntercalacao);
	int blocosFinalizados = 0;
	for (i = 0, j = 0 ; i <= tam; i++) {
		c1 = malloc(tamReg);
		fread(c1, tamReg, 1, ArrArqEnt[i]);
		c[j] = c1;
		j++;
	}
	do {
		c1 = getMenorElemento(c, tam, &posicao, callback);
		a = c1;
		fwrite(a, tamReg, 1, ArqSaida);
		fread(c1, tamReg, 1, ArrArqEnt[posicao]);
		if (feof(ArrArqEnt[posicao])) {
			blocosFinalizados++;
			free(c1);
		}
		else {
			c[posicao] = c1;
		}
	} while (blocosFinalizados != OrdemIntercalacao);
	free(c);
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

int verificaBufferVazio(void **buffer) {
	if (buffer[0] == NULL) {
		return true;
	}
	return false;
}

void OrdeneExterno(char *arquivo, char* arquivoFinal, int OrdemIntercalacao, int numRegistros, int tamReg, int(callback)(void*, void*)) {
	int NBlocos = 0;
	ArqEntradaTipo ArqEntrada, ArqSaida;
	ArqEntradaTipo *ArrArqEnt = (ArqEntradaTipo*) malloc(sizeof(ArqEntradaTipo)*OrdemIntercalacao);
	short Fim;
	int Low, High, Lim, nBlocosLidos = 0, i, j;
	void **buffer = malloc(sizeof(void*)*numRegistros);
	ArqEntrada = AbrirArquivoDeEntrada(arquivo);
	do   /*Formacao inicial dos NBlocos ordenados */
	{
		Fim = EnchePaginas(NBlocos, ArqEntrada, buffer, &nBlocosLidos, numRegistros, tamReg);
		if (verificaBufferVazio(buffer)) break;
		NBlocos++;
		qsort(buffer, nBlocosLidos, sizeof(void*), callback);
		ArqSaida = AbreArqSaida(NBlocos - 1);
		DescarregaPaginas(ArqSaida, buffer, numRegistros, tamReg);
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
		Intercale(ArrArqEnt, Low, Lim, ArqSaida, OrdemIntercalacao, tamReg, callback);
		fclose(ArqSaida);
		for (i = Low, j = 0; i <= Lim; i++, j++) {
			fclose(ArrArqEnt[j]);
			Apague_Arquivo(i);
		}
		Low += OrdemIntercalacao;
	}   //Mudar o nome do arquivo High para o nome fornecido pelo usuario;

	free(ArrArqEnt);
	free(buffer);

}
