#include <iostream>
#include "arvore_busca.h"



using std::cout;

Arvore* cria_arvore(int info) {
	Arvore* a = (Arvore*)malloc(sizeof(Arvore));
	if (!a) {
		return NULL;
	}
	a->info = info;
	a->esq = NULL;
	a->dir = NULL;
	return a;
}

void libera_arvore(Arvore** a) {
	if ((*a) == NULL) {
		return;
	}
	libera_arvore(&(*a)->esq);	
	libera_arvore(&(*a)->dir);	
	free((*a));
	*a = NULL;
}

bool insere_arvore(Arvore** a, int info) {
	if (!(*a)) { // caso árvore não exista
		Arvore* nova = cria_arvore(info);
		if (!nova) {
			return false;
		}
		(*a) = nova;
	}	
	if ((*a)->info == info) { // caso a info já exista na árvore
		return false;
	}
	if (info < (*a)->info) { // caso insira à esquerda
		return insere_arvore(&(*a)->esq, info);
	}
	else if (info > (*a)->info) { // caso insira à direita
		return insere_arvore(&(*a)->dir, info);
	}
	return true;
}

bool remove_arvore(Arvore* a, int info) {
	return false;
}

void imprime_pre(Arvore* a) {
	if (!a) {
		return;
	}
	cout << "[" << a->info << "]";
	imprime_pre(a->esq);
	imprime_pre(a->dir);
}

void imprime_pos(Arvore* a) {
	if (!a) {
		return;
	}
	imprime_pos(a->esq);
	imprime_pos(a->dir);
	cout << "[" << a->info << "]";	
}

void imprime_simetrico(Arvore* a) {
	if (!a) {
		return;
	}
	imprime_simetrico(a->esq);
	cout << "[" << a->info << "]";
	imprime_simetrico(a->dir);
}

Arvore* busca_arvore(Arvore* a, int info) {
	if (!a) {
		return NULL;
	}
	if (info < a->info) {
		return busca_arvore(a->esq, info);
	}
	else if (info > a->info) {
		return busca_arvore(a->dir, info);
	}
	return a;
}
