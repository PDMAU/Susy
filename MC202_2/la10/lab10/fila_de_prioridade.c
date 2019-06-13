// Maurilio Santos
// 203648
#include "fila_de_prioridade.h"
#include <stdio.h>
#include <stdlib.h>
#define PAI(i) ((i-1)/2)
#define F_ESQ(i) (2*i+1) /*Filho esquerdo de i*/
#define F_DIR(i) (2*i+2) /*Filho direito de i*/

void troca(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

p_fp criar_filaprio(int tam)
{
    p_fp fprio = malloc(sizeof(FP));
    fprio->v = malloc(tam * sizeof(int));
    fprio->n = 0;
    fprio->tamanho = tam;
    return fprio;
}

void sobe_no_heap(p_fp fprio, int k) // alteraçao feita para deixar o menor elemento no topo
{
    if (k > 0 && fprio->v[PAI(k)] > fprio->v[k]) //se for menor que o pai, ele sobe
    {
        troca(&fprio->v[k], &fprio->v[PAI(k)]);
        sobe_no_heap(fprio, PAI(k));
    }
}

void insere(p_fp fprio, int chave)
{
    fprio->v[fprio->n] = chave;
    fprio->n++;
    sobe_no_heap(fprio, fprio->n - 1);
}
void desce_no_heap(p_fp fprio, int k) // alterado para manter o menor indice no topo
{
    int menor_filho;
    if (F_ESQ(k) < fprio->n)
    {
        menor_filho = F_ESQ(k);
        if (F_DIR(k) < fprio->n &&
                fprio->v[F_ESQ(k)] > fprio->v[F_DIR(k)])
            menor_filho = F_DIR(k);
        if (fprio->v[k] > fprio->v[menor_filho])
        {
            troca(&fprio->v[k], &fprio->v[menor_filho]);
            desce_no_heap(fprio, menor_filho);
        }
    }
}

int extrai_minimo(p_fp fprio)
{
    int item = fprio->v[0];
    troca(&fprio->v[0], &fprio->v[fprio->n - 1]);
    fprio->n--;
    desce_no_heap(fprio, 0);
    return item;
}


