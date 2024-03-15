#include <iostream>
#include "prototipos.h"

int main(void) {
	Listacd* l = cria_listacd();
	insere_listacd(l, 5);
	imprime_listacd(l);
	insere_listacd(l, 10);
	imprime_listacd(l);
	insere_listacd(l, 15);
	imprime_listacd(l);
	insere_listacd(l, 4);
	imprime_listacd(l);
	insere_listacd(l, 22);
	imprime_listacd(l);
	insere_listacd(l, 45);
	imprime_listacd(l);
	remove_listacd(l, 4);
	imprime_listacd(l);
	remove_listacd(l, 5);
	imprime_listacd(l);
	remove_listacd(l, 22);
	imprime_listacd(l);
	altera_listacd(l, 15, 16);
	imprime_listacd(l);
	altera_listacd(l, 10, 11);
	imprime_listacd(l);
	altera_listacd(l, 45, 46);
	imprime_listacd(l);
	libera_listacd(&l);
	return 0;
}