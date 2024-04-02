#ifndef COMBINA_FILAS_H
#define COMBINA_FILAS_H

typedef struct fila Fila;
Fila* fila_cria(void);
void fila_insere(Fila* f, float v);
float fila_retira(Fila* f);
int fila_vazia(Fila* f);
void fila_libera(Fila** f);
void imprime_fila(Fila* f);
void combina_filas(Fila* f_res, Fila* f1, fila* f2);

#endif
