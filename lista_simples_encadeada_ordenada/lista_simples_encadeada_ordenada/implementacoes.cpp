#ifndef IMPLEMENTACOES_CPP
#define IMPLEMENTACOES_CPP

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
    // inicializa a lista com NULL
    l->inicio = NULL;
    return l;
}

int tamanho_lista(Lista* l) {
    if (!l) {
        return 0;
    }
    int i = 0;
    No* aux = l->inicio;
    // se a lista estiver vazia, retorna 0
    if (aux == NULL) {
        return 0;
    }
    // se a lista tiver um elemento, retorna 1
    if (aux->prox == NULL) {
        return 1;
    }
    // percorre a lista até encontrar NULL
    i++;
    while (aux->prox != NULL) {
        aux = aux->prox;
        // incrementa o contador
        i++;
    }
    return i;
}

bool insere_info(Lista* l, int info) {
    if (!l) {
        return false;
    }    
    No* novo_no = cria_no(info);
    if (!novo_no) {
        return false;
    } 
    No* aux = l->inicio;
    // caso a lista esteja vazia
    if (aux == NULL) {
        l->inicio = novo_no;
        return true;
    }    
    // caso lista com um elemento e info menor
    if (aux->prox == NULL && info < aux->info) {
        novo_no->prox = aux;
        l->inicio = novo_no;
        return true;
    }
    // caso lista com um elemento e info maior
    if (aux->prox == NULL && info > aux->info) {
        aux->prox = novo_no;
        return true;
    }
    // inserindo no inicio
    if (info < aux->info) {
        l->inicio = novo_no;
        novo_no->prox = aux;
        return true;
    }
    // busca posição adequada na lista
    while (aux->prox != NULL && aux->prox->info < info) {
        aux = aux->prox;
    }
    // insere no final
    if (aux->prox == NULL) {
        aux->prox = novo_no;
        return true;
    }
    // insere no meio
    novo_no->prox = aux->prox;
    aux->prox = novo_no;
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
    No* aux1 = l->inicio;    
    // caso seja o primeiro
    if (aux1->info == info) {
        l->inicio = aux1->prox;
        free(aux1);
        return true;
    }
    // buscando info na lista
    while (aux1->prox != NULL && aux1->prox->info != info) {
        aux1 = aux1->prox;
    }
    // info não foi encontrada
    if (aux1->prox == NULL) {
        return false;
    }
    No* aux2 = l->inicio;
    // excluindo o nó
    aux2 = aux1->prox;
    aux1->prox = aux2->prox;
    free(aux2);
    return true;   
}

bool reordenar_lista(Lista* l) {
    if (!l) {
        return false;
    }
    // caso a lista esteja vazia
    if (l->inicio == NULL) {
        return false;
    }
    No* aux1 = l->inicio;
    No* aux2 = l->inicio;    
    // ordenando a lista
    while (true) {
        // se o primeiro for maior que o segundo
        while (l->inicio->info > l->inicio->prox->info) {
            l->inicio = aux1->prox;
            aux1->prox = aux1->prox->prox;
            l->inicio->prox = aux1;
            aux1 = l->inicio;
            aux2 = l->inicio;
        }
        // procurando inversões
        while (aux1->prox->info >= aux1->info && aux1->prox != NULL) {
            aux2 = aux1;
            aux1 = aux1->prox;
            // chegou ao final sem encontra inversões
            if (aux1->prox == NULL) {
                return true;
            }
        }
        // invertendo posições
        aux2->prox = aux1->prox;
        aux1->prox = aux1->prox->prox;
        aux2->prox->prox = aux1;
        aux1 = l->inicio;
        aux2 = l->inicio;
    }
    return true;
}

bool modifica_info(Lista* l, int info, int novo_info) {
    if (!l) {
        return false;
    }
    // caso a lista esteja vazia
    if (l->inicio == NULL) {
        return false;
    }
    No* aux = l->inicio;
    while (aux->info != info && aux->prox != NULL) {
        aux = aux->prox;
    }
    // info não foi encontrada
    if (aux->prox == NULL && aux->info != info) {
        return false;
    }
    // alterando info
    aux->info = novo_info;
    reordenar_lista(l);
    return true;
}

void imprime_lista(Lista* l) {
    if (!l) {
        return;
    }
    No* aux = l->inicio;
    if (tamanho_lista(l) == 0) {
        // exibe aviso de lista vazia
        cout << "[Lista vazia]" << endl;
    }
    else {
        // percorre a lista e imprimindo os elementos
        while (aux != NULL) {
            cout << "[" << aux->info << "] ";
            aux = aux->prox;
        }
    }
    cout << endl;
}

void libera_lista(Lista** l) {
    if (!(*l)) {
        return;
    }    
    // caso a lista esteja não vazia, remove os nós
    if ((*l)->inicio != NULL) {
        int s = tamanho_lista(*l);
        No* aux = (*l)->inicio;
        for (int i = 0; i < s; i++) {
            (*l)->inicio = aux->prox;
            free(aux);
            aux = (*l)->inicio;
        }
    }
    // libera a lista
    free(*l);
    *l = NULL;
}

#endif