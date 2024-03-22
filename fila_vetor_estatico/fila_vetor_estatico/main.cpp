#include "fila_vetor_estatico.h"
#include <iostream>

int main(void) {


	Fila* f = cria_fila();
	insere(f, 1);
	imprime(f);
	insere(f, 2);
	imprime(f);
	insere(f, 3);
	imprime(f);
	insere(f, 4);
	imprime(f);
	insere(f, 5);
	imprime(f);
	insere(f, 6);
	imprime(f);
	insere(f, 6);
	imprime(f);
	int info;
	// removendo elementos
	remove(f, &info);
	std::cout << "info: " << info << std::endl;
	imprime(f);
	remove(f, &info);
	std::cout << "info: " << info << std::endl;
	imprime(f);
	remove(f, &info);
	std::cout << "info: " << info << std::endl;
	imprime(f);
	// inserindo mais elementos
	insere(f, 6);
	imprime(f);
	insere(f, 7);
	imprime(f);
	libera_fila(&f);
	return 0;
}