#ifndef IMPLEMENTACOES_CPP
#define IMPLEMENTACOES_CPP

#include <iostream>
#include "prototipos.h"

using std::cout;
using std::endl;

// implementação do TAD

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

Nnz* cria_nnz(int linha, int coluna, double info) {
	Nnz* n = new Nnz;
	if (!n) {
		return NULL;
	}
	n->linha = linha;
	n->coluna = coluna;
	n->info = info;
	n->prox = NULL;
	return n;
}

Linha* cria_linha(int linha) {
	Linha* l = new Linha;
	if (!l) {
		return NULL;
	}
	l->linha = linha;
	l->inicio = NULL;
	l->prox = NULL;
	return l;
}

Mesparsa* cria_mesparsa() {
	Mesparsa* m = new Mesparsa;
	if (!m) {
		return NULL;
	}
	m->inicio = NULL;
	return m;
}

int qtd_linhas(Mesparsa* m) {
	if (!m) {
		return 0;
	}
	if (m->inicio == NULL) {
		return 0;
	}
	int count = 1;
	Linha* aux = m->inicio;
	while (aux->prox != NULL) {
		aux = aux->prox;
		count++;
	}
	return count;
}

int qtd_nnz(Linha* linha) {
	if (!linha) {
		return 0;
	}
	if (linha->inicio == NULL) {
		return 0;
	}
	int count = 1;
	Nnz* aux2 = linha->inicio;
	while (aux2->prox != NULL) {
		aux2 = aux2->prox;
		count++;
	}
	return count;
}

void libera_mesparsa(Mesparsa** matriz) {
	if (!(*matriz)) {
		return;
	}
	// liberando as linhas
	if ((*matriz)->inicio != NULL) {		
		Linha* aux = (*matriz)->inicio;
		while (aux != NULL) {
			// liberando os nnz
			if (aux->inicio != NULL) {
				Nnz* aux2 = aux->inicio;
				while (aux2 != NULL) {
					aux->inicio = aux2->prox;
					delete(aux2);
					aux2 = aux->inicio;
				}
			}
			(*matriz)->inicio = aux->prox;
			delete(aux);
			aux = (*matriz)->inicio;
		}
	}
	// libera a matriz
	delete((*matriz));
	*matriz = NULL;
}

bool insere_na_linha(Linha* l, int linha, int coluna, double info) {
	// caso linha vazia
	if (l->inicio == NULL) {
		Nnz* n = cria_nnz(linha, coluna, info); // cria nnz
		if (!n) { // verifica alocação
			delete(l); // destroi linha se alocação falhou
			return false;
		}
		l->inicio = n; // adiciona nnz a linha
		return true;
	}
	Nnz* n = cria_nnz(linha, coluna, info); // cria nnz
	if (!n) {
		return false;
	}
	// insere na primeira posicao
	if (l->inicio->coluna > coluna) {
		n->prox = l->inicio;
		l->inicio = n;
		return true;
	}
	Nnz* aux2 = l->inicio;
	while (aux2->prox != NULL && aux2->prox->coluna < coluna) {
		aux2 = aux2->prox;
	}
	// insere no final
	if (aux2->prox == NULL) {
		aux2->prox = n;
		return true;
	}
	// insere entre dois	
	n->prox = aux2->prox;
	aux2->prox = n;
	return true;
}

bool insere_nnz(Mesparsa* matriz, int linha, int coluna, double info) {
	if (!matriz) {
		return false;
	}
	Linha* l = cria_linha(linha); // cria linha
	if (!l) {
		return false;
	}
	// caso matriz vazia
	if (matriz->inicio == NULL) {
		matriz->inicio = l; // adiciona linha a matriz
		return insere_na_linha(l, linha, coluna, info); // insere nnz na linha
	}
	// buscando posição da linha
	Linha* aux = matriz->inicio; // ponteiro para primeira linha
	while (aux->prox != NULL && aux->linha != linha && aux->prox->linha <= linha) {
		// buscando linha igual, limite, ou final
		aux = aux->prox;
	}
	// insere na primeira posição
	if (aux->linha > linha) {
		l->prox = aux;
		matriz->inicio = l;
		return insere_na_linha(l, linha, coluna, info); // insere nnz na linha
	}
	// caso linha encontrada
	if (aux->linha == linha) {
		return insere_na_linha(aux, linha, coluna, info); // insere nnz na linha
	}
	// caso final da lista
	if (aux->prox == NULL) {
		aux->prox = l;
		return insere_na_linha(l, linha, coluna, info); // insere nnz na linha
	}
	// caso limite insere após	
	l->prox = aux->prox;
	aux->prox = l;
	return insere_na_linha(l, linha, coluna, info); // insere nnz na linha
}

bool remove_nnz(Mesparsa* matriz, int linha, int coluna) {
	if (!matriz) {
		return false;
	}
	// caso matriz vazia
	if (matriz->inicio == NULL) {
		return false;
	}
	// buscando linha
	Linha* aux = matriz->inicio;
	while (aux != NULL && aux->linha != linha) {
		aux = aux->prox;
	}
	// caso linha não encontrada
	if (aux == NULL) {
		return false;
	}
	// caso linha encontrada
	// caso linha vazia
	if (aux->inicio == NULL) {
		return false;
	}
	Nnz* aux2 = aux->inicio;
	// caso seja o primeiro
	if (aux->inicio->coluna == coluna) {
		aux->inicio = aux2->prox;
		delete(aux2);
		return true;
	}
	// buscando nnz	
	while (aux2->prox->coluna != coluna && aux2->prox != NULL) {
		aux2 = aux2->prox;
	}
	// caso nnz não encontrado
	if (aux2->prox == NULL) {
		return false;
	}
	// deletando nnz
	Nnz* aux3 = aux2->prox;
	aux2->prox = aux3->prox;
	delete(aux3);
	return true;
}

//bool altera_nnz(Mesparsa* matriz, int linha, int coluna, double info, double novo);

void imprime_mesparsa(Mesparsa* matriz) {
	if (!matriz) {
		return;
	}
	// caso matriz vazia
	if (matriz->inicio == NULL) {
		return;
	}
	// imprime linha a linha
	Linha* aux = matriz->inicio;
	while (aux != NULL) {
		// caso linha vazia
		if (aux->inicio == NULL) {
			return;
		}
		Nnz* nnz = aux->inicio;
		while (nnz != NULL) {
			cout << "[(" << nnz->linha << ", " << nnz->coluna << ")=" << nnz->info << "]";
			nnz = nnz->prox;
		}
		cout << endl;
		aux = aux->prox;
	}
}

#endif