#include "fila_lista_dupla.h"
#include <iostream>

using std::cout;
using std::endl;

Fila* cria_fila() {
	Fila* f = (Fila*)malloc(sizeof(Fila));
	if (!f) {
		return NULL;
	}
	f->fim = NULL;
	f->inicio = NULL;
	return f;
}

Elemento* cria_elemento(int info) {
	Elemento* e = (Elemento*)malloc(sizeof(Elemento));
	if (!e) {
		return NULL;
	}
	e->info = info;
	e->frente = NULL;
	e->tras = NULL;
	return e;
}

void libera_fila(Fila** f) {
	if (!(*f)) {
		return;
	}
	// caso fila vazia
	if ((*f)->fim == NULL && (*f)->inicio == NULL) {
		free((*f));
		*f = NULL;
	}
	// caso fila tenha elementos
	Elemento* aux = (*f)->fim;
	while (aux->frente != NULL) {
		(*f)->fim = aux->frente;
		(*f)->fim->tras = NULL;
		free(aux);
		aux = (*f)->fim;
	}
	// eliminando o último elemento
	(*f)->fim = NULL;
	(*f)->inicio = NULL;
	free(aux);
	free((*f));
	*f = NULL;
}

bool entra_na_fila(Fila* f, int info) {
	if (!f) {
		return false;
	}
	Elemento* e = cria_elemento(info);
	// caso fila vazia
	if (f->fim == NULL && f->inicio == NULL) {
		f->fim = e;
		f->inicio = e;
		return true;
	}
	// caso fila tenha elementos
	e->frente = f->fim;
	f->fim->tras = e;
	f->fim = e;
	return true;
}

bool sai_da_fila(Fila* f, int* e) {
	if (!f) {
		return false;
	}
	Elemento* aux = f->fim;
	*e = aux->info;
	f->fim = aux->frente;
	f->fim->tras = NULL;
	free(aux);
}

int tamanho_da_fila(Fila* f) {
	if (!f) {
		return -1;
	}
	// caso fila vazia
	if (f->fim == NULL && f->inicio == NULL) {
		return 0;
	}
	// caso fila tenha elementos
	int count = 1;
	Elemento* aux = f->inicio;
	while (aux->tras != NULL) {
		aux = aux->tras;
		count++;
	}
	return count;
}

void imprime_fila(Fila* f) {
	if (!f) {
		return;
	}
	// caso lista vazia
	if (f->fim == NULL && f->inicio == NULL) {
		return;
	}
	// caso lista tenha elementos
	Elemento* aux = f->inicio;
	while (aux != NULL) {
		cout << "[" << aux->info << "]";
		aux = aux->tras;
	}
	cout << endl;
}