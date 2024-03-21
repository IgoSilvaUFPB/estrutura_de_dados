#include <iostream>
#include "prototipos.h"

using std::cout;
using std::endl;
using std::cin;

int main(void) {    
    Lista* l = cria_lista();
    int opcao = 0, pos = 0, info = 0, nova_info = 0;
    while (opcao == 0) {
        // limpa a tela
        system("cls");

        // exibe o titulo
        cout << "LISTA SIMPLESMENTE ENCADEADA" << endl;
        int t = tamanho_lista(l);
        cout << "Tamanho da lista: " << t << endl;

        // exibe a lista
        imprime_lista(l);

        // exibir menu
        cout << "MENU" << endl;
        cout << "1 - Inserir no inicio" << endl;
        cout << "2 - Inserir no fim" << endl;
        cout << "3 - Inserir no meio" << endl;
        cout << "4 - Remover no inicio" << endl;
        cout << "5 - Remover no fim" << endl;
        cout << "6 - Remover no meio" << endl;
        cout << "7 - Modificar info" << endl;
        cout << "8 - Remover info" << endl;
        cout << "9 - Remover todas as ocorrencias de info" << endl;
        cout << "10 - Sair" << endl;
        cout << "O que deseja fazer?" << endl;
        cin >> opcao;

        // tratar opcao
        switch (opcao) {
            case 1:
                cout << "Inserir no inicio" << endl;
                cout << "Digite a info: ";
                cin >> info;
                insere_inicio(l, info);
                opcao = 0;
				break;
			case 2:
				cout << "Inserir no fim" << endl;
                cout << "Digite a info: ";
                cin >> info;
                insere_fim(l, info);
                opcao = 0;
				break;
			case 3:
				cout << "Inserir no meio" << endl;
                cout << "Digite a info: ";
				cin >> info;
				cout << "Digite a posicao: ";
				cin >> pos;
				insere_meio(l, info, pos);
				opcao = 0;
				break;
			case 4:
				cout << "Remover no inicio" << endl;
                remove_inicio(l);
                opcao = 0;
				break;
			case 5:
				cout << "Remover no fim" << endl;
                remove_fim(l);
                opcao = 0;
				break;
			case 6:
				cout << "Remover no meio" << endl;
                cout << "Digite a posicao: ";
                cin >> pos;
                remove_meio(l, pos);
				opcao = 0;
				break;
			case 7:
				cout << "Modificar info" << endl;
                cout << "Digite a info: ";
                cin >> info;
                cout << "Digite a nova info: ";
                cin >> nova_info;
                modifica_no(l, info, nova_info);
                opcao = 0;
				break;
			case 8:
				cout << "Remover info" << endl;
                cout << "Digite a info: ";
                cin >> info;
                remove_info(l, info);
                opcao = 0;
				break;
			case 9:
				cout << "Remover todas as ocorrencias de info" << endl;
                cout << "Digite a info: ";
				cin >> info;
				remove_info_all(l, info);
				opcao = 0;
				break;
			case 10:
				cout << "Sair" << endl;
				break;
			default:
				cout << "Opcao invalida" << endl;
				break;            
        }        
    }

    // libera lista
    libera_lista(&l);
    return 0;
}