#ifndef PROTOTIPOS_PONTO_2D_H
#define PROTOTIPOS_PONTO_2D_H

// cria tipo Ponto com base no struct
typedef struct ponto Ponto;

// fun��o para cria pontos
Ponto* cria_ponto(float x, float y);

// fun��o para modificar as coordenadas de um ponto
bool modifica_ponto(Ponto* p, float x, float y);

// fun��o para calcular a dist�ncia entre dois pontos
float distancia_entre_pontos(Ponto* a, Ponto* b);

// fun��o para exibir as coordenadas de um ponto
void imprime_ponto(Ponto* p);

// fun��o para extrair coordenadas do ponto
bool acessa_ponto(Ponto* p, float* x, float* y);

// fun��o para liberar espa�o de mem�ria
void libera_ponto(Ponto** p);

#endif