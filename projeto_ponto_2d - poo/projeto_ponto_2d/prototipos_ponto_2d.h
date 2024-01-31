#ifndef PROTOTIPOS_PONTO_2D_H
#define PROTOTIPOS_PONTO_2D_H

class Ponto {
	float x;
	float y;
public:
	Ponto(float novo_x, float novo_y);
	void modifica_ponto(float novo_x, float novo_y);
	float distancia_entre_pontos(Ponto B);
	void imprime_ponto();
	void acessa_ponto(float* coord_x, float *coord_y);
};

#endif