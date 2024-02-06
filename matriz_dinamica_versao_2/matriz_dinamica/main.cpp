#include <iostream>
#include "prototipos_matriz.h"

using namespace std;

int main(void) {
	// definição das dimensões da matriz
	int linhas = 3, colunas = 3;

	// criação da matriz
	Matriz* matriz = cria_matriz(linhas, colunas);

	// preenchimento da matriz
	preenche_matriz(matriz);

	// exibição da matriz
	exibe_matriz(matriz);

	int linha = 1, coluna = 2;
	float copia = 0;
	float valor = 3.14;

	// alteração de um elemento da matriz
	modifica_elemento(matriz, linha, coluna, valor);

	// acesso a um elemento da matriz
	acessa_elemento(matriz, linha, coluna, &copia);
	cout << "Copia:" << copia << endl;

	// exibição da matriz
	exibe_matriz(matriz);

	// liberação do espaço de memória alocado
	destroi_matriz(&matriz);

	return 0;
}