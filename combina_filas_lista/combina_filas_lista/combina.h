#ifndef COMBINA_H
#define COMBINA_H

typedef struct fila Fila;
typedef struct no No;

Fila* cria_fila(void);
No* cria_no(float info);
void libera_fila(Fila** f);
bool entra_fila(Fila* f, float v);
void imprime_fila(Fila* f);
bool sai_fila(Fila* f, float* v);
bool combina_filas(Fila* res, Fila* f1, Fila* f2);

#endif
