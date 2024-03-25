#include "fila_lista_simples.h"
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	Fila* f = cria_fila();
	entra_na_fila(f, 7);
	entra_na_fila(f, 4);
	entra_na_fila(f, 1);
	entra_na_fila(f, 5);
	entra_na_fila(f, 3);
	imprime_fila(f);
	cout << "Tamanho da fila: " << tamanho_da_fila(f) << endl;
	int e;
	sai_da_fila(f, &e);
	imprime_fila(f);
	cout << "Tamanho da fila: " << tamanho_da_fila(f) << endl;
	cout << "Saiu da fila: " << e << endl;
	sai_da_fila(f, &e);
	imprime_fila(f);
	cout << "Tamanho da fila: " << tamanho_da_fila(f) << endl;
	cout << "Saiu da fila: " << e << endl;
	entra_na_fila(f, 9);
	entra_na_fila(f, 6);
	entra_na_fila(f, 8);
	imprime_fila(f);
	cout << "Tamanho da fila: " << tamanho_da_fila(f) << endl;
	libera_fila(&f);
	return 0;
}