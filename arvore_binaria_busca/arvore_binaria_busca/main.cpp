#include <iostream>
#include "arvore_busca.h"

using std::cout;
using std::endl;

int main(void) {
	Arvore* a = cria_arvore(10);
	insere_arvore(&a, 5);
	insere_arvore(&a, 15);
	insere_arvore(&a, 1);
	insere_arvore(&a, 11);
	insere_arvore(&a, 17);
	insere_arvore(&a, 7);
	cout << "Impressao PRE:" << endl;
	imprime_pre(a);
	cout << endl << "Impressao POS:" << endl;
	imprime_pos(a);
	cout << endl << "Impressao SIMETRICA:" << endl;
	imprime_simetrico(a);
	cout << endl;
	Arvore* resultado = busca_arvore(a, 11);
	cout << endl << "Resultado da busca: " << resultado->info << endl;
	libera_arvore(&a);
	return 0;
}