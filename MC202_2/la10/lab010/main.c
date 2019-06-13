#include "fila_de_prioridade.h"
#include <stdio.h>
#include <stdlib.h>x

int main()
{
    int k, * tamanhos,i,j,aux, tamanhoFila =0;
    p_fp fila;
    scanf("%d", &k);
    tamanhos = malloc(k*sizeof(int));
    for(i =0; i < k; i++){
        scanf("%d", &tamanhos[i]);
        tamanhoFila = tamanhoFila+ (tamanhos[i]);
    }
    fila = criar_filaprio(tamanhoFila);
    for(i =0; i < k; i++){
        for(j =0; j < tamanhos[i]; j++){
            scanf("%d", &aux);
            insere(fila, aux);
        }
    }

    printf("Hello world!\n");
    return 0;
}
