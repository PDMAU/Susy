#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main()
{
    p_no lista, atual;
    int qtsProdutosEstoque, i, numeroPedidos ; 
    lista = criar_lista();  
    scanf(" %d", &qtsProdutosEstoque);
    for(i=0; i < qtsProdutosEstoque; i++){
        scanf(" %d", &numeroPedidos);
        lista = inserir(lista, numeroPedidos);
    }

    while(lista != NULL){
        printf("%d\n", lista->ordem);
        lista = lista->prox;
    }
    return 0;
}
