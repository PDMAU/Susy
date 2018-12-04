#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "heap.h"
#define OPOSTO(i) (i*(-1))

/*Esse metodo funciona pelo pressuposto que nao existe massa negativa*/
int main() {
    int qtsCaixas, i, peso;
    p_fp max_heap;
    p_fp min_heap;

    scanf("%d", &qtsCaixas);

    max_heap = criar_filaprio(qtsCaixas);
    min_heap = criar_filaprio(qtsCaixas);

    for(i = 0; i < qtsCaixas; i++) {
        Item item;
        char produto[21];
        scanf("%s %d", produto, &peso);
        strcpy(item.nome, produto);
        item.chave = peso;

        if(vazia(min_heap)&&vazia(min_heap)){
            item.chave = OPOSTO(item.chave);
            insere(min_heap, item);
        }else{
            inserirProduto(max_heap, min_heap,item);
            balancear(max_heap, min_heap);
        }
        printarProdutosSelecionados(max_heap, min_heap);
    }
    return 0;
}


void inserirProduto(p_fp max_heap, p_fp min_heap, Item item){
    Item meio;
     if (vazia(min_heap)){
         meio = pegarTopo(max_heap);
     }else if (vazia(max_heap)){
         meio = pegarTopo(min_heap);
    }else if (min_heap->n > max_heap->n){
        meio = pegarTopo(min_heap);
    }else{
        meio = pegarTopo(max_heap);
    }

    if(meio.chave < 0){
        meio.chave = OPOSTO(meio.chave);
    }

    if (item.chave >= meio.chave){
        item.chave = OPOSTO(item.chave);
        insere(min_heap, item);
    }else{
        insere(max_heap, item);
    }

}

void balancear(p_fp max_heap, p_fp min_heap){
    Item item;
    if (min_heap->n - max_heap->n > 1 ) {
        item = extrai_maximo(min_heap);
        item.chave = OPOSTO(item.chave);
        insere(max_heap, item);
    }

    if (max_heap->n - min_heap->n > 1) {
        item = extrai_maximo(max_heap);
        item.chave = OPOSTO(item.chave);
        insere(min_heap, item);
    }
}

void printarProdutosSelecionados(p_fp max_heap, p_fp min_heap){
    Item max;
    Item min;
    if (max_heap->n == min_heap->n) {
        max = pegarTopo(max_heap);
        min = pegarTopo(min_heap);
        printf("%s: %d\n", max.nome, max.chave);
        printf("%s: %d\n", min.nome, OPOSTO(min.chave));
    } else if (min_heap->n > max_heap->n ) {
        min = pegarTopo(min_heap);
        printf("%s: %d\n", min.nome, OPOSTO(min.chave));
    }else{
        max = pegarTopo(max_heap);
        printf("%s: %d\n", max.nome, max.chave);
    }
}
