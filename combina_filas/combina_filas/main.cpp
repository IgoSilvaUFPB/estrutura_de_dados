#include <iostream>
#include "combina_filas.h"

int main(void) {
	Fila* f1 = fila_cria();
	fila_insere(f1, 2.3);
	fila_insere(f1, 3.1);
	fila_insere(f1, 2.7);
	fila_insere(f1, 7.4);
	fila_insere(f1, 8.3);
	fila_insere(f1, 1.1);
	fila_insere(f1, 3.5);
	fila_insere(f1, 9.7);
	imprime_fila(f1);

	Fila* f2 = fila_cria();
	fila_insere(f2, 7.2);
	fila_insere(f2, 2.5);
	fila_insere(f2, 1.1);
	fila_insere(f2, 5.4);
	imprime_fila(f2);

	Fila* f_res = fila_cria();
	combina_filas(f_res, f1, f2);
	imprime_fila(f1);
	imprime_fila(f2);
	imprime_fila(f_res);

	float retirado = fila_retira(f_res);
	std::cout << "Saiu da fila: " << retirado << std::endl;
	imprime_fila(f_res);

	fila_libera(&f1);
	fila_libera(&f2);
	fila_libera(&f_res);
	return 0;
}