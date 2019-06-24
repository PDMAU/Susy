#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"


p_no montar_arvore(int *v, int l, int r)
{
    p_no novo;
    int valor, m = (l + r) / 2;

    if (l >= r){
        novo = malloc(sizeof(No));
        novo->vezes_atingidas = 0;
        novo->esq = novo->dir = NULL;
        novo->chave = v[m];
        return novo;
    }
    novo = malloc(sizeof(No));
    novo->vezes_atingidas = 0;
    novo->chave = v[m];
    novo->esq = montar_arvore(v, l, m-1);
    novo->dir = montar_arvore(v, m+1, r);
    return novo;
}

int main(){
    int *v,n,i,k,m;
    p_no arvore, aux;
    arvore = criar_arvore();
    scanf("%d", &n);
    v = malloc(n*sizeof(int));

    for(i =0;i < n; i++){
        scanf("%d", &k);
        v[i] = k;
    }
    arvore = montar_arvore(v,0,n-1);
    if(arvore == NULL)
    printf("TA NULA");
    scanf("%d", &m);
    for(i =0;i < m; i++){
        scanf("%d", &k);
        aux = buscar(arvore, k);
        if(aux == NULL )
            printf("TA NULO");
        aux->vezes_atingidas = aux->vezes_atingidas+1;
    }
    for(i =0;i < n; i++){
        aux = buscar(arvore, i);
        if(aux == NULL )
            printf("TA NULO");
        printf("No %d Vezes atingidas %d \n",i,aux->vezes_atingidas);
    }
    return 0;
}



