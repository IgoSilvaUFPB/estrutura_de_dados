#include <iostream>
#include "combina_filas.h"

struct fila {
	int tamanho; // tamanho máximo da fila
	int n; // número de elementos na fila
	float* vet; // vetor de elementos
};

Fila* fila_cria(void) {
	Fila* f = (Fila*)malloc(sizeof(Fila));
	if (!f) {
		return NULL;
	}
	f->tamanho = 10;
	f->n = 0;
	f->vet = (float*)malloc(f->tamanho*sizeof(float));
	if (!f->vet) {
		free(f);
		return NULL;
	}
	return f;
}

void fila_insere(Fila* f, float v) {
	if (!f) {
		return;
	}
	if (f->n == f->tamanho) { // fila está cheia
		return;
	}
	f->vet[f->n] = v;
	f->n++;
}

float fila_retira(Fila* f) {
	if (!f) {
		return -1;
	}
	float valor = f->vet[0];
	for (int i = 0; i < f->n; i++) {
		f->vet[i] = f->vet[i + 1];
	}
	f->n--;
	return valor;
}

int fila_vazia(Fila* f) {
	if (!f) {
		return -1;
	}
	if (f->n == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

void fila_libera(Fila** f) {
	if (!(*f)) {
		return;
	}
	free((*f)->vet);
	free((*f));
}

void imprime_fila(Fila* f){
	if (!f) {
		return;
	}
	if (fila_vazia(f) == 1) {
		std::cout << "[fila vazia]";
	}
	for (int i = 0; i < f->n; i++) {
		std::cout << "[" << f->vet[i] << "]";
	}
	std::cout << std::endl;
}

void combina_filas(Fila* f_res, Fila* f1, fila* f2) {
	if (!f_res || !f1 || !f2) {
		return;
	}
	while ((f1->n > 0 || f2->n > 0) && f_res->n < f_res->tamanho) {
		if (f1->n > 0) {
			f_res->vet[f_res->n] = f1->vet[0];
			f_res->n++;
			for (int i = 0; i < f1->n; i++) {
				f1->vet[i] = f1->vet[i + 1];
			}
			f1->n--;
		}
		if (f2->n > 0) {
			f_res->vet[f_res->n] = f2->vet[0];
			f_res->n++;
			for (int i = 0; i < f2->n; i++) {
				f2->vet[i] = f2->vet[i + 1];
			}
			f2->n--;
		}
	}
}