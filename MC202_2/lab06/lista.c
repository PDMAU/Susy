#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

p_no inserir(p_no lista, int ordem){
    p_no anterior = NULL;
    p_no aux = lista;
    p_no novoNo = malloc(sizeof(No));
    novoNo->ordem = ordem;

    while(aux != NULL && (aux->ordem < ordem)){
        anterior = aux;
        aux = aux->prox;
        if(aux == NULL)
            break;
    }
    if(aux == NULL){
        if(anterior == NULL){
            novoNo->prox = lista;
            return novoNo;
        }else{
            novoNo->prox = NULL;
            anterior->prox = novoNo;
            return lista;
        }
    }
    else{
        if(anterior == NULL){
            novoNo->prox = aux;
            return novoNo;
        }else{
            novoNo->prox = aux;
            anterior->prox = novoNo;
            return lista;
        }
    }
}

p_no criar_lista() {
    return NULL;
}

void destruir_lista(p_no lista) {
    if (lista != NULL) {
        destruir_lista(lista->prox);
        free(lista);
    }
}
