#include <iostream>
#include "combina.h"

using std::cout;
using std::endl;

int main(void) {
	Fila* f = cria_fila();
	entra_fila(f, 2.4);
	entra_fila(f, 6.1);
	entra_fila(f, 3.3);
	entra_fila(f, 8.2);
	entra_fila(f, 7.5);
	entra_fila(f, 9.6);
	imprime_fila(f);
	float valor = 0;
	sai_fila(f, &valor);
	cout << "Saiu da fila: " << valor << endl;
	imprime_fila(f);
	sai_fila(f, &valor);
	cout << "Saiu da fila: " << valor << endl;
	imprime_fila(f);
	Fila* z = cria_fila();
	entra_fila(z, 1.9);
	entra_fila(z, 5.3);
	imprime_fila(z);
	Fila* res = cria_fila();
	imprime_fila(res);
	combina_filas(res, f, z);
	imprime_fila(res);
	imprime_fila(f);
	imprime_fila(z);
	libera_fila(&f);
	libera_fila(&z);
	libera_fila(&res);
	return 0;
}