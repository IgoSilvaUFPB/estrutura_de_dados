#ifndef IMPLEMENTACOES_MATRIZ_CPP
#define IMPLEMENTACOES_MATRIZ_CPP

#include <iostream>
#include "prototipos_matriz.h"

using namespace std;

// definição da estrutura
struct matriz_dinamica {
	float* elementos;
	int num_linhas;
	int num_colunas;
};

// criação da matriz
Matriz* cria_matriz(int linhas, int colunas) {
	Matriz* m = new Matriz;
	if (!m) {
		return NULL;
	}
	m->elementos = new float[linhas * colunas];
	if (!m->elementos) {
		delete m;
		return NULL;
	}
	m->num_linhas = linhas;
	m->num_colunas = colunas;
	return m;
}

// preenchimento da matriz
bool preenche_matriz(Matriz* m) {
	if (!m || !m->elementos) {
		return false;
	}
	for (int i = 0; i < m->num_linhas; i++) {
		for (int j = 0; j < m->num_colunas; j++) {
			cout << "Valor da linha " << i << " coluna " << j << ":";
			cin >> m->elementos[(i * m->num_colunas) + j]; // posição = (linha * número_de_colunas) + coluna
		}
	}
	return true;
}

// exibição da matriz inteira
void exibe_matriz(Matriz* m) {
	if (!m || !m->elementos) {
		return;
	}
	for (int i = 0; i < m->num_linhas; i++) {
		for (int j = 0; j < m->num_colunas; j++) {
			cout << "[" << m->elementos[(i * m->num_colunas) + j] << "]";
		}
		cout << endl;
	}
}

// acesso a um elemento da matriz
bool acessa_elemento(Matriz* m, int linha, int coluna, float* copia) {
	if (!m || !m->elementos || !copia) {
		return false;
	}
	*copia = m->elementos[(linha * m->num_colunas) + coluna];
	return true;
}

// mofificação de um elemento da matriz
bool modifica_elemento(Matriz* m, int linha, int coluna, float valor) {
	if (!m || !m->elementos) {
		return false;
	}
	m->elementos[(linha * m->num_colunas) + coluna] = valor;
	return true;
}

// liberação do espaço de memória alocado
void destroi_matriz(Matriz** m) {
	if (!*m || !(*m)->elementos) {
		return;
	}
	delete[] ((*m)->elementos);
	(*m)->elementos = NULL;
	delete(*m);
	*m = NULL;
}

#endif