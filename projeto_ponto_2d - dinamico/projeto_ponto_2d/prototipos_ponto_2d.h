#ifndef PROTOTIPOS_PONTO_2D_H
#define PROTOTIPOS_PONTO_2D_H

typedef struct ponto Ponto;

// função para cria pontos
Ponto* cria_ponto(float x, float y);

// função para modificar as coordenadas de um ponto
bool modifica_ponto(Ponto* p, float x, float y);

// função para calcular a distância entre dois pontos
float distancia_entre_pontos(Ponto* a, Ponto* b);

// função para exibir as coordenadas de um ponto
void imprime_ponto(Ponto* p);

void libera_ponto(Ponto** p);

bool acessa_ponto(Ponto* p, float* x, float* y);

#endif