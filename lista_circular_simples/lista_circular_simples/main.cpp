#include <iostream>
#include "prototipos.h"

int main(void) {
	Listac* lc = cria_listac();
	insere_listac(lc, 2);
	imprime_listac(lc);
	insere_listac(lc, 4);
	imprime_listac(lc);
	insere_listac(lc, 6);
	imprime_listac(lc);
	insere_listac(lc, 8);
	imprime_listac(lc);
	insere_listac(lc, 10);
	imprime_listac(lc);
	insere_listac(lc, 12);
	imprime_listac(lc);
	remove_listac(lc, 4);
	imprime_listac(lc);
	modifica_listac(lc, 10, 11);
	imprime_listac(lc);
	return 0;
}