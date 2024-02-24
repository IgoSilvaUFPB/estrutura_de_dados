#include <iostream>

using std::cout;
using std::cin;

void wait() {
    char i = ' ';
    while (i != '\n') {
        cin.get(i);
    }
}

int main() {
    int ar[] = { 10, 15, 4, 25, 3, -4 };
    int* p = &ar[2];

    cout << "======== EXERCITANDO PONTEIROS ========\n\n";
    cout << "->       Tecle ENTER para revelar a resposta e continuar       <-\n";
    cout << "-> O ponteiro eh retornado a posicao original a cada altenativa <-\n";
    cout << "->           Lembre-se que um inteiro ocupa 4 bytes!           <-\n\n";

    cout << "Quais sao os resultados das avaliacoes das seguintes expressoes?\n\n";
    cout << "Sempre considere:\nint ar[] = {10, 15, 4, 25, 3, -4};\nint *p = &ar[2];\n\n";

    cout << "(a) *(p + 1)";
    wait();
    cout << "Resposta: " << *(p + 1) << "\n";
    wait();
    cout << "(b) p[-1]";
    wait();
    cout << "Resposta: " << p[-1] << "\n";
    wait();
    cout << "(c) ar[*p++]";
    wait();
    cout << "Resposta: " << ar[*(p++)] << "\n";
    p--;
    wait();
    cout << "(d) *(ar + ar[2])";
    wait();
    cout << "Resposta: " << *(ar + ar[2]) << "\n";
    cout << "ar = " << ar << "\n";
    cout << "ar[2] = " << ar[2] << "\n";
    wait();
    cout << "(e) (&ar[4] - p)";
    wait();
    cout << "Resposta: " << (&ar[4] - p) << "\n";
    cout << "&ar[4] = " << &ar[4] << "\n";
    cout << "p = " << p << "\n";
    wait();
    cout << "(f) sizeof(ar) / sizeof(ar[0])";
    wait();
    cout << "Resposta: " << sizeof(ar) / sizeof(ar[0]) << "\n";
    cout << "sizeof(ar) = " << sizeof(ar) << "\n";
    cout << "sizeof(ar[0]) = " << sizeof(ar[0]) << "\n";
    wait();
    cout << "(g) p - ar";
    wait();
    cout << "Resposta: " << p - ar << "\n";
    cout << "p = " << p << "\n";
    cout << "ar = " << ar << "\n";
    wait();
    cout << "(h) &p";
    wait();
    cout << "Resposta: " << &p << " ou " << static_cast<void*>(&p) << "(hexadecimal)\n";
    wait();
    cout << "(i) ar[p - ar]";
    wait();
    cout << "Resposta: " << ar[p - ar] << "\n";
    cout << "p = " << p << "\n";
    cout << "ar = " << ar << "\n";
    wait();
    cout << "(j) ar + 3";
    wait();
    cout << "Resposta: " << ar + 3 << "\n";
    cout << "ar = " << ar << "\n";
    wait();
    cout << "(k) *(p += 1)";
    wait();
    cout << "Resposta: " << *(p += 1) << "\n";
    p--;
    wait();
    cout << "(l) *(ar + 2)";
    wait();
    cout << "Resposta: " << *(ar + 2) << "\n";
    wait();
    cout << "(m) ar[ar[4]]";
    wait();
    cout << "Resposta: " << ar[ar[4]] << "\n";
    wait();
    cout << "(n) (*p)--";
    wait();
    cout << "Resposta: " << (*p)-- << "\n";
    cout << "*p = " << *p << " devido ao pos-decremento.\n";
    *p = 4;
    wait();
    cout << "(o) *(ar + (*p - ar[4]))";
    wait();
    cout << "Resposta: " << *(ar + (*p - ar[4])) << "\n";
    cout << "ar[4] = " << ar[4] << "\n";
    cout << "*p = " << *p << "\n";
    wait();
    cout << "(p) *(++p)";
    wait();
    cout << "Resposta: " << *(++p) << "\n";
    p--;
    cout << "*p = " << *p << "\n";
    wait();
    cout << "(q) &ar[2]";
    wait();
    cout << "Resposta: " << &ar[2] << "\n";
    wait();
    cout << "(r) *(ar + (p - &ar[2]))";
    wait();
    cout << "Resposta: " << *(ar + (p - &ar[2])) << "\n";
    cout << "&ar[2] = " << &ar[2] << "\n";
    cout << "p = " << p << "\n";
    wait();
    cout << "(s) ar[p - &ar[0]]";
    wait();
    cout << "Resposta: " << ar[p - &ar[0]] << "\n";
    cout << "&ar[0] = " << &ar[0] << "\n";
    cout << "p = " << p << "\n";
    wait();
    cout << "Exercicio terminado.\n\n";
    cout << "---------------------------------------------------------------\n";
    cout << "Igo Silva - Ciencia de Dados e Inteligencia Artificial";
    return 0;
}
