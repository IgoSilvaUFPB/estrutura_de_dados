#include <iostream>
#include "prototipos_ponto_2d.h"
#include <cmath>
using namespace std;

Ponto cria_ponto(float x, float y) {
	Ponto MeuPonto;
	MeuPonto.x = x;
	MeuPonto.y = y;
	return MeuPonto;
}

void modifica_ponto(Ponto* p, float x, float y) {
	p->x = x;
	p->y = y;
}

float distancia_entre_pontos(Ponto a, Ponto b) {
	float distancia = sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
	return distancia;
}

void imprime_ponto(Ponto p) {
	cout << "x do ponto = " << p.x << endl;
	cout << "y do ponto = " << p.y << endl;
}

void acessa_ponto(Ponto p, float* x, float* y) {
	*x = p.x;
	*y = p.y;
}