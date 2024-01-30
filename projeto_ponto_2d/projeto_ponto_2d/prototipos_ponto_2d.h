#ifndef PROTOTIPOS_PONTO_2D_H
#define PROTOTIPOS_PONTO_2D_H

// definição da estrutura
struct Ponto {
	float x;
	float y;
};
/*
NÃO CONSEGUI DESCOBRIR UM JEITO DE FAZER A DEFINIÇÃO DO STRUCT NO ARQUIVO .CPP
AO INVÉS DE AQUI NO .H. SEMPRE DAVA UM ERRO COMO SE NÃO IDENTIFICASSE O STRUCT LÁ.
*/

// função para cria pontos
Ponto cria_ponto(float x, float y);

// função para modificar as coordenadas de um ponto
bool modifica_ponto(Ponto* p, float x, float y);

// função para calcular a distância entre dois pontos
float distancia_entre_pontos(Ponto a, Ponto b);

// função para exibir as coordenadas de um ponto
void imprime_ponto(Ponto p);

// função para extrair coordenadas do ponto
bool acessa_ponto(Ponto p, float* x, float* y);

#endif