#include <iostream>
#include "combina.h"

using std::cout;
using std::endl;

struct fila {
	struct no* ini;
	struct no* fim;
};

struct no {
	float info;
	struct no* ant;
	struct no* prox;
};

Fila* cria_fila(void) {
	Fila* f = (Fila*)malloc(sizeof(Fila));
	if (!f) {
		return NULL;
	}
	f->ini = NULL;
	f->fim = NULL;
	return f;
}

No* cria_no(float info) {
	No* n = (No*)malloc(sizeof(No));
	if (!n) {
		return NULL;
	}
	n->ant = NULL;
	n->prox = NULL;
	n->info = info;
	return n;
}

void libera_fila(Fila** f) {
	if (!(*f)) {
		return;
	}
	// liberando os nos
	while ((*f)->ini != NULL) {
		No* aux = (*f)->ini;
		(*f)->ini = aux->prox;
		free(aux);
	}
	// liberando a fila
	free((*f));
	*f = NULL;
}

bool entra_fila(Fila* f, float v) {
	if (!f) {
		return false;
	}
	No* n = cria_no(v);
	// caso lista vazia
	if (f->ini == NULL && f->fim == NULL) {
		f->ini = n;
		f->fim = n;
		return true;
	}
	// caso lista tenha elementos
	n->ant = f->fim;
	f->fim->prox = n;
	f->fim = n;
	return true;
}

void imprime_fila(Fila* f) {
	if (!f) {
		return;
	}
	// caso fila vazia
	if (f->ini == NULL && f->fim == NULL) {
		cout << "[fila vazia]" << endl;
		return;
	}
	No* aux = f->ini;
	cout << "[";
	while (aux != NULL) {
		cout << aux->info << " -> ";
		aux = aux->prox;
	}
	cout << "]" << endl;
}

bool sai_fila(Fila* f, float* v) {
	if (!f) {
		return false;
	}
	// caso lista vazia
	if (f->ini == NULL && f->fim == NULL) {
		return false;
	}
	No* aux = f->ini;
	*v = aux->info; // extração da informação
	// caso tenha apenas um elemento
	if (f->ini == f->fim) {
		f->fim = NULL;
		f->ini = NULL;
		free(aux);
		return true;
	}
	// caso tenha mais de um elemento
	f->ini = aux->prox;
	f->ini->ant = NULL;
	free(aux);
	return true;
}

bool combina_filas(Fila* res, Fila* f1, Fila* f2) {
	if (!res || !f1 || !f2) {
		return false;
	}
	while ((f1->ini != NULL && f1->fim != NULL) || (f2->ini != NULL && f2->fim != NULL)) {
		// usa fila 1
		if (f1->ini != NULL && f1->fim != NULL) {			
			if (res->ini == NULL && res->fim == NULL) {
				// caso res vazia
				res->ini = f1->ini;
				res->fim = f1->ini;
				f1->ini = f1->ini->prox;
				f1->ini->ant = NULL;
				res->ini->prox = NULL;
			}
			else {
				// caseo res tenha elementos
				res->fim->prox = f1->ini;
				res->fim = res->fim->prox;
				// caso f1 tenha apenas um elemento
				if (f1->ini == f1->fim) {
					f1->ini = NULL;
					f1->fim = NULL;

				}
				else {
					f1->ini = f1->ini->prox;
					f1->ini->ant = NULL;
				}
				res->fim->prox = NULL;
			}			
		}
		// usa fila 2
		if (f2->ini != NULL && f2->fim != NULL) {			
			if (res->ini == NULL && res->fim == NULL) {
				// caso res vazia
				res->ini = f2->ini;
				res->fim = f2->ini;
				f2->ini = f2->ini->prox;
				f2->ini->ant = NULL;
				res->ini->prox = NULL;
			}
			else {
				// caseo res tenha elementos
				res->fim->prox = f2->ini;
				res->fim = res->fim->prox;
				// caso f1 tenha apenas um elemento
				if (f2->ini == f2->fim) {
					f2->ini = NULL;
					f2->fim = NULL;

				}
				else {
					f2->ini = f2->ini->prox;
					f2->ini->ant = NULL;
				}
				res->fim->prox = NULL;
			}			
		}
	}
}