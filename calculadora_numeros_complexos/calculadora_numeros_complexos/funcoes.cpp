#ifndef FUNCOES_CPP
#define FUNCOES_CPP

#include <iostream>
#include "prototipos_funcoes.h"

using std::cout;
using std::endl;

// criando complexo
Complexo cria_complexo(float r, float i) {
	Complexo num;
	num.real = r;
	num.img = i;
	return num;
}

// exibindo número complexo
void exibe_complexo(Complexo x) {
	if (x.img >= 0) {
		cout << x.real << "+" << x.img << "i";
	}
	else {
		cout << x.real << x.img << "i";
	}
}

// operação adicão/subtração
Complexo somasub(Complexo a, Complexo b) {
	Complexo resultado;

	resultado.real = a.real + b.real;
	resultado.img = a.img + b.img;

	return resultado;
}

// multiplica complexos
Complexo multiplica(Complexo a, Complexo b) {
	Complexo resultado;

	resultado.real = (a.real * b.real) - (a.img * b.img);
	resultado.img = (a.real * b.img) + (a.img * b .real);

	return resultado;
}

// divide complexos
Complexo divide(Complexo a, Complexo b) {
	Complexo resultado;

	resultado.real = ((a.real * b.real) + (a.img * b.img)) / ((b.real * b.real) + (b.img * b.img));
	resultado.img = ((b.real * a.img)-(a.real * b.img)) / ((b.real * b.real) + (b.img * b.img));

	return resultado;
}


#endif