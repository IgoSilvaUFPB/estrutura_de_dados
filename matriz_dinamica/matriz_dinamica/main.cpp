#include <iostream>
#include "prototipos_matriz.h"

using namespace std;

int main(void) {
	int linhas = 3, colunas = 3;
	Matriz* matriz = cria_matriz(linhas, colunas);
	preenche_matriz(matriz);
	exibe_matriz(matriz);
	int linha = 1, coluna = 2;
	float copia = 0;
	float valor = 3.14;
	modifica_elemento(matriz, linha, coluna, valor);
	acessa_elemento(matriz, linha, coluna, &copia);
	cout << "Copia:" << copia << endl;
	exibe_matriz(matriz);
	destroi_matriz(&matriz);

	return 0;
}