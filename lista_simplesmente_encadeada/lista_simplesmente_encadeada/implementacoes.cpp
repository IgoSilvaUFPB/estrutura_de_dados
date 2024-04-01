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
    // verifica o tamanho da lista
    int s = tamanho_lista(l);
    // se a lista estiver vazia e a posição for maior ou igual a zero, insere no inicio
    if (l->inicio == NULL && pos >= 0) {
        return insere_inicio(l, info);
    }
    // se a posição for menor que zero ou maior que o tamanho da lista, retorna falso
    if (pos < 0 || pos >= s) {
        return false;
    }
    // se a posição for zero, insere no inicio
    if (pos == 0) {
        return insere_inicio(l, info);
    }
    // se a posição for igual ao tamanho da lista, insere no fim
    if (pos == s) {
        return insere_fim(l, info);
    }
    // se a lista tiver um elemento e a posição for zero, insere no inicio
    if (s == 1 && pos == 0) {
        return insere_inicio(l, info);
    }
    No* aux = l->inicio;
    No* novo_no = cria_no(info);
    if (!novo_no) {
        return false;
    }
    // percorre a lista até a posição desejada
    for (int i = 0; i < (pos - 1); i++) {
		aux = aux->prox;
	}    
    novo_no->prox = aux->prox;
    aux->prox = novo_no;
    return true;
};

bool insere_fim(Lista* l, int info) {
    if (!l) {
        return false;
    }
    // se a lista estiver vazia, insere no inicio
    if (l->inicio == NULL) {
        return insere_inicio(l, info);
    }
    No* aux = l->inicio;
    // percorre a lista até encontrar NULL
    while (aux->prox != NULL) {
        aux = aux->prox;
    }
    // cria um novo nó e insere no final
    aux->prox = cria_no(info);
    // verifica se o novo nó foi criado
    return(aux->prox != NULL);
}

bool remove_inicio(Lista* l) {
    if (!l) {
        return false;
    }
    // se a lista estiver vazia, retorna falso
    if (l->inicio == NULL) {
        return false;
    }
    No* aux = l->inicio->prox;
    free(l->inicio);
    l->inicio = aux;
    return true;
}

bool remove_meio(Lista* l, int pos) {
    if (!l) {
        return false;
    }
    // se a lista estiver vazia, retorna falso
    if (l->inicio == NULL) {
        return false;
    }
    int s = tamanho_lista(l);
    // se a posição for menor que zero ou maior que o tamanho da lista, retorna falso
    if (pos < 0 || pos > s) {
		return false;
	}
    // se a posição for a mesma do tamanho da lista, remove o último
    if (pos == s) {
        remove_fim(l);
    }    
    // remocao do primeiro elemento
    if (pos == 0) {
		remove_inicio(l);
		return true;
	}
    No* aux1 = l->inicio;
    No* aux2 = l->inicio;
    // percorre a lista até a posição desejada
    for (int i = 0; i < (pos - 1); i++) {
        aux1 = aux1->prox;
    }
    aux2 = aux1->prox->prox;
    free(aux1->prox);
    aux1->prox = aux2;
    return true;

};

bool remove_fim(Lista* l) {
    if (!l) {
        return false;
    }
    // se a lista estiver vazia, retorna falso
    if (l->inicio == NULL) {
        return false;
    }
    // se a lista tiver um elemento, remove o primeiro
    if (l->inicio->prox == NULL) {
		remove_inicio(l);
		return true;
	}
    No* aux = l->inicio;
    // percorre a lista até encontrar o penultimo elemento
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
    // caso a lista esteja vazia, retorna falso
    if (l->inicio == NULL) {
        return false;
    }
    int s = tamanho_lista(l);
    No* aux1 = l->inicio;
    No* aux2 = l->inicio;
    // caso só tenha um elemento e seja igual a info, remove o último
    if (s == 1 && aux1->info == info) {
        remove_fim(l);
        return true;
    }
    // se o primeiro for igual a info, remove o primeiro
    if (aux1->info == info) {
        remove_inicio(l);
        return true;
    }
    // percorre a lista até encontrar o elemento desejado
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
    // caso a lista esteja vazia, retorna falso
    if (l->inicio == NULL) {
        return false;
    }
    int s = tamanho_lista(l);
    cout << "tamanho da lista: " << s << endl;
    No* aux1 = l->inicio;
    No* aux2 = l->inicio;
    // caso só tenha um elemento e seja igual a info, remove o último
    if (s == 1 && aux1->info == info) {
        remove_fim(l);
        return true;
    }
    // removendo o primeiro elemento enquanto for igual a info
    while (l->inicio->info == info) {
        cout << "removido do inicio" << endl;
        remove_inicio(l);
        // necessário atualizar o aux1 se o primeiro for removido
        aux1 = l->inicio;
    }
    // removendo a partir do segundo elemento o que for igual a info até o final
    while (aux1->prox != NULL) {
        if (aux1->prox->info == info) {
			aux2 = aux1->prox;
			aux1->prox = aux2->prox;
			free(aux2);
		}
        else {
			aux1 = aux1->prox;
		}
	}
    return true;
}

No* busca_no(Lista* l, int info) {
    if (!l) {
        return NULL;
    }
    No* aux = l->inicio;
    // percorre a lista até encontrar o elemento desejado
    while (aux != NULL) {
        if (aux->info == info) {
            // retorna o ponteiro para o nó desejado
            return aux;
        }
        aux = aux->prox;
    }
    return NULL;
}

bool modifica_no(Lista* l, int info, int novo_info) {
    // busca o nó desejado
    No* aux = busca_no(l, info);
    // se não encontrar a informação, retorna falso
    if (!aux) {
        return false;
    }
    // modifica a informação
    aux->info = novo_info;
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
    // libera todos os nós da lista
    while ((*l)->inicio != NULL) {
        remove_inicio(*l);
    }
    // libera a lista
    free(*l);
    *l = NULL;
}

bool concatena_listas(Lista* l1, Lista* l2) {
    if (!l1 || !l2) {
        return false;
    }
    // lista 2 é vazia
    if (l2->inicio == NULL) {
        return false;
    }
    if (l1->inicio != NULL) {
        No* aux1 = l1->inicio;
        // mover auxiliar para o final da lista 1    
        while (aux1->prox != NULL) {
            aux1 = aux1->prox;
        }
        aux1->prox = l2->inicio;
        l2->inicio = NULL;
    }
    else {
        // caso lista 1 vazia
        l1->inicio = l2->inicio;
        l2->inicio = NULL;
    }
    return true;
}

bool inverte_lista(Lista* l) {
    if (!l) {
        return false;
    }
    // lista vazia
    if (l->inicio == NULL) {
        return false;
    }
    // lista com apenas um elemento
    if (l->inicio->prox == NULL) {
        return false;
    }
    No* aux1 = l->inicio;
    l->inicio = aux1->prox;
    aux1->prox = NULL;
    No* aux2 = l->inicio;
    while (l->inicio->prox != NULL) {
        l->inicio = aux2->prox;
        aux2->prox = aux1;
        aux1 = aux2;
        aux2 = l->inicio;
    }
    l->inicio->prox = aux1;
    return true;
}

#endif
