#include <iostream>
#include "prototipos.h"

int main(void) {
	Mesparsa* matriz = cria_mesparsa();
	insere_nnz(matriz, 1, 5, 5.1);
	insere_nnz(matriz, 4, 3, 7.3);
	insere_nnz(matriz, 1, 3, 3.8);
	insere_nnz(matriz, 3, 5, 1.4);
	insere_nnz(matriz, 1, 1, 2.2);
	insere_nnz(matriz, 1, 6, 6.7);
	insere_nnz(matriz, 4, 2, 2.1);
	insere_nnz(matriz, 4, 5, 5.5);
	imprime_mesparsa(matriz);

	return 0;
}