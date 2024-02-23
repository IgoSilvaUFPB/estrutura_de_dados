#ifndef PROTOTIPOS_FUNCOES_H
#define PROTOTIPOS_FUNCOES_H

struct ncomplexo {
	float real;
	float img;
};

typedef struct ncomplexo Complexo;

// criando complexo
Complexo cria_complexo(float r, float i);

// exibindo n�mero complexo
void exibe_complexo(Complexo x);

// opera��o adic�o/subtra��o
Complexo somasub(Complexo a, Complexo b);

// multiplica complexos
Complexo multiplica(Complexo a, Complexo b);

// divide complexos
Complexo divide(Complexo a, Complexo b);

#endif