#include <iostream>
#include "prototipos_matriz.h"

using namespace std;

int main(void) {
	// defini��o das dimens�es da matriz
	int linhas = 3, colunas = 3;

	// cria��o da matriz
	Matriz* matriz = cria_matriz(linhas, colunas);

	// preenchimento da matriz
	preenche_matriz(matriz);

	// exibi��o da matriz
	exibe_matriz(matriz);

	int linha = 1, coluna = 2;
	float copia = 0;
	float valor = 3.14;

	// altera��o de um elemento da matriz
	modifica_elemento(matriz, linha, coluna, valor);

	// acesso a um elemento da matriz
	acessa_elemento(matriz, linha, coluna, &copia);
	cout << "Copia:" << copia << endl;

	// exibi��o da matriz
	exibe_matriz(matriz);

	// libera��o do espa�o de mem�ria alocado
	destroi_matriz(&matriz);

	return 0;
}