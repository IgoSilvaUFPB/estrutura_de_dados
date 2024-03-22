#ifndef FILA_VETOR_ESTATICO_H
#define FILA_VETOR_ESTATICO_H

#define _TAMANHO_ 5

struct fila {
	int info[_TAMANHO_];
	int entrada;
	int n; // número de elementos na fila
};

typedef struct fila Fila;

Fila* cria_fila();
void libera_fila(Fila** f);
bool insere(Fila* f, int info);
bool remove(Fila* f, int* info);
bool esta_vazia(Fila* f);
bool esta_cheia(Fila* f);
void imprime(Fila* f);
int tamanho(Fila* f);

#endif