#include <iostream>
#include "arvore_busca.h"

using std::cout;
using std::endl;

int main(void) {
	// criando árvore
	Arvore* a = cria_arvore(10);
	// inserindo na árvore
	insere_arvore(&a, 5);
	insere_arvore(&a, 15);
	insere_arvore(&a, 3);
	insere_arvore(&a, 1);
	insere_arvore(&a, 11);
	insere_arvore(&a, 17);
	insere_arvore(&a, 7);
	insere_arvore(&a, 6);
	insere_arvore(&a, 9);
	insere_arvore(&a, 8);
	insere_arvore(&a, 2);
	insere_arvore(&a, 4);
	insere_arvore(&a, 14);
	insere_arvore(&a, 13);
	insere_arvore(&a, 16);
	// imprimindo árvore
	cout << "Impressao PRE:" << endl;
	imprime_pre(a);
	cout << endl << "Impressao POS:" << endl;
	imprime_pos(a);
	cout << endl << "Impressao SIMETRICA:" << endl;
	imprime_simetrico(a);
	cout << endl;
	// buscando na árvore
	Arvore* resultado = busca_arvore(a, 11);
	cout << endl << "Resultado da busca: " << resultado->info << endl;
	// removendo da árvore
	int removido;
	remove_arvore(&a, 15, &removido);
	cout << "Removido: " << removido << endl;
	// imprimindo após remoção
	imprime_pre(a);
	// liberando árvore
	libera_arvore(&a);
	return 0;
}