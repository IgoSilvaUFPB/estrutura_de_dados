#ifndef PROTOTIPOS_MATRIZ_H
#define PROTOTIPOS_MATRIZ_H

// associação da estrutura ao nome do tipo
typedef struct matriz_dinamica Matriz;

// criação da matriz
Matriz* cria_matriz(int linhas, int colunas);

// preenchimento da matriz
bool preenche_matriz(Matriz* m);

// exibição da matriz inteira
void exibe_matriz(Matriz* m);

// acesso a um elemento da matriz
bool acessa_elemento(Matriz* m, int linha, int coluna, float* copia);

// mofificação de um elemento da matriz
bool modifica_elemento(Matriz* m, int linha, int coluna, float valor);

// liberação do espaço de memória alocado
void destroi_matriz(Matriz** m);

#endif
