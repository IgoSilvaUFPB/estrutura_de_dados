#ifndef IMPLEMENTACOES_CPP
#define IMPLEMENTACOES_CPP

#include <iostream>
#include "prototipos.h"

using std::cout;
using std::endl;

Nod* cria_nod(int info) {
	Nod* nod = new Nod;
	nod->info = info;
	nod->ant = NULL;
	nod->prox = NULL;
	return nod;
}

Listad* cria_listad() {
	Listad* ld = new Listad;
	ld->inicio = NULL;
	ld->fim = NULL;
	return ld;
}

void libera_listad(Listad** ld) {
	if (!(*ld)) {
		return;
	}
	// liberar nós
	Nod* aux = (*ld)->fim;
	while ((*ld)->fim != NULL) {
		aux = (*ld)->fim;
		(*ld)->fim = (*ld)->fim->ant;
		delete(aux);
	}
	// liberar lista
	delete((*ld));
	*ld = NULL;
}

int tamanho(Listad* ld) {
	if (!ld) {
		return 0;
	}
	int cont = 0;
	Nod* aux = ld->inicio;
	while (aux != NULL) {
		cont++;
		aux = aux->prox;
	}
	return cont;
}

bool insere_vazia(Listad* ld, Nod* nod) {
	ld->inicio = nod;
	ld->fim = nod;
	return true;
}

bool insere_inicio(Listad* ld, int info) {
	if (!ld) {
		return false;
	}
	Nod* nod = cria_nod(info);
	// caso lista vazia
	if (ld->inicio == NULL && ld->fim == NULL) {
		return insere_vazia(ld, nod);
	}
	// caso lista não vazia
	nod->prox = ld->inicio;
	ld->inicio->ant = nod;
	ld->inicio = nod;
	return true;
}

bool insere_fim(Listad* ld, int info) {
	if (!ld) {
		return false;
	}
	Nod* nod = cria_nod(info);
	// caso lista vazia
	if (ld->inicio == NULL && ld->fim == NULL) {
		return insere_vazia(ld, nod);
	}
	// caso lista não vazia
	nod->ant = ld->fim;
	ld->fim->prox = nod;
	ld->fim = nod;
	return true;
}

bool insere_meio(Listad* ld, int info, int pos) {
	if (!ld) {
		return false;
	}
	Nod* nod = cria_nod(info);
	// caso lista vazia
	if (ld->inicio == NULL && ld->fim == NULL) {
		return insere_vazia(ld, nod);
	}
	// caso pos= 0, insere no inicio
	if (pos == 0) {
		return insere_inicio(ld, info);
	}
	int t = tamanho(ld);
	// caso pos == t, insere no fim
	if (pos == (t-1)) {
		return insere_fim(ld, info);
	}
	// insere na posição caso exista	
	if (pos > 0 && pos < t){
		Nod* aux = ld->inicio;
		for (int i = 0; i < (pos-1); i++) {
			aux = aux->prox;
		}
		nod->ant = aux;
		nod->prox = aux->prox;
		aux->prox->ant = nod;
		aux->prox = nod;
		return true;
	}
	return false;
}

bool remove_info(Listad* ld, int info) {
	if (!ld) {
		return false;
	}
	// caso lista vazia
	if (ld->inicio == NULL && ld->fim == NULL) {
		return false;
	}
	// caso lista tenha um elemento
	if (ld->inicio == ld->fim) {
		delete(ld->inicio);
		ld->inicio = NULL;
		ld->fim = NULL;
		return true;
	}	
	// removendo o primeiro
	if (ld->inicio->info == info) {
		ld->inicio = ld->inicio->prox;
		delete(ld->inicio->ant);
		ld->inicio->ant = NULL;
		return true;
	}
	// removendo o último
	if (ld->fim->info == info) {
		ld->fim = ld->fim->ant;
		delete(ld->fim->prox);
		ld->fim->prox = NULL;
		return true;
	}
	Nod* aux = ld->inicio;
	// buscando info
	while (aux != NULL && aux->info != info) {
		aux = aux->prox;
	}
	// info não encontrada
	if (aux == NULL) {
		return false;
	}
	// removendo no meio
	aux->ant->prox = aux->prox;
	aux->prox->ant = aux->ant;
	delete(aux);
	return true;
}

void imprime_lista(Listad* ld) {
	if (!ld) {
		return;
	}
	Nod* aux = ld->inicio;
	while (aux != NULL) {
		cout << "[" << aux->info << "]";
		aux = aux->prox;
	}
	cout << endl;
}

#endif