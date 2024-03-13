#ifndef PROTOTIPOS_H
#define PROTOTIPOS_H

struct nod {
	struct nod* ant;
	int info;
	struct nod* prox;
};

struct listad {
	struct nod* inicio;
	struct nod* fim;
};

typedef struct nod Nod;
typedef struct listad Listad;

Nod* cria_nod(int info);
Listad* cria_listad();
void libera_listad(Listad** ld);
int tamanho(Listad* ld);
bool insere_vazia(Listad* ld, int info);
bool insere_inicio(Listad* ld, int info);
bool insere_fim(Listad* ld, int info);
bool insere_meio(Listad* ld, int info, int pos);
bool remove_info(Listad* ld, int info);
void imprime_lista(Listad* ld);

#endif
