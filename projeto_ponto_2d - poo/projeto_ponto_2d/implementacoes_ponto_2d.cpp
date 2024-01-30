#include <iostream>
#include "prototipos_ponto_2d.h"
// biblioteca de operações matemáticas
#include <cmath>
using namespace std;

Ponto::Ponto(float novo_x, float novo_y) {
	x = novo_x;
	y = novo_y;
}

float Ponto::distancia_entre_pontos(Ponto B) {
	float distancia = sqrt(pow(x - B.x, 2) + pow(y - B.y, 2));
	return distancia;
}

void Ponto::imprime_ponto() {
	cout << "x do ponto = " << x << endl;
	cout << "y do ponto = " << y << endl;
}

bool Ponto::modifica_ponto(float novo_x, float novo_y) {
	x = novo_x;
	y = novo_y;
	return true;
}

bool Ponto::acessa_ponto(float* coord_x, float* coord_y) {
	*coord_x = x;
	*coord_y = y;
	return true;
}