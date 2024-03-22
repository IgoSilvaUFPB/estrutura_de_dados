#include <iostream>
#include "prototipos_funcoes.h"

using std::cout;
using std::endl;
using std::cin;

int main(void) {
	cout << "CALCULADOR DE NUMEROS COMPLEXOS" << endl;
	int op = 0;

	do {
		// menu
		cout << "Escolha uma operacao:" << endl;
		cout << "1. Soma/Subtacao" << endl;
		cout << "2. Multiplicacao" << endl;
		cout << "3. Divisao" << endl;
		cout << "4. Sair" << endl;
		cin >> op;

		// interrompe a iteracao em caso de saida
		if (op == 4) {
			continue;
		}

		// interrompe a iteracao em caso de opcao invalida
		if (op != 1 && op != 2 && op != 3) {
			cout << "Opcao invalida!" << endl;
			continue;
		}
		
		// variaveis dos operandos
		float ra, rb, ia, ib;

		// cria primerio complexo
		cout << "Informe a parte real do primeiro complexo: ";
		cin >> ra;
		cout << "Informe a parte imaginaria do primeiro complexo: ";
		cin >> ia;
		Complexo a = cria_complexo(ra, ia);
		cout << "O primeiro complexo eh ";
		exibe_complexo(a);
		cout << endl;

		// cria segundo complexo
		cout << "Informe a parte real do segundo complexo: ";
		cin >> rb;
		cout << "Informe a parte imaginaria do segundo complexo: ";
		cin >> ib;
		Complexo b = cria_complexo(rb, ib);
		cout << "O segundo complexo eh ";
		exibe_complexo(b);
		cout << endl;

		// alerta em caso de divisao por zero
		if (rb == 0 || ib == 0) {
			cout << "Esta divisao nao pode ser processada!" << endl;
			continue;
		}

		// realiza a operacao selecionada
		switch (op) {
		case 1:
			// somando/subtraindo complexos
			cout << "O resultado da soma/subtracao de ";
			exibe_complexo(a);
			cout << " e ";
			exibe_complexo(b);
			cout << " eh ";
			Complexo s = somasub(a, b);
			exibe_complexo(s);
			cout << endl << endl;
			break;
		case 2:
			// multiplicando complexos
			cout << "O resultado da multiplicacao de ";
			exibe_complexo(a);
			cout << " e ";
			exibe_complexo(b);
			cout << " eh ";
			Complexo m = multiplica(a, b);
			exibe_complexo(m);
			cout << endl << endl;
			break;
		case 3:
			// dividindo complexos
			cout << "O resultado da divisao de ";
			exibe_complexo(a);
			cout << " por ";
			exibe_complexo(b);
			cout << " eh ";
			Complexo d = divide(a, b);
			exibe_complexo(d);
			cout << endl << endl;
			break;
		default:
			// alerta para opcao invalida
			cout << "Opcao invalida!" << endl;
		}

	} while (op != 4);

	return 0;
}