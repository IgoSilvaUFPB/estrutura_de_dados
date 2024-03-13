#include <iostream>
#include "prototipos.h"

int main(void) {
	Listad* ld = cria_listad();
	insere_inicio(ld, 3);
	insere_inicio(ld, 2);
	insere_inicio(ld, 1);
	insere_fim(ld, 4);
	insere_meio(ld, 7, 2);
	insere_meio(ld, 7, 0);
	insere_meio(ld, 7, 5);
	imprime_lista(ld);
	remove_info(ld, 7);
	imprime_lista(ld);
	remove_info(ld, 7);
	imprime_lista(ld);
	remove_info(ld, 7);
	imprime_lista(ld);
	return 0;
}