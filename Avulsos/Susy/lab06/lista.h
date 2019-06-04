#ifndef LISTA_H
#define LISTA_H

typedef struct {
    int ordem;
    struct no* prox;
} No;

typedef No* p_no;

p_no inserir(no lista, int val);
p_no criar_lista();
void destruir_lista(p_no lista);

#endif