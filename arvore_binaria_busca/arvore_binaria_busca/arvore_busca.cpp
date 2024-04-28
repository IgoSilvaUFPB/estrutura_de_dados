#include <iostream>
#include "arvore_busca.h"

using std::cout;
using std::endl;

struct arvore {
	int info;
	struct arvore* esq;
	struct arvore* dir;
};

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
}

bool remove_arvore(Arvore** a, int info, int* deletado) {
	if (!(*a)) { // caso não encontrado, e fim da árvore
		return false;
	}
	if ((*a)->info == info) { // caso encontrado
		*deletado = (*a)->info;
		if (!(*a)->esq && !(*a)->dir) { // caso não haja subárvores			
			free((*a));
			*a = NULL;
			return true;
		}
		else if ((*a)->esq) { // remove o maior da subárvore a esquerda
			Arvore* aux = (*a)->esq;
			Arvore* aux2 = (*a)->esq;
			while (aux->dir != NULL) { // busca maior da subárvore a esquerda
				aux2 = aux;
				aux = aux->dir;
			}
			if (aux == aux2) { // caso só tenha uma árvore à esquerda
				(*a)->info = aux->info;
				(*a)->esq = NULL;
				free(aux);
				aux = NULL;
				return true;
			}
			if (aux->esq) { // caso o maior tenha subárvores a esquerda
				(*a)->info = aux->info;
				aux2->dir = aux->esq;
				free(aux);
				aux = NULL;
				return true;
			}
			else { // caso não tenha subárvores
				(*a)->info = aux->info;
				aux2->dir = NULL;
				free(aux);
				aux = NULL;
				return true;
			}
		}
		else { // remove o menor da subárvore a direita
			Arvore* aux = (*a)->dir;
			Arvore* aux2 = (*a)->dir;
			while (aux->esq != NULL) { // busca menor da subárvore a direita
				aux2 = aux;
				aux = aux->esq;
			}
			if (aux == aux2) { // caso só tenha uma árvore à esquerda
				(*a)->info = aux->info;
				(*a)->dir = NULL;
				free(aux);
				aux = NULL;
				return true;
			}
			if (aux->dir) { // caso o menor tenha subárvores a direita
				(*a)->info = aux->info;
				aux2->esq = aux->dir;
				free(aux);
				aux = NULL;
				return true;
			}
			else { // caso não tenha subárvores
				(*a)->info = aux->info;
				aux2->esq = NULL;
				free(aux);
				aux = NULL;
				return true;
			}
		}
	}
	if (info < (*a)->info) { // caso não encontrado, e menor
		return remove_arvore(&(*a)->esq, info, deletado);
	}
	else if (info > (*a)->info) { // caso não encontrado, e maior
		return remove_arvore(&(*a)->dir, info, deletado);
	}
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

int get_info(Arvore* a) {
	return a->info;
}
