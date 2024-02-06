#include <iostream>
#include "prototipos.h"
using namespace std;

int main(void) {

	// criando vetor com 3 elementos
	Vetor* igo = cria_vetor(3);

	// adicionando elementos ao vetor
	seta_vetor(igo, 0, 10);
	seta_vetor(igo, 1, 20);
	seta_vetor(igo, 2, 30);

	// exibindo vetor
	print_vetor(igo);

	// criando ponteiro para guardar valor da segunda posição
	float* valor;
	float value = 1.1;
	valor = &value;

	// pagando o valor da segunda posição e exibindo
	pega_vetor(igo, 1, valor);
	cout << "Valor 1=" << *valor << endl;

	// extrapolando o tamanho do vetor para realocar
	seta_vetor(igo, 3, 40);

	// exibindo vetor realocado
	print_vetor(igo);

	// liberando espaço de memória
	libera_vetor(&igo);

	return 0;
}