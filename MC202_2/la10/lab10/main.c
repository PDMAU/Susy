// Maurilio Santos
// 203648
#include "fila_de_prioridade.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int k, * tamanhos,i,j,aux, tamanhoFila = 0;
    p_fp fila;
    scanf("%d", &k);
    tamanhos = malloc(k*sizeof(int));
    if(tamanhos == NULL){
        printf("Erro para alocar vetor");
        return -1;
    }

    for(i =0; i < k; i++)
    {
        scanf("%d", &tamanhos[i]);
        tamanhoFila = tamanhoFila + (tamanhos[i]);
    }
    fila = criar_filaprio(tamanhoFila);
    for(i = 0; i < k; i++)
    {
        for(j =0; j < tamanhos[i]; j++)
        {
            scanf("%d", &aux);
            insere(fila, aux);
        }
    }
    //como o menor elemento sempre esta no topo, eh so extrair o minimo
    for(i =0; i < tamanhoFila ; i++)
    {
        if(i == tamanhoFila-1)
            printf("%d\n", extrai_minimo(fila));
        else
            printf("%d ", extrai_minimo(fila));

    }
    //ao final da execucao acima, para fazer uma funcao q retorna um vetor ordenado com todos os elementos
    //eh preciso apenas retornar o fila->v

    free(tamanhos);
    free(fila->v);
    free(fila);
    return 0;
}
