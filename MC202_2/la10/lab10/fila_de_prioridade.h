// Maurilio Santos
// 203648
#ifndef FILA_DE_PRIORIDADE_H_INCLUDED
#define FILA_DE_PRIORIDADE_H_INCLUDED

typedef struct
{
    int *v;
    int n, tamanho;
} FP;

typedef FP * p_fp;

p_fp criar_filaprio(int tam);
void insere(p_fp fprio, int chave);
int extrai_minimo(p_fp fprio);

#endif // FILA_DE_PRIORIDADE_H_INCLUDED
