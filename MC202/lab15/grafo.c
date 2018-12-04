#include "grafo.h"

typedef struct
{
    int *v;
    int ini, fim, N, tamanho;
} Fila;
typedef Fila *p_fila;

p_fila criar_fila(int N)
{
    p_fila f;
    f = malloc(sizeof(Fila));
    f->v = malloc(N * sizeof(int));
    f->ini = 0;
    f->fim = 0;
    f->N = N;
    f->tamanho = 0;
    return f;
}

void enfileira(p_fila f, int x)
{
    f->v[f->fim] = x;
    f->fim = (f->fim + 1) % f->N;
    f->tamanho++;
}

int desenfileira(p_fila f)
{
    int x = f->v[f->ini];
    f->ini = (f->ini + 1) % f->N;
    f->tamanho--;
    return x;
}
int fila_vazia(p_fila f){
   return !f->tamanho;
}

void destroi_fila(p_fila f){
    free(f);
}
p_grafo criar_grafo(int n)
{
    int i, j;
    p_grafo g = malloc(sizeof(Grafo));
    g->n = n;
    g->adj = malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
        g->adj[i] = malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            g->adj[i][j] = 0;
    return g;
}

void destroi_grafo(p_grafo g)
{
    int i;
    for (i = 0; i < g->n; i++)
        free(g->adj[i]);
    free(g->adj);
    free(g);
}

void insere_aresta(p_grafo g, int u, int v)
{
    g->adj[u][v] = 1;
    g->adj[v][u] = 1;
}

void remove_aresta(p_grafo g, int u, int v)
{
    g->adj[u][v] = 0;
    g->adj[v][u] = 0;
}

int tem_aresta(p_grafo g, int u, int v)
{
    return g->adj[u][v];
}

int *busca_em_largura(p_grafo g, int s)
{
    int w, v;
    int *pai = malloc(g->n * sizeof(int));
    int *visitado = malloc(g->n * sizeof(int));
    p_fila f = criar_fila(g->n);
    for (v = 0; v < g->n; v++)
    {
        pai[v] = -1;
        visitado[v] = 0;
    }
    enfileira(f, s);
    pai[s] = s;
    visitado[s] = 1;
    while (!fila_vazia(f))
    {
        v = desenfileira(f);
        for (w = 0; w < g->n; w++)
            if (g->adj[v][w] && !visitado[w])
            {
                visitado[w] = 1; /*evita repetição na fila*/
                pai[w] = v;
                enfileira(f, w);
            }
    }
    destroi_fila(f);
    free(visitado);
    return pai;
}
