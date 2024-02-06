#include <iostream>
#include "prototipos.h"
using namespace std;

struct vetor {
	float* valor;
	int n;
};

Vetor* cria_vetor(int n) {
	Vetor* v = (Vetor*)malloc(sizeof(Vetor));
	if (v) {
		v->valor = (float*)malloc(n * sizeof(float));
		if (v->valor) {
			v->n = n;
			return v;
		}
		free(v);
	}
	return NULL;
}

void libera_vetor(Vetor** v) {
	if (*v) {
		free((*v)->valor);
		free(*v);
		*v = NULL;
	}
}

bool seta_vetor(Vetor* v, int pos, float valor) {
	if (!v || pos < 0)
		return false;
	if (pos >= v->n)
		if (!reescalona_vetor(v, pos + 1))
			return false;
	v->valor[pos] = valor;
	return true;
}

bool pega_vetor(Vetor* v, int pos, float* valor) {
	if (!v || pos < 0 || pos >= v->n || !valor || !v)
		return false;
	*valor = v->valor[pos];
	return true;
}

void print_vetor(Vetor* v) {
	if (!v)
		return;
	for (int i = 0; i < v->n; i++)
		cout << v->valor[i] << "-";
	cout << endl;
}

bool reescalona_vetor(Vetor * v, int n) {
	if (!v || n < v->n)
		return false;
	float* nv = (float*) realloc(v->valor, n*sizeof(float));
	if (nv) {
		v->valor = nv;
		v->n = n;
		return true;
	}
	return false;
}