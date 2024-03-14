#ifndef IMPLEMENTACOES_CPP
#define IMPLEMENTACOES_CPP

#include <iostream>
#include "prototipos.h"

using std::cout;
using std::endl;

Noc* cria_noc(int info) {
	Noc* noc = new Noc;
	if (!noc) {
		return NULL;
	}
	noc->info = info;
	noc->prox = NULL;
	return noc;
}

Listac* cria_listac() {
	Listac* listac = new Listac;
	if (!listac) {
		return NULL;
	}
	listac->acesso = NULL;
	return listac;
}

int tamanho_listac(Listac* l) {
	if (!l) {
		return 0;
	}
	// caso lista vazia
	if (l->acesso == NULL) {
		return 0;
	}
	Noc* aux = l->acesso;
	int count = 1;
	while (aux->prox != l->acesso) {
		count++;
		aux = aux->prox;
	}
	return count;
}

void libera_listac(Listac** l) {
	if (!(*l)) {
		return;
	}
	// lista vazia
	if ((*l)->acesso == NULL) {
		delete((*l));
		*l = NULL;
		return;
	}
	// se tem apenas um elemento
	if ((*l)->acesso->prox == NULL) {
		delete((*l)->acesso);
		delete((*l));
		*l = NULL;
		return;
	}
	// demais casos
	int t = tamanho_listac((*l));
	Noc* aux = (*l)->acesso;
	for (int i = 0; i < t; i++) {
		(*l)->acesso = aux->prox;
		delete(aux);
		aux = (*l)->acesso;
	}
	delete((*l));
	*l = NULL;
}

bool insere_listac(Listac* l, int info) {
	if (!l) {
		return false;
	}
	Noc* noc = cria_noc(info);
	if (!noc) {
		return false;
	}
	// caso lista vazia
	if (l->acesso == NULL) {
		l->acesso = noc;
		noc->prox = noc;
		return true;
	}
	// demais casos
	noc->prox = l->acesso->prox;
	l->acesso->prox = noc;
	return true;	
}

bool remove_listac(Listac* l, int info) {
	if (!l) {
		return false;
	}
	// caso lista vazia
	if (l->acesso == NULL) {
		return false;
	}
	// caso tenha um elemento e seja igual
	if (l->acesso->info == info && l->acesso->prox == l->acesso) {
		delete(l->acesso);
		l->acesso = NULL;
		return true;
	}
	// caso tenha um elemento e seja diferente
	if (l->acesso->info != info && l->acesso->prox == l->acesso) {
		return false;
	}
	Noc* aux1 = l->acesso->prox;
	Noc* aux2 = l->acesso;
	while (aux1->info != info && aux1 != l->acesso) {
		aux1 = aux1->prox;
		aux2 = aux2->prox;
	}
	if (aux1 == l->acesso && aux1->info != info) {
		return false;
	}
	aux2->prox = aux1->prox;
	l->acesso = aux2;
	delete(aux1);
}

bool modifica_listac(Listac* l, int info, int novo) {
	if (!l) {
		return false;
	}
	// caso lista vazia
	if (l->acesso == NULL) {
		return false;
	}
	// modifica o primeiro
	if (l->acesso->info == info) {
		l->acesso->info = novo;
		return true;
	}
	// demais casos
	Noc* aux = l->acesso->prox;
	while (aux->info != info && aux != l->acesso) {
		aux = aux->prox;
	}
	if (aux == l->acesso) {
		return false;
	}
	aux->info = novo;
	return true;
}

void imprime_listac(Listac* l){	
	if (!l) {
		return;
	}	
	// caso lista vazia
	if(l->acesso == NULL){
		return;
	}
	// caso lista com um elemento
	if (l->acesso->prox == l->acesso) {
		cout << "[" << l->acesso->info << "]" << endl;
		return;
	}	
	// demais casos
	Noc* aux = l->acesso->prox;
	while (aux != l->acesso) {
		cout << "[" << aux->info << "]";
		aux = aux->prox;
	}
	cout << "[" << aux->info << "]" << endl;	
}

#endif