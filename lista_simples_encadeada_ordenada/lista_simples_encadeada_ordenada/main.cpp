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
        cout << "LISTA SIMPLESMENTE ENCADEADA ORDENADA" << endl;
        int t = tamanho_lista(l);
        cout << "Tamanho da lista: " << t << endl;

        // exibe a lista
        imprime_lista(l);

        // exibir menu
        cout << "MENU" << endl;
        cout << "1 - Inserir info" << endl;
        cout << "2 - Remover info" << endl;
        cout << "3 - Modificar info" << endl;
        cout << "4 - Sair" << endl;
        cout << "O que deseja fazer?" << endl;
        cin >> opcao;

        // tratar opcao
        switch (opcao) {
        case 1:
            cout << "Inserir info" << endl;
            cout << "Digite a info: ";
            cin >> info;
            insere_info(l, info);
            opcao = 0;
            break;
        case 2:
            cout << "Remover info" << endl;
            cout << "Digite a info: ";
            cin >> info;
            remove_info(l, info);
            opcao = 0;
            break;
        case 3:
            cout << "Modificar info" << endl;
            cout << "Digite a info: ";
            cin >> info;
            cout << "Digite a nova info: ";
            cin >> nova_info;
            modifica_info(l, info, nova_info);
            opcao = 0;
            break;       
        case 4:
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