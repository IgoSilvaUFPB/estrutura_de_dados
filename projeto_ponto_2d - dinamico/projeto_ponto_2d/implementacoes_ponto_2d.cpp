#include <iostream>
#include "prototipos_ponto_2d.h"
// biblioteca de opera��es matem�ticas
#include <cmath>
using namespace std;

// defini��o da estrutura
struct ponto {
	float x;
	float y;
};

Ponto* cria_ponto(float x, float y) {
	Ponto* MeuPonto = (Ponto*) malloc(sizeof(Ponto));
	MeuPonto->x = x;
	MeuPonto->y = y;
	return MeuPonto;
}

void libera_ponto(Ponto** p) {
	free(*p);
}

void imprime_ponto(Ponto* p) {
	cout << "x do ponto = " << p->x << endl;
	cout << "y do ponto = " << p->y << endl;
}

float distancia_entre_pontos(Ponto* a, Ponto* b) {
	float distancia = sqrt(pow(a->x - b->x, 2) + pow(a->y - b->y, 2));
	return distancia;
}

bool modifica_ponto(Ponto* p, float x, float y) {
	p->x = x;
	p->y = y;
	return true;
}

bool acessa_ponto(Ponto* p, float* ptx, float* pty) {
	*ptx = p->x;
	*pty = p->y;
	return true;
}