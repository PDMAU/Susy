#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int **adj;
    int n;
} Grafo;

typedef Grafo * p_grafo;

p_grafo criar_grafo(int n);

void destroi_grafo(p_grafo g);

void insere_aresta(p_grafo g, int u, int v);

void remove_aresta(p_grafo g, int u, int v);

int tem_aresta(p_grafo g, int u, int v);

int *busca_em_largura(p_grafo g, int s);
