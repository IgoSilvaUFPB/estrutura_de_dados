typedef struct vetor Vetor;
Vetor* cria_vetor(int n);
void libera_vetor(Vetor** v);
bool seta_vetor(Vetor* v, int pos, float valor);
bool pega_vetor(Vetor* v, int pos, float* valor);
void print_vetor(Vetor* v);
bool reescalona_vetor(Vetor* v, int n);