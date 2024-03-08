#include <iostream>
#include "prototipos.h"

using std::cout;
using std::endl;

No* cria_no(int info) {
    No* n = (No*)malloc(sizeof(No));
    if (!n) {
        return NULL;
    }
    n->info = info;
    n->prox = NULL;
    return n;
}

Lista* cria_lista() {
    Lista* l = (Lista*)malloc(sizeof(Lista));
    if (!l) {
        return NULL;
    }
    l->inicio = NULL;
    return l;
}

int tamanho_lista(Lista* l) {
    if (!l) {
        return 0;
    }
    int i = 0;
    No* aux = l->inicio;
    if (aux == NULL) {
		return 0;
	}
    while (aux->prox) {
        aux = aux->prox;
        i++;
    }
    return i;
}

bool insere_inicio(Lista* l, int info) {
    if (!l) {
        return false;
    }
    No* n = cria_no(info);
    if (!n) {
        return false;
    }
    n->prox = l->inicio;
    l->inicio = n;
    return true;
}

bool insere_meio(Lista* l, int info, int pos)
{
    if (!l) {
        return false;
    }
    int s = tamanho_lista(l);
    if (l->inicio == NULL && pos == 0) {
        return insere_inicio(l, info);
    }
    if (pos < 0 || pos >= s) {
        return false;
    }
    if (pos == 0) {
        return insere_inicio(l, info);
    }
    if (pos == s) {
        return insere_fim(l, info);
    }
    if (s == 1 && pos == 0) {
        return insere_inicio(l, info);
    }
    No* aux = l->inicio;
    int i = 0;
    while (i < pos - 1) {
        aux = aux->prox;
        i++;
    }
    No* novo_no = cria_no(info);
    if (!novo_no) {
        return false;
    }
    novo_no->prox = aux->prox;
    aux->prox = novo_no;
    return true;
};

bool insere_fim(Lista* l, int info) {
    if (!l) {
        return false;
    }
    if (l->inicio == NULL) {
        return insere_inicio(l, info);
    }
    No* aux = l->inicio;
    while (aux->prox != NULL) {
        aux = aux->prox;
    }
    aux->prox = cria_no(info);
    return(aux->prox != NULL);
}

bool remove_inicio(Lista* l) {
    if (!l) {
        return false;
    }
    if (l->inicio == NULL) {
        return false;
    }
    No* aux = l->inicio->prox;
    free(l->inicio);
    l->inicio = aux;
    return true;
}

bool remove_meio(Lista* l, int pos)
{
    if (!l) {
        return false;
    }
    if (l->inicio == NULL) {
        return false;
    }
    No* aux1 = l->inicio;
    No* aux2 = l->inicio;
    for (int i = 0; i < (pos - 1); i++) {
        aux1 = aux1->prox;
        aux2 = aux2->prox;
    }
    aux2 = aux2->prox->prox;
    free(aux1->prox);
    aux1->prox = aux2;
    return true;

};

bool remove_fim(Lista* l) {
    if (!l) {
        return false;
    }
    if (l->inicio == NULL) {
        return false;
    }
    No* aux = l->inicio;
    while (aux->prox->prox != NULL) {
        aux = aux->prox;
    }
    free(aux->prox);
    aux->prox = NULL;
    return true;
}

bool remove_info(Lista* l, int info) {
    if (!l) {
        return false;
    }
    // caso a lista esteja vazia
    if (l->inicio == NULL) {
        return false;
    }
    int s = tamanho_lista(l);
    No* aux1 = l->inicio;
    No* aux2 = l->inicio;
    // caso só tenha um elemento
    if (s == 1 && aux1->info == info) {
        remove_fim(l);
        return true;
    }
    //se o primeiro for igual
    if (aux1->info == info) {
        remove_inicio(l);
        return true;
    }
    while (aux1->prox->info != info) {
        aux1 = aux1->prox;
    }
    aux2 = aux1->prox;
    aux1->prox = aux2->prox;
    free(aux2);
    return true;
}

bool remove_info_all(Lista* l, int info) {
    if (!l) {
        return false;
    }
    // lista vazia
    if (l->inicio == NULL) {
        return false;
    }
    int s = tamanho_lista(l);
    cout << "tamanho da lista: " << s << endl;
    No* aux1 = l->inicio;
    No* aux2 = l->inicio;
    // só um elemento
    if (s == 1 && aux1->info == info) {
        remove_fim(l);
        return true;
    }
    // removendo o primeiro enquanto igual
    while (l->inicio->info == info) {
        cout << "removido do inicio" << endl;
        remove_inicio(l);
        // necessário atualizar o aux1 se o primeiro for removido
        aux1 = l->inicio;
    }
    // removendo até o final
    while (aux1->prox != NULL) {
        cout << "entrou no while" << endl;
        cout << "aux1->info: " << aux1->info << endl;
        cout << "aux1->prox->info: " << aux1->prox->info << endl;
        if (aux1->prox->info == info) {
            cout << "removendo: " << aux1->prox->info << endl;
			aux2 = aux1->prox;
			aux1->prox = aux2->prox;
			free(aux2);
		}
        else {
			aux1 = aux1->prox;
            cout << "nada removido" << endl;
		}
	}
    return true;
}

No* busca_no(Lista* l, int info) {
    if (!l) {
        return NULL;
    }
    No* aux = l->inicio;
    while (aux != NULL) {
        if (aux->info == info) {
            return aux;
        }
        aux = aux->prox;
    }
    return NULL;
}

bool modifica_no(Lista* l, int info, int novo_info) {
    No* aux = busca_no(l, info);
    if (!aux) {
        return false;
    }
    aux->info = novo_info;
    return true;
}

void imprime_lista(Lista* l) {
    if (!l) {
        return;
    }
    No* aux = l->inicio;
    while (aux != NULL) {
        cout << "[" << aux->info << "] ";
        aux = aux->prox;
    }
    cout << endl;
}

void libera_lista(Lista** l) {
    if (!(*l)) {
        return;
    }
    while ((*l)->inicio != NULL) {
        remove_inicio(*l);
    }
    free(*l);
    *l = NULL;
}