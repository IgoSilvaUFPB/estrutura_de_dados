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

bool insere_inicio(Lista* l, int info);

bool insere_meio(Lista* l, int info, int pos);

bool insere_fim(Lista* l, int info);

bool remove_inicio(Lista* l);

bool remove_meio(Lista* l, int pos);

bool remove_fim(Lista* l);

bool remove_info(Lista* l, int info);

bool remove_info_all(Lista* l, int info);

No* busca_no(Lista* l, int info);

bool modifica_no(Lista* l, int info, int novo_info);

void imprime_lista(Lista* l);

void libera_lista(Lista** l);

bool concatena_listas(Lista* l1, Lista* l2);

bool inverte_lista(Lista* l);

#endif

