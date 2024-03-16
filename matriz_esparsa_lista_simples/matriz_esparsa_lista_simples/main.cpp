#include <iostream>
#include "prototipos.h"

int main(void) {
	Mesparsa* matriz = cria_mesparsa();	
	insere_linha(matriz, 4, 3, 7.3);
	//insere_linha(matriz, 1, 3, 3.8);
	insere_linha(matriz, 7, 5, 1.4);
	insere_linha(matriz, 8, 1, 2.2);
	insere_linha(matriz, 4, 6, 6.7);
	insere_linha(matriz, 8, 2, 2.1);
	insere_linha(matriz, 4, 5, 5.5);
	insere_linha(matriz, 6, 5, 5.5);
	insere_linha(matriz, 1, 5, 5.1);
	imprime_mesparsa(matriz);

	return 0;
}