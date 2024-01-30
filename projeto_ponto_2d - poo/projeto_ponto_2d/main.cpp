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
	Ponto ptA(xa, ya);

	// cria ponto 2
	Ponto ptB(xb, yb);

	//variável de controle
	int i = 0;

	system("cls");

	do {
		
		// calcula e exibe distancia entre os pontos
		float dist = ptA.distancia_entre_pontos(ptB);
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
			system("cls");
			cout << "indique a coordenada x do ponto A" << endl;
			cin >> nxa;
			cout << "indique a coordenada y do ponto A" << endl;
			cin >> nya;
			ptA.modifica_ponto(nxa, nya);
			system("cls");
			break;
		case(2):
			system("cls");
			cout << "indique a coordenada x do ponto B" << endl;
			cin >> nxb;
			cout << "indique a coordenada y do ponto B" << endl;
			cin >> nyb;
			ptB.modifica_ponto(nxb, nyb);
			system("cls");
			break;
		case(3):
			system("cls");
			ptA.acessa_ponto(&ptx, &pty);
			cout << "coordenada x do ponto A: " << ptx << endl;
			break;
		case(4):
			system("cls");
			ptA.acessa_ponto(&ptx, &pty);
			cout << "coordenada y do ponto A: " << pty << endl;
			break;
		case(5):
			system("cls");
			ptB.acessa_ponto(&ptx, &pty);
			cout << "coordenada x do ponto B: " << ptx << endl;
			break;
		case(6):
			system("cls");
			ptB.acessa_ponto(&ptx, &pty);
			cout << "coordenada y do ponto B: " << pty << endl;
			break;
		case(7):
			system("cls");
			ptA.imprime_ponto();
			break;
		case(8):
			system("cls");
			ptB.imprime_ponto();
			break;
		case(9):
			i = 1;
			break;
		default:
			cout << "Opcao invalida!";
			break;
		}
		
	} while (i == 0);

	return 0;
}