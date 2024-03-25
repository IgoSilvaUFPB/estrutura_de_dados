#ifndef FILA_LISTA_SIMPLES_H
#define FILA_LISTA_SIMPLES_H

struct elemento {
	int info;
	struct elemento* frente;
};

struct fila {
	struct elemento* fim;
};

typedef struct fila Fila;
typedef struct elemento Elemento;

Fila* cria_fila();
Elemento* cria_elemento(int info);
void libera_fila(Fila** f);
bool entra_na_fila(Fila* f, int info);
bool sai_da_fila(Fila* f, int* e);
int tamanho_da_fila(Fila* f);
void imprime_fila(Fila* f);

#endif 