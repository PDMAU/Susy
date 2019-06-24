#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

p_no inserir(p_no raiz, int chave)
{
    p_no novo;
    if (raiz == NULL)
    {
        novo = malloc(sizeof(No));
        novo->vezes_atingidas = 0;
        novo->esq = novo->dir = NULL;
        novo->chave = chave;
        return novo;
    }
    if (chave < raiz->chave)
        raiz->esq = inserir(raiz->esq, chave);
    else
        raiz->dir = inserir(raiz->dir, chave);
    return raiz;
}

p_no buscar(p_no raiz, int chave)
{
    if (raiz == NULL || chave == raiz->chave)
        return raiz;
    if (chave < raiz->chave)
        return buscar(raiz->esq, chave);
    else
        return buscar(raiz->dir, chave);
}

p_no criar_arvore(){
    return NULL;
}
