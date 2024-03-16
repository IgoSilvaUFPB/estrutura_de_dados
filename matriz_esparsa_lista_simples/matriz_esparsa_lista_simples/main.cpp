#include <iostream>
#include "prototipos.h"

using std::cout;
using std::endl;

int main(void) {
	Mesparsa* matriz = cria_mesparsa();
	cout << "iniciando insercoes..." << endl;
	insere_nnz(matriz, 4, 3, 7.3);
	insere_nnz(matriz, 1, 3, 3.8);
	insere_nnz(matriz, 7, 5, 1.4);
	insere_nnz(matriz, 8, 1, 2.2);
	insere_nnz(matriz, 4, 6, 6.7);
	insere_nnz(matriz, 8, 2, 2.1);
	insere_nnz(matriz, 4, 5, 5.5);
	insere_nnz(matriz, 6, 5, 5.5);
	insere_nnz(matriz, 1, 5, 5.1);
	insere_nnz(matriz, 4, 1, 9.9);
	insere_nnz(matriz, 8, 5, 5.2);
	insere_nnz(matriz, 4, 4, 7.7);
	insere_nnz(matriz, 6, 3, 1.3);
	insere_nnz(matriz, 7, 8, 5.8);
	imprime_mesparsa(matriz);
	cout << "iniciando remocoes..." << endl;
	remove_nnz(matriz, 4, 3);
	remove_nnz(matriz, 8, 5);
	remove_nnz(matriz, 8, 1);
	remove_nnz(matriz, 1, 3);
	imprime_mesparsa(matriz);
	libera_mesparsa(&matriz);
	return 0;
}