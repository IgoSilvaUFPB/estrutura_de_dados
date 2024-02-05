#ifndef IMPLEMENTACOES_PONTO_2D_CPP
#define IMPLEMENTACOES_PONTO_2D_CPP

#include <iostream>
#include "prototipos_ponto_2d.h"
#include <cmath>
using namespace std;

// defini��o da estrutura
struct ponto {
	float x;
	float y;
};

// fun��o para cria pontos
Ponto* cria_ponto(float x, float y) {
	Ponto* MeuPonto = (Ponto*) malloc(sizeof(Ponto));
	if (MeuPonto) {
		MeuPonto->x = x;
		MeuPonto->y = y;
		return MeuPonto;
	}	
	return NULL;
}

// fun��o para modificar as coordenadas de um ponto
bool modifica_ponto(Ponto* p, float x, float y) {
	if (!p) {
		return false;
	}
	p->x = x;
	p->y = y;
	return true;
}

// fun��o para calcular a dist�ncia entre dois pontos
float distancia_entre_pontos(Ponto* a, Ponto* b) {
	if (!a || !b) {
		return -1;
	}
	float distancia = sqrt(pow(a->x - b->x, 2) + pow(a->y - b->y, 2));
	return distancia;
}

// fun��o para exibir as coordenadas de um ponto
void imprime_ponto(Ponto* p) {
	if (!p) {
		return;
	}
	cout << "x do ponto = " << p->x << endl;
	cout << "y do ponto = " << p->y << endl;
}

// fun��o para extrair coordenadas do ponto
bool acessa_ponto(Ponto* p, float* ptx, float* pty) {
	if (!p || !ptx || !pty) {
		return false;
	}
	*ptx = p->x;
	*pty = p->y;
	return true;
}

// fun��o para liberar espa�o de mem�ria
void libera_ponto(Ponto** p) {
	if (*p) {
		free(*p);
		*p = NULL;
	}	
}

#endif