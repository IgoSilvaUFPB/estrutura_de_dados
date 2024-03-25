#include "fila_lista_simples.h"
#include <iostream>

using std::cout;
using std::endl;

Fila* cria_fila() {
	Fila* f = (Fila*)malloc(sizeof(Fila));
	if (!f) {
		return NULL;
	}
	f->fim = NULL;
	return f;
}

Elemento* cria_elemento(int info) {
	Elemento* e = (Elemento*)malloc(sizeof(Elemento));
	if (!e) {
		return NULL;
	}
	e->info = info;
	e->frente = NULL;
	return e;
}

void libera_fila(Fila** f) {
	if (!(*f)) {
		return;
	}
	// caso fila vazia
	if ((*f)->fim == NULL) {
		free((*f));
		*f = NULL;
		return;
	}
	// caso fila tenha elementos
	Elemento* aux = (*f)->fim;
	while (aux != NULL) {
		(*f)->fim = aux->frente;
		free(aux);
		aux = (*f)->fim;
	}
	free((*f));
	*f = NULL;
}

bool entra_na_fila(Fila* f, int info) {
	if (!f) {
		return false;
	}
	// cria o elemento
	Elemento* e = cria_elemento(info);
	// caso fila vazia
	if (f->fim == NULL) {
		f->fim = e;
		return true;
	}
	// caso fila tenha elementos
	e->frente = f->fim;
	f->fim = e;
	return true;
}

bool sai_da_fila(Fila* f, int* e) {
	if (!f) {
		return false;
	}
	// caso fila vazia
	if (f->fim == NULL) {
		return true;
	}
	Elemento* aux = f->fim;
	// caso tenha um elemento
	if (f->fim->frente == NULL) {
		f->fim = NULL;
		*e = aux->info;
		free(aux);
	}
	// caso fila tenha elementos	
	while (aux->frente->frente != NULL) {
		aux = aux->frente;
	}
	Elemento* aux2 = aux->frente;
	aux->frente = NULL;
	*e = aux2->info;
	free(aux2);
	return true;
}

int tamanho_da_fila(Fila* f) {
	if (!f) {
		return false;
	}
	// caso fila vazia
	if (f->fim == NULL) {
		return 0;
	}
	// caso fila tenha elementos
	int count = 1;
	Elemento* aux = f->fim;
	while (aux->frente != NULL) {
		aux = aux->frente;
		count++;
	}
	return count;
}

void imprime_fila(Fila* f) {
	if (!f) {
		return;
	}
	// caso fila vazia
	if (f->fim == NULL) {
		return;
	}
	// caso fila tenha elementos
	Elemento* aux = f->fim;
	while (aux != NULL) {
		cout << "[" << aux->info << "]";
		aux = aux->frente;
	}
	cout << endl;
}