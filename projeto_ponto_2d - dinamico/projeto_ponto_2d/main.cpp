#include <iostream>
#include "prototipos_ponto_2d.h"
using namespace std;

int main(void) {

	// inicialização dos pontos
	float xa=0, ya=0, xb=0, yb=0;
	cout << "DISTANCIA ENTRE PONTOS 2D" << endl;
	cout << "indique a coordenada x do ponto A" << endl;
	cin >> xa;
	cout << "indique a coordenada y do ponto A" << endl;
	cin >> ya;
	cout << "indique a coordenada x do ponto B" << endl;
	cin >> xb;
	cout << "indique a coordenada y do ponto B" << endl;
	cin >> yb;

	// cria ponto 1
	Ponto* ptA = cria_ponto(xa, ya);

	// cria ponto 2
	Ponto* ptB = cria_ponto(xb, yb);

	//variável de controle
	int i = 0;

	do {

		// calcula e exibe distancia entre os pontos
		float dist = distancia_entre_pontos(ptA, ptB);
		cout << "A distancia entre os pontos A e B: " << dist << endl;

		int menu = 0;
		float nxa = 0, nya = 0, nxb = 0, nyb = 0;
		float ptx=0, pty=0;

		cout << "== OPCOES ==" << endl;
		cout << "1. Quero alterar o ponto A" << endl;
		cout << "2. Quero alterar o ponto B" << endl;
		cout << "3. Acessar x do ponto A" << endl;
		cout << "4. Acessar y do ponto A" << endl;
		cout << "5. Acessar x do ponto B" << endl;
		cout << "6. Acessar y do ponto B" << endl;
		cout << "7. Exibir coordenadas do ponto A" << endl;
		cout << "8. Exibir coordenadas do ponto B" << endl;
		cout << "9. Sair" << endl;
		cin >> menu;

		switch(menu) {
		case(1):			
			cout << "indique a coordenada x do ponto A" << endl;
			cin >> nxa;
			cout << "indique a coordenada y do ponto A" << endl;
			cin >> nya;
			modifica_ponto(ptA, nxa, nya);
			break;
		case(2):
			cout << "indique a coordenada x do ponto B" << endl;
			cin >> nxb;
			cout << "indique a coordenada y do ponto B" << endl;
			cin >> nyb;
			modifica_ponto(ptB, nxb, nyb);
			break;
		case(3):
			acessa_ponto(ptA, &ptx, &pty);
			cout << "coordenada x do ponto A: " << ptx << endl;
			break;
		case(4):
			acessa_ponto(ptA, &ptx, &pty);
			cout << "coordenada y do ponto A: " << pty << endl;
			break;
		case(5):
			acessa_ponto(ptB, &ptx, &pty);
			cout << "coordenada x do ponto B: " << ptx << endl;
			break;
		case(6):
			acessa_ponto(ptB, &ptx, &pty);
			cout << "coordenada y do ponto B: " << pty << endl;
			break;
		case(7):
			imprime_ponto(ptA);
			break;
		case(8):
			imprime_ponto(ptB);
			break;
		case(9):
			i = 1;
			break;
		default:
			cout << "Opcao invalida!";
			break;
		}
	} while (i == 0);

	libera_ponto(&ptA);

	libera_ponto(&ptB);

	return 0;
}