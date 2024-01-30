#ifndef PROTOTIPOS_PONTO_2D_H
#define PROTOTIPOS_PONTO_2D_H

// defini��o da estrutura
struct Ponto {
	float x;
	float y;
};

// fun��o para cria pontos
Ponto cria_ponto(float x, float y);

// fun��o para modificar as coordenadas de um ponto
bool modifica_ponto(Ponto* p, float x, float y);

// fun��o para calcular a dist�ncia entre dois pontos
float distancia_entre_pontos(Ponto a, Ponto b);

// fun��o para exibir as coordenadas de um ponto
void imprime_ponto(Ponto p);

//void libera_ponto(Ponto* p); !n�o precisa alocar dinamicamente!
//bool acessa_ponto(Ponto p, float* x, float* y); !j� temos acesso direto!

#endif