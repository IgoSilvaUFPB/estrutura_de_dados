#ifndef IMPLEMENTACOES_CPP
#define IMPLEMENTACOES_CPP

#include <iostream>
#include "prototipos.h"

using std::cout;
using std::endl;

Nnz* cria_nnz(int linha, int coluna, double info) {
	Nnz* n = new Nnz;
	if (!n) {
		return NULL;
	}
	n->linha = linha;
	n->coluna = coluna;
	n->info = info;
	n->prox = NULL;
	return n;
}

Linha* cria_linha(int linha) {
	Linha* l = new Linha;
	if (!l) {
		return NULL;
	}
	l->linha = linha;
	l->inicio = NULL;
	l->prox = NULL;
	return l;
}

Mesparsa* cria_mesparsa() {
	Mesparsa* m = new Mesparsa;
	if (!m) {
		return NULL;
	}
	m->inicio = NULL;
	return m;
}

//void libera_mesparsa(Mesparsa* matriz);

bool insere_nnz(Linha* l, int linha, int coluna, double info) {
	// caso linha vazia
	if (l->inicio == NULL) {
		Nnz* n = cria_nnz(linha, coluna, info); // cria nnz
		if (!n) { // verifica alocação
			delete(l); // destroi linha se alocação falhou
			return false;
		}
		l->inicio = n; // adiciona nnz a linha
		return true;
	}
	// insere no inicio para teste
	Nnz* n = cria_nnz(linha, coluna, info); // cria nnz
	if (!n) { // verifica alocação
		return false;
	}
	n->prox = l->inicio;
	l->inicio = n; // adiciona nnz a linha
	return true;
}

bool insere_linha(Mesparsa* matriz, int linha, int coluna, double info) {
	if (!matriz) {
		return false;
	}
	// caso matriz vazia
	if (matriz->inicio == NULL) {
		cout << "lista vazia" << endl;
		Linha* l = cria_linha(linha); // cria matriz
		matriz->inicio = l; // adiciona linha a matriz
		return insere_nnz(l, linha, coluna, info); // insere nnz na linha
	}
	// buscando posição da linha
	Linha* aux = matriz->inicio; // ponteiro para primeira linha
	while (aux->prox != NULL && aux->linha != linha && aux->prox->linha <= linha) {
		// buscando linha igual, limite, ou final
		aux = aux->prox;
	}
	// insere na primeira posição
	if (aux->linha > linha) {
		cout << "inseriu no inicio" << endl;
		Linha* l = cria_linha(linha);
		l->prox = aux;
		matriz->inicio = l;
		return insere_nnz(l, linha, coluna, info); // insere nnz na linha
	}
	// caso linha encontrada
	if (aux->linha == linha) {
		cout << "linha encontrada" << endl;
		return insere_nnz(aux, linha, coluna, info); // insere nnz na linha
	}
	// caso final da lista
	if (aux->prox == NULL) {
		cout << "final da lista" << endl;
		Linha* l = cria_linha(linha);
		aux->prox = l;
		return insere_nnz(l, linha, coluna, info); // insere nnz na linha
	}
	// caso limite insere após
	cout << "inseriu no meio" << endl;
	Linha* l = cria_linha(linha);
	l->prox = aux->prox;
	aux->prox = l;
	return insere_nnz(l, linha, coluna, info); // insere nnz na linha
}

//bool remove_nnz(Mesparsa* matriz, int linha, int coluna, double info);
//bool altera_nnz(Mesparsa* matriz, int linha, int coluna, double info, double novo);

void imprime_mesparsa(Mesparsa* matriz) {
	if (!matriz) {
		return;
	}
	// caso matriz vazia
	if (matriz->inicio == NULL) {
		return;
	}
	// imprime linha a linha
	Linha* aux = matriz->inicio;
	while (aux != NULL) {
		// caso linha vazia
		if (aux->inicio == NULL) {
			return;
		}
		Nnz* nnz = aux->inicio;
		while (nnz != NULL) {
			cout << "[(" << nnz->linha << ", " << nnz->coluna << ")=" << nnz->info << "]";
			nnz = nnz->prox;
		}
		cout << endl;
		aux = aux->prox;
	}
}

#endif