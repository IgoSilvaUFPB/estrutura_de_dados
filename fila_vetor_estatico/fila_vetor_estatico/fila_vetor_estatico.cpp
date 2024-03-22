#include "fila_vetor_estatico.h"
#include <iostream>

Fila* cria_fila() {
	Fila* f = (Fila*)malloc(sizeof(Fila));
	if (!f) {
		return NULL;
	}
	f->entrada = -1;
	f->n = 0;
	return f;
}

void libera_fila(Fila** f) {
	delete *f;
	*f = NULL;
}

bool insere(Fila* f, int info) {
	if (!f) {
		return false;
	}
	if (esta_cheia(f)) { // fila cheia
		return false;
	}
	(f->entrada)++; // avançar a entrada
	f->info[f->entrada] = info; // inserir o elemento
	(f->n)++; // incrementar o número de elementos
	return true;
}

bool remove(Fila* f, int* info) {
	if (!f || !info) {
		return false;
	}
	int pos = (f->entrada) - (f->n) + 1; // posição do primeiro elemento da fila
	*info = f->info[pos]; // recuperar o primeiro elemento
	// remover o primeiro elemento da fila
	for (int i = 0; i < f->entrada; i++) {
		f->info[i] = f->info[i + 1]; // deslocar os elementos
	}
	(f->entrada)--; // voltar a entrada
	(f->n)--; // decrementar o número de elementos
	return true;
}

bool esta_vazia(Fila* f) {
	return f->n == 0;
}

bool esta_cheia(Fila* f) {
	return f->n == _TAMANHO_;
}

void imprime(Fila* f) {
	if (!f) {
		return;
	}
	for (int i = 0; i < f->n; i++) {
		std::cout << f->info[i] << " ";
	}
	std::cout << std::endl;
}

int tamanho(Fila* f) {
	return f->n;
}

