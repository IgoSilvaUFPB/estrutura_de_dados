#ifndef IMPLEMENTACOES_MATRIZ_CPP
#define IMPLEMENTACOES_MATRIZ_CPP

#include <iostream>
#include "prototipos_matriz.h"

using namespace std;

// definição da estrutura
struct matriz_dinamica {
	float** elementos;
	int num_linhas;
	int num_colunas;
};

// criação da matriz
Matriz* cria_matriz(int linhas, int colunas) {
	Matriz* m = new Matriz;
	if (!m) {
		return NULL;
	}
	m->elementos = new float*[linhas];
	if (!m->elementos) {
		delete m;
		return NULL;
	}
	for (int i = 0; i < colunas; i++) {
		m->elementos[i] = new float[colunas];
		if (!m->elementos[i]) {
			for (int j = 0; j < i; j++) {
				delete[] m->elementos[j];
			}
			delete[] m->elementos;
			delete m;
			return NULL;
		}
	}
	m->num_linhas = linhas;
	m->num_colunas = colunas;
	return m;
}

// preenchimento da matriz
bool preenche_matriz(Matriz* m) {
	if (!m) {
		return false;
	}
	for (int i = 0; i < m->num_linhas; i++) {
		for (int j = 0; j < m->num_colunas; j++) {
			cout << "Valor da linha " << i << " coluna " << j << ":";
			cin >> m->elementos[i][j];
		}
	}
	return true;
}

// exibição da matriz inteira
void exibe_matriz(Matriz* m) {
	if (!m) {
		return;
	}
	for (int i = 0; i < m->num_linhas; i++) {
		for (int j = 0; j < m->num_colunas; j++) {
			cout << "[" << m->elementos[i][j] << "]";
		}
		cout << endl;
	}
}

// acesso a um elemento da matriz
bool acessa_elemento(Matriz* m, int linha, int coluna, float* copia) {
	if (!m || !copia || linha > m->num_linhas || linha < 0 || coluna > m->num_colunas || coluna < 0) {
		return false;
	}
	*copia = m->elementos[linha][coluna];
	return true;
}

// mofificação de um elemento da matriz
bool modifica_elemento(Matriz* m, int linha, int coluna, float valor) {
	if (!m || linha > m->num_linhas || linha < 0 || coluna > m->num_colunas || coluna < 0) {
		return false;
	}
	m->elementos[linha][coluna] = valor;
	return true;
}

// liberação do espaço de memória alocado
void destroi_matriz(Matriz** m) {
	if (!*m) {
		return;
	}
	// desalocando vetores das linhas
	for (int i = 0; i < (*m)->num_linhas; i++) {
		delete[] (*m)->elementos[i];
	}
	// desalocando vetor dos ponteiros das linhas
	delete[] (*m)->elementos;
	// desalocando matriz
	delete (*m);
	*m = NULL;
}

#endif