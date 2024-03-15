#ifndef IMPLEMENTACOES_CPP
#define IMPLEMENTACOES_CPP

#include <iostream>
#include "prototipos.h"

using std::cout;
using std::endl;

Nocd* cria_nocd(int info) {
	Nocd* nocd = new Nocd;
	if (!nocd) {
		return NULL;
	}
	nocd->info = info;
	nocd->ant = NULL;
	nocd->prox = NULL;
	return nocd;
}

Listacd* cria_listacd() {
	Listacd* listacd = new Listacd;
	if (!listacd) {
		return NULL;
	}
	listacd->acesso = NULL;
	return listacd;
}

int tamanho_listacd(Listacd* l) {
	if (!l) {
		return 0;
	}
	// caso lista vazia
	if (l->acesso == NULL) {
		return 0;
	}
	// caso 1 elemento
	if (l->acesso->prox == l->acesso && l->acesso->ant == l->acesso) {
		return 1;
	}
	// demais casos
	int count = 1;
	Nocd* aux = l->acesso->prox;
	while (aux != l->acesso) {
		aux = aux->prox;
	}
	return count;
}

void libera_listacd(Listacd** l) {
	if ((*l)) {
		return;
	}
	// caso lista vazia
	if ((*l)->acesso == NULL) {
		delete((*l));
		*l = NULL;
		return;
	}
	// caso 1 elemento
	if ((*l)->acesso->prox == (*l)->acesso && (*l)->acesso->ant == (*l)->acesso) {
		delete((*l)->acesso);
		delete((*l));
		*l = NULL;
		return;
	}
	// demais casos
	Nocd* aux = (*l)->acesso->prox;
	int t = tamanho_listacd((*l));
	for (int i = 0; i < t; i++) {
		(*l)->acesso->prox = aux->prox;
		delete(aux);
		aux = (*l)->acesso->prox;
	}
	delete((*l));
	*l = NULL;
}

bool insere_listacd(Listacd* l, int info) {
	if (!l) {
		return false;
	}
	Nocd* nocd = cria_nocd(info);
	// caso lista vazia
	if (l->acesso == NULL) {
		l->acesso = nocd;
		nocd->prox = l->acesso;
		nocd->ant = l->acesso;
		return true;
	}
	// demais casos
	nocd->prox = l->acesso->prox;
	nocd->ant = l->acesso;
	l->acesso->prox->ant = nocd;
	l->acesso->prox = nocd;
	return true;
}

bool remove_listacd(Listacd* l, int info) {
	if (!l) {
		return false;
	}
	// caso lista vazia
	if (l->acesso == NULL) {
		return false;
	}
	// caso 1 elemento e seja igual
	if (l->acesso->prox == l->acesso && l->acesso->info == info) {
		delete(l->acesso);
		l->acesso = NULL;
		return true;
	}
	// caso 1 elemento e diferente
	if (l->acesso->prox == l->acesso && l->acesso->info != info) {
		return false;
	}
	// caso seja o primeiro
	Nocd* aux = l->acesso->prox;
	if (l->acesso->info == info) {
		aux = l->acesso;
		l->acesso = aux->prox;
		aux->ant->prox = aux->prox;
		aux->prox->ant = aux->ant;
		delete(aux);
		return true;
	}
	// demais casos	
	while (aux->info != info && aux != l->acesso) {
		aux = aux->prox;
	}
	if (aux == l->acesso) {
		return false;
	}
	aux->ant->prox = aux->prox;
	aux->prox->ant = aux->ant;
	delete(aux);
	return true;
}

bool altera_listacd(Listacd* l, int info, int novo) {
	if (!l) {
		return false;
	}
	// caso lista vazia
	if (l->acesso == NULL) {
		return false;
	}
	// caso 1 elemento e seja igual
	if (l->acesso->prox == l->acesso && l->acesso->info == info) {
		l->acesso->info = novo;
		return true;
	}
	// caso 1 elemento e seja diferente
	if (l->acesso->prox == l->acesso && l->acesso->info != info) {
		return false;
	}
	// caso seja o primeiro
	if (l->acesso->info == info) {
		l->acesso->info = novo;
		return true;
	}
	// demais casos
	Nocd* aux = l->acesso->prox;
	while (aux->info != info && aux != l->acesso) {
		aux = aux->prox;
	}
	if (aux == l->acesso) {
		return false;
	}
	aux->info = novo;
	return true;
}

void imprime_listacd(Listacd* l) {
	if (!l) {
		return;
	}
	Nocd* aux = l->acesso->prox;
	while (aux != l->acesso) {
		cout << "[" << aux->info << "]";
		aux = aux->prox;
	}
	cout << "[" << aux->info << "]" << endl;
}

#endif