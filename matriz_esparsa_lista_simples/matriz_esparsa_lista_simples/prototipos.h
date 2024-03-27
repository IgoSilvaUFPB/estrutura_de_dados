#ifndef PROTOTIPOS_H
#define PROTOTIPOS_H

// defini��o do TAD

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

