#ifndef ARVORE_BUSCA_H
#define ARVORE_BUSCA_H

typedef struct arvore Arvore;

struct arvore {
	int info;
	struct arvore* esq;
	struct arvore* dir;
};

Arvore* cria_arvore(int info);
void libera_arvore(Arvore** a);
bool insere_arvore(Arvore** a, int info);
bool remove_arvore(Arvore** a, int info, int* deletado);
void imprime_pre(Arvore* a);
void imprime_pos(Arvore* a);
void imprime_simetrico(Arvore* a);
Arvore* busca_arvore(Arvore* a, int info);

#endif
