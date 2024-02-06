#ifndef PROTOTIPOS_MATRIZ_H
#define PROTOTIPOS_MATRIZ_H

// associa��o da estrutura ao nome do tipo
typedef struct matriz_dinamica Matriz;

// cria��o da matriz
Matriz* cria_matriz(int linhas, int colunas);

// preenchimento da matriz
bool preenche_matriz(Matriz* m);

// exibi��o da matriz inteira
void exibe_matriz(Matriz* m);

// acesso a um elemento da matriz
bool acessa_elemento(Matriz* m, int linha, int coluna, float* copia);

// mofifica��o de um elemento da matriz
bool modifica_elemento(Matriz* m, int linha, int coluna, float valor);

// libera��o do espa�o de mem�ria alocado
void destroi_matriz(Matriz** m);

#endif
