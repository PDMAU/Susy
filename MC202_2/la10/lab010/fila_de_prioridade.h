#ifndef FILA_DE_PRIORIDADE_H_INCLUDED
#define FILA_DE_PRIORIDADE_H_INCLUDED

typedef struct
{
    int chave;
} Item;

typedef struct
{
    Item *v;
    int n, tamanho;
} FP;

typedef FP * p_fp;

p_fp criar_filaprio(int tam);
void insere(p_fp fprio, int chave);
Item extrai_minimo(p_fp fprio);

#endif // FILA_DE_PRIORIDADE_H_INCLUDED
