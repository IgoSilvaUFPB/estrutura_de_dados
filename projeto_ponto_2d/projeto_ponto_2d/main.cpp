#include <iostream>
#include "prototipos_ponto_2d.h"
using namespace std;

int main(void) {

	// inicialização dos pontos
	float xa = 0, ya = 0, xb = 0, yb = 0;
	cout << "DISTANCIA ENTRE PONTOS 2D" << endl;
	cout << "Informe a coordenada x do ponto A" << endl;
	cin >> xa;
	cout << "Informe a coordenada y do ponto A" << endl;
	cin >> ya;
	cout << "Informe a coordenada x do ponto B" << endl;
	cin >> xb;
	cout << "Informe a coordenada y do ponto B" << endl;
	cin >> yb;

	// cria ponto 1
	Ponto ptA = cria_ponto(xa, ya);

	// cria ponto 2
	Ponto ptB = cria_ponto(xb, yb);

	// variável de controle para saída do loop
	int i = 0;

	do {
		// calcula e exibe distancia entre os pontos
		float dist = distancia_entre_pontos(ptA, ptB);
		cout << "A distancia entre os pontos A e B: " << dist << endl;

		// inicializa variáveis
		int menu = 0;
		float nxa = 0, nya = 0, nxb = 0, nyb = 0, ptx = 0, pty = 0;

		// exibe menu
		cout << "== OPCOES ==" << endl;
		cout << "1. Alterar coordenadas do ponto A" << endl;
		cout << "2. Alterar coordenadas do ponto B" << endl;
		cout << "3. Acessar x do ponto A" << endl;
		cout << "4. Acessar y do ponto A" << endl;
		cout << "5. Acessar x do ponto B" << endl;
		cout << "6. Acessar y do ponto B" << endl;
		cout << "7. Exibir coordenadas do ponto A" << endl;
		cout << "8. Exibir coordenadas do ponto B" << endl;
		cout << "9. Sair do programa" << endl;
		cin >> menu;

		// limpa tela
		system("cls");

		// alterna conforme opção selecionada
		switch (menu) {
		case(1):
			// alterar coordenadas do ponto A
			cout << "indique a coordenada x do ponto A" << endl;
			cin >> nxa;
			cout << "indique a coordenada y do ponto A" << endl;
			cin >> nya;
			modifica_ponto(&ptA, nxa, nya);
			break;
		case(2):
			// altera coordenadas do ponto B
			cout << "indique a coordenada x do ponto B" << endl;
			cin >> nxb;
			cout << "indique a coordenada y do ponto B" << endl;
			cin >> nyb;
			modifica_ponto(&ptB, nxb, nyb);
			break;
		case(3):
			// acessar x do ponto A
			acessa_ponto(ptA, &ptx, &pty);
			cout << "coordenada x do ponto A: " << ptx << endl;
			break;
		case(4):
			// acessar y do ponto A
			acessa_ponto(ptA, &ptx, &pty);
			cout << "coordenada y do ponto A: " << pty << endl;
			break;
		case(5):
			// acessar x do ponto B
			acessa_ponto(ptB, &ptx, &pty);
			cout << "coordenada x do ponto B: " << ptx << endl;
			break;
		case(6):
			// acessar y do ponto B
			acessa_ponto(ptB, &ptx, &pty);
			cout << "coordenada y do ponto B: " << pty << endl;
			break;
		case(7):
			// exibir coordenadas do ponto A
			imprime_ponto(ptA);
			break;
		case(8):
			// exibir coordenadas do ponto B
			imprime_ponto(ptB);
			break;
		case(9):
			// sair do programa
			i = 1;
			break;
		default:
			// alerta de opção inválida
			cout << "Opcao invalida!" << endl;
			break;
		}

	} while (i == 0);

	return 0;
}