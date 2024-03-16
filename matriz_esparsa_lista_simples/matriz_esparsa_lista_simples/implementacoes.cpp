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

bool insere_na_linha(Linha* l, int linha, int coluna, double info) {
	// caso linha vazia
	if (l->inicio == NULL) {
		Nnz* n = cria_nnz(linha, coluna, info); // cria nnz
		if (!n) { // verifica aloca��o
			delete(l); // destroi linha se aloca��o falhou
			return false;
		}
		l->inicio = n; // adiciona nnz a linha
		return true;
	}
	// insere na primeira posicao
	if (l->inicio->coluna > coluna) {
		Nnz* n = cria_nnz(linha, coluna, info); // cria nnz
		if (!n) {
			return false;
		}
		n->prox = l->inicio;
		l->inicio = n;
		return true;
	}
	Nnz* aux2 = l->inicio;
	while (aux2->prox != NULL && aux2->prox->coluna < coluna) {
		aux2 = aux2->prox;
	}
	// insere no final
	if (aux2->prox == NULL) {
		Nnz* n = cria_nnz(linha, coluna, info); // cria nnz
		if (!n) {
			return false;
		}
		aux2->prox = n;
		return true;
	}
	// insere entre dois
	Nnz* n = cria_nnz(linha, coluna, info); // cria nnz
	if (!n) {
		return false;
	}
	n->prox = aux2->prox;
	aux2->prox = n;
	return true;
}

bool insere_nnz(Mesparsa* matriz, int linha, int coluna, double info) {
	if (!matriz) {
		return false;
	}
	// caso matriz vazia
	if (matriz->inicio == NULL) {
		Linha* l = cria_linha(linha); // cria matriz
		if (!l) {
			return false;
		}
		matriz->inicio = l; // adiciona linha a matriz
		return insere_na_linha(l, linha, coluna, info); // insere nnz na linha
	}
	// buscando posi��o da linha
	Linha* aux = matriz->inicio; // ponteiro para primeira linha
	while (aux->prox != NULL && aux->linha != linha && aux->prox->linha <= linha) {
		// buscando linha igual, limite, ou final
		aux = aux->prox;
	}
	// insere na primeira posi��o
	if (aux->linha > linha) {
		Linha* l = cria_linha(linha);
		if (!l) {
			return false;
		}
		l->prox = aux;
		matriz->inicio = l;
		return insere_na_linha(l, linha, coluna, info); // insere nnz na linha
	}
	// caso linha encontrada
	if (aux->linha == linha) {
		return insere_na_linha(aux, linha, coluna, info); // insere nnz na linha
	}
	// caso final da lista
	if (aux->prox == NULL) {
		Linha* l = cria_linha(linha);
		if (!l) {
			return false;
		}
		aux->prox = l;
		return insere_na_linha(l, linha, coluna, info); // insere nnz na linha
	}
	// caso limite insere ap�s
	Linha* l = cria_linha(linha);
	if (!l) {
		return false;
	}
	l->prox = aux->prox;
	aux->prox = l;
	return insere_na_linha(l, linha, coluna, info); // insere nnz na linha
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