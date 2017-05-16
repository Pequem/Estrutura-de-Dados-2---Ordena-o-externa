#include "bloco.h"

reg* ordenaBloco(reg* registro) {
	int i, j;
	reg aux;
	for (i = 0; i < n-1; i++) {
		for (j = 0; j < n-1; j++) {
			if (registro[j].letter > registro[j + 1].letter) {
				aux = registro[j];
				registro[j] = registro[j + 1];
				registro[j] = aux;
			}
		}
	}
	return registro;
}

void intercala(FILE* arq1, FILE* arq2) {

}
