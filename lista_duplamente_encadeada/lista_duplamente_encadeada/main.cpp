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
	insere_fim(ld, 8);
	insere_inicio(ld, 111);
	imprime_lista(ld);
	altera_info(ld, 8, 18);
	imprime_lista(ld);
	altera_info(ld, 2, 23);
	altera_info(ld, 4, 45);
	imprime_lista(ld);
	std::cout << "fim";
	return 0;
}