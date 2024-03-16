#ifndef PROTOTIPOS_H
#define PROTOTIPOS_H

struct nnz {
	double info;
	int linha;
	int coluna;
	struct nnz* prox;
};

struct linha {
	int linha;
	struct nnz* inicio;
	struct linha* prox;
};

struct mesparsa {
	struct linha* inicio;
};

typedef struct nnz Nnz;
typedef struct linha Linha;
typedef struct mesparsa Mesparsa;

Mesparsa* cria_mesparsa();
Linha* cria_linha(int linha);
Nnz* cria_nnz(int linha, int coluna, double info);
int qtd_linhas(Mesparsa* matriz);
int qtd_nnz(Linha* linha);
void libera_mesparsa(Mesparsa** matriz);
bool insere_na_linha(Linha* l, int linha, int coluna, double info);
bool insere_nnz(Mesparsa* matriz, int linha, int coluna, double info);
bool remove_nnz(Mesparsa* matriz, int linha, int coluna);
//bool altera_nnz(Mesparsa* matriz, int linha, int coluna, double info, double novo);
void imprime_mesparsa(Mesparsa* matriz);

#endif

