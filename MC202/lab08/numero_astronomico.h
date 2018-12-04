#ifndef NUMERO_ASTRONOMICO_H
#define NUMERO_ASTRONOMICO_H

typedef struct {
    int valor;
    struct no* prox;
    struct no* ant;
} No;

typedef No* p_no;

p_no inserir(no lista, int val, int onde);

p_no pegarUltimoNo(no lista);

void printa(no lista);

no soma(no lista, no lista2);

no limpa(no lista);
#endif