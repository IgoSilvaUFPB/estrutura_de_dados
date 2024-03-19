#include "lista.h"

using std::cout;
using std::endl;

Pilha* cria_pilha() {
	Pilha* p = (Pilha*)malloc(sizeof(Pilha));
	if (!p) {
		return NULL;
	}
	p->topo = NULL;
	return p;
}

Elemento* cria_elemento(int info) {
	Elemento* e = (Elemento*)malloc(sizeof(Elemento));
	if (!e) {
		return NULL;
	}
	e->info = info;
	e->prox = NULL;
	return e;
}

void libera_pilha(Pilha** p) {
	if (!(*p)) {
		return;
	}
	free((*p));
	*p = NULL;
}

bool empilha(Pilha* p, int info) {
	if (!p) {
		return false;
	}
	int t = tamanho_pilha(p);
	// caso pilha está cheia	
	if (t == _TAMANHO_PILHA_) {
		return false;
	}
	Elemento* e = cria_elemento(info);
	// caso pilha vazia
	if (p->topo == NULL) {
		p->topo = e;
		return true;
	}
	e->prox = p->topo;
	p->topo = e;
	return true;
}

bool desempilha(Pilha* p, int* info) {
	if (!p) {
		return false;
	}
	// caso pilha está vazia
	if (p->topo == NULL) {
		return false;
	}
	// armazena valor do topo
	*info = p->topo->info;
	// desempilha
	Elemento* aux = p->topo; 
	p->topo = p->topo->prox;
	free(aux);
	return true;
}

void imprime_pilha(Pilha* p) {
	if (!p) {
		return;
	}
	// caso pilha vazia
	if (p->topo == NULL) {
		return;
	}
	int t = tamanho_pilha(p);
	Elemento* aux = p->topo;
	// percorre pilha imprimindo
	for (int i = 0; i < t; i++) {
		cout << "[" << aux->info << "]";
		aux = aux->prox;
	}
	cout << endl;
}

int tamanho_pilha(Pilha* p) {
	if (!p) {
		return 0;
	}
	// caso pilha vazia
	if (p->topo == NULL) {
		return 0;
	}
	int count = 1;
	Elemento* aux = p->topo;
	while (aux->prox != NULL) {
		aux = aux->prox;
		count++;
	}
	return count;
}