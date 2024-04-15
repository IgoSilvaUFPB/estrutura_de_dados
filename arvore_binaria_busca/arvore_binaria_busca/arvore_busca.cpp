#include <iostream>
#include "arvore_busca.h"

using std::cout;
using std::endl;

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
	if (!(*a)) { // caso �rvore n�o exista
		Arvore* nova = cria_arvore(info);
		if (!nova) {
			return false;
		}
		(*a) = nova;
	}	
	if ((*a)->info == info) { // caso a info j� exista na �rvore
		return false;
	}
	if (info < (*a)->info) { // caso insira � esquerda
		return insere_arvore(&(*a)->esq, info);
	}
	else if (info > (*a)->info) { // caso insira � direita
		return insere_arvore(&(*a)->dir, info);
	}
}

bool remove_arvore(Arvore** a, int info, int* deletado) {
	if (!(*a)) { // caso n�o encontrado, e fim da �rvore
		return false;
	}
	if ((*a)->info == info) { // caso encontrado
		*deletado = (*a)->info;
		if (!(*a)->esq && !(*a)->dir ) { // caso n�o haja sub�rvores			
			free((*a));
			*a = NULL;
			return true;
		}
		else if ((*a)->esq) { // remove o maior da sub�rvore a esquerda
			Arvore* aux = (*a)->esq;
			Arvore* aux2 = (*a)->esq;
			while (aux->dir != NULL) { // busca maior da sub�rvore a esquerda
				aux2 = aux;
				aux = aux->dir;
			}
			if (aux == aux2) { // caso s� tenha uma �rvore � esquerda
				(*a)->info = aux->info;
				(*a)->esq = NULL;
				free(aux);
				aux = NULL;
				return true;
			}
			if (aux->esq) { // caso o maior tenha sub�rvores a esquerda
				(*a)->info = aux->info;
				aux2->dir = aux->esq;
				free(aux);
				aux = NULL;
				return true;
			}
			else { // caso n�o tenha sub�rvores
				(*a)->info = aux->info;
				aux2->dir = NULL;
				free(aux);
				aux = NULL;
				return true;
			}
		}
		else { // remove o menor da sub�rvore a direita
			Arvore* aux = (*a)->dir;
			Arvore* aux2 = (*a)->dir;
			while (aux->esq != NULL) { // busca menor da sub�rvore a direita
				aux2 = aux;
				aux = aux->esq;
			}
			if (aux == aux2) { // caso s� tenha uma �rvore � esquerda
				(*a)->info = aux->info;
				(*a)->dir = NULL;
				free(aux);
				aux = NULL;
				return true;
			}
			if (aux->dir) { // caso o menor tenha sub�rvores a direita
				(*a)->info = aux->info;
				aux2->esq = aux->dir;
				free(aux);
				aux = NULL;
				return true;
			}
			else { // caso n�o tenha sub�rvores
				(*a)->info = aux->info;
				aux2->esq = NULL;
				free(aux);
				aux = NULL;
				return true;
			}
		}
	}
	if (info < (*a)->info) { // caso n�o encontrado, e menor
		return remove_arvore(&(*a)->esq, info, deletado);
	}
	else if (info > (*a)->info) { // caso n�o encontrado, e maior
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
