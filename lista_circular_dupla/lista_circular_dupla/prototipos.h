#ifndef PROTOTIPOS_H
#define PROTOTIPOS_H

struct nocd {
	int info;
	struct nocd* ant;
	struct nocd* prox;
};

struct listacd {
	struct nocd* acesso;
};

typedef struct nocd Nocd;
typedef struct listacd Listacd;

Nocd* cria_nocd(int info);
Listacd* cria_listacd();
int tamanho_listacd(Listacd* l);
void libera_listacd(Listacd** l);
bool insere_listacd(Listacd* l, int info);
bool remove_listacd(Listacd* l, int info);
bool altera_listacd(Listacd* l, int info, int novo);
void imprime_listacd(Listacd* l);

#endif
