#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

p_no buscar(p_no raiz, int chave)
{
    if (raiz == NULL || chave == raiz->chave)
        return raiz;
    if (chave < raiz->chave)
        return buscar(raiz->esq, chave);
    else
        return buscar(raiz->dir, chave);
}

void printar_arvore(p_no raiz){
    if(raiz == NULL)
        return;
    printf("%d %d\n", raiz->chave, raiz->vezes_atingidas);
    printar_arvore(raiz->esq);
    printar_arvore(raiz->dir);
}

void destruir_arvore(p_no raiz){
  if(raiz == NULL)
        return;
    printar_arvore(raiz->esq);
    printar_arvore(raiz->dir);
    free(raiz);
}
p_no criar_arvore(){
    return NULL;
}
