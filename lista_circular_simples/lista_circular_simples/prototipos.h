#ifndef PROTOTIPOS_H
#define PROTOTIPOS_H

struct noc {
	int info;
	struct noc* prox;
};

struct listac {
	struct noc* acesso;
};

typedef struct noc Noc;
typedef struct listac Listac;

Noc* cria_noc(int info);
Listac* cria_listac();
int tamanho_listac(Listac* l);
void libera_listac(Listac** l);
bool insere_listac(Listac* l, int info);
bool remove_listac(Listac* l, int info);
bool modifica_listac(Listac* l, int info, int novo);
void imprime_listac(Listac* l);

#endif
