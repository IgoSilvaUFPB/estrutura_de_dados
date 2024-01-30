#include <iostream>
#include "prototipos_ponto_2d.h"
using namespace std;

int main(void) {

	// cria ponto 1
	Ponto igo1 = cria_ponto(1, 1);
	imprime_ponto(igo1);

	// cria ponto 2
	Ponto igo2 = cria_ponto(1, 3);
	imprime_ponto(igo2);

	// modifica ponto 2
	modifica_ponto(&igo2, 1, 6);
	imprime_ponto(igo2);

	// calcula a distancia entre os pontos
	float dist = distancia_entre_pontos(igo1, igo2);
	cout << "Distancia = " << dist << endl;

	return 0;
}