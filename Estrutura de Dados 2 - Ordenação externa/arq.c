#include "arq.h"
#include <stdlib.h>

FILE* openFile(char* file) {
	FILE* fileArq = fopen(file, "r");

	return fileArq;
}

reg* readBloco(FILE* file, int *eof) {
	reg* registro;

	for (int i = 0; i < n; i++)
	{
		if (sizeof(reg) == fread(&registro[i], sizeof(reg), 1, file)) {
			*eof = 1;
			return registro;
		}
	}

	return registro;

}

char* readLetters(FILE* file, int *eof) {
	char* letter;
	letter = (char*) malloc(sizeof(char)*n);

	for (int i = 0; i < n; i++)
	{
		if (sizeof(char) == fread(&letter[i], sizeof(char), 1, file)) {
			*eof = 1;
			return letter;
		}
	}

	return letter;
}

void writeBloco(FILE* file, reg* registro) {
	for (int i = 0; i < n; i++)
	{
		fwrite(&registro[i], sizeof(reg), 1, file);
	}

	return;
}

void writeBloco(FILE* file, char* letter) {
	for (int i = 0; i < n; i++)
	{
		fwrite(&letter[i], sizeof(char), 1, file);
	}

	return;
}

reg readReg(FILE* file) {
	reg registro;

	fread(&registro, sizeof(reg), 1, file);

	return registro;
}

void writeReg(FILE* file, reg* registro) {
	fwrite(registro, sizeof(reg), 1, file);
}