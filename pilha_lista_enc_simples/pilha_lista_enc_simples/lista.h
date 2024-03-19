#ifndef LISTA_H
#define LISTA_H

#include <iostream>

#define _TAMANHO_PILHA_ 10

struct pilha {
	struct elemento* topo;
};

struct elemento {
	int info;
	struct elemento* prox;
};

typedef struct pilha Pilha;
typedef struct elemento Elemento;

Pilha* cria_pilha();
Elemento* cria_elemento(int info);
void libera_pilha(Pilha** p);
bool empilha(Pilha* p, int info);
bool desempilha(Pilha* p, int* info);
void imprime_pilha(Pilha* p);
int tamanho_pilha(Pilha* p);

#endif
