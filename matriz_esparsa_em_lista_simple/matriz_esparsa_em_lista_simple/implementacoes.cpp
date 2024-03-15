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

bool insere_nnz(Mesparsa* matriz, int linha, int coluna, double info) {
	if (!matriz) {
		return false;
	}
	// caso matriz vazia
	if (matriz->inicio == NULL) {
		// aloca linha
		Linha* l = cria_linha(linha);
		if (!l) {
			return false;
		}
		Nnz* n = cria_nnz(linha, coluna, info);
		if (!n) {
			delete(l);
			return false;
		}
		// insere nnz
		matriz->inicio = l;
		l->inicio = n;
		return true;
	}
	// busca linha correspondente
	Linha* aux = matriz->inicio;
	while (aux->linha != linha && aux->prox != NULL) {
		aux = aux->prox;
	}
	
	// caso encontrado na última linha
	if (aux->prox == NULL && aux->linha == linha) {
		Nnz* n = cria_nnz(linha, coluna, info);
		if (!n) {
			return false;
		}
		// caso linha vazia
		if (aux->inicio == NULL) {			
			n->prox = aux->inicio;
			aux->inicio = n;
			return true;
		}
		// insere no primeiro da linha
		if (aux->inicio->coluna > coluna) {
			n->prox = aux->inicio->prox;
			aux->inicio->prox = n;
			return true;
		}
		Nnz* aux2 = aux->inicio;
		while (aux2->prox->coluna < coluna && aux2->prox != NULL) {
			aux2 = aux2->prox;
		}
		n->prox = aux2->prox;
		aux2->prox = n;
		return true;
	}
	// caso não encontrado nem na última
	if (aux->prox == NULL && aux->linha != linha) {
		Linha* l = cria_linha(linha);
		if (!l) {
			return false;
		}
		Nnz* n = cria_nnz(linha, coluna, info);
		if (!n) {
			delete(l);
			return false;
		}
		aux->prox = l;
		aux->prox->inicio = n;
		return true;
	}
	// caso linha encontrada
	Nnz* n = cria_nnz(linha, coluna, info);
	if (!n) {
		return false;
	}
	if (aux->inicio == NULL) {
		n->prox = aux->inicio;
		aux->inicio = n;
		return true;
	}
	if (aux->inicio->coluna > coluna) {
		n->prox = aux->inicio;
		aux->inicio = n;
		return true;
	}
	Nnz* aux2 = aux->inicio;
	while (aux2->prox != NULL && aux2->prox->coluna < coluna) {
		aux2 = aux2->prox;
	}
	n->prox = aux2->prox;
	aux2->prox = n;
	return true;	
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