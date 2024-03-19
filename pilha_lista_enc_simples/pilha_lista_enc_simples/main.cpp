#include "lista.h"
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main(void) {
	Pilha* p = cria_pilha();
	int valor;
	int info = 0;
	bool x;

	cout << "PILHA EM LISTA ENCADEADA SIMPLES" << endl;
	int opcao = 0;
	while (opcao != 3) {
		cout << endl << "MENU DE OPCOES" << endl;
		cout << "1. Empilhar" << endl;
		cout << "2. Desempilhar" << endl;
		cout << "3. Sair" << endl;
		cout << "Digite a opcao: ";
		cin >> opcao;
		switch (opcao) {
		case 1 :			
			cout << "Digite o valor a ser empilhado: ";
			cin >> info;
			x = empilha(p, info);
			if (!x) {
				cout << "Empilhagem falhou...a pilha pode estar cheia." << endl;
			}
			break;
		case 2:
			desempilha(p, &valor);
			cout << "Valor desempilhado: " << valor << endl;
			break;
		case 3:
			cout << "Saindo do programa..." << endl;
			break;
		default:
			cout << "Digite uma opcao valida!" << endl;
		}
		cout << endl;
		imprime_pilha(p);
		cout << "Tamanho da pilha: " << tamanho_pilha(p) << endl;
	}
	libera_pilha(&p);
	/*
	empilha(p, 14);
	empilha(p, 5);
	empilha(p, 77);
	empilha(p, 8);
	empilha(p, 23);
	empilha(p, 45);
	empilha(p, 61);
	empilha(p, 38);
	imprime_pilha(p);
	cout << "Tamanho da pilha: " << tamanho_pilha(p) << endl;
	int valor;
	desempilha(p, &valor);
	cout << "Valor desempilhado: " << valor << endl;
	imprime_pilha(p);
	cout << "Tamanho da pilha: " << tamanho_pilha(p) << endl;
	libera_pilha(&p);
	*/
	return 0;
}
