#ifndef PROTOTIPOS_H
#define PROTOTIPOS_H

struct No {
    int info;
    struct No* prox;
};

struct lista {
    No* inicio;
};

typedef struct lista Lista;

No* cria_no(int info);

Lista* cria_lista();

int tamanho_lista(Lista* l);

bool insere_info(Lista* l, int info);

bool remove_info(Lista* l, int info);

bool reordenar_lista(Lista* l);

bool modifica_info(Lista* l, int info, int novo_info);

void imprime_lista(Lista* l);

void libera_lista(Lista** l);

#endif


