#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main()
{
    p_no lista;
    p_no* vetor_prioridade;
    int n, i, k, ordem, prioridade;
    scanf(" %d", &k);
    vetor_prioridade = malloc(sizeof(p_no)*k);
    scanf(" %d", &n);
    for(i=0; i <= k; i++){
        vetor_prioridade[i] = criar_lista();
    }
    for(i=0; i < n; i++){
        ordem = 0;
        prioridade =0;
        scanf(" %d %d", &ordem, &prioridade);
        vetor_prioridade[prioridade] = inserir(vetor_prioridade[prioridade], ordem);
    }


    for(i=k; 0 <= i; i--){
        lista = vetor_prioridade[i];
        while(lista != NULL){
            printf("%d %d\n", lista->ordem, i);
            lista = lista->prox;
        }
    }
    return 0;
}
