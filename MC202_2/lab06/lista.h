#ifndef LISTA_H
#define LISTA_H

typedef struct No {
    int ordem;
    struct No *prox;
} No;

typedef struct No * p_no;

p_no inserir(p_no lista, int ordem);
p_no criar_lista();
void destruir_lista(p_no lista);

#endif
