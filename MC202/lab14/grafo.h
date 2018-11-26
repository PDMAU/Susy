/*
Nome: Maurilio dos Santos Gonçalves 
RA:203648
*/
typedef struct No {
    int v;
    struct No *prox;
} No;

typedef No * p_no;

typedef struct {
    p_no *adjacencia;
    int n;
} Grafo;

typedef Grafo * p_grafo;

p_grafo criar_grafo(int n);

void destroi_grafo(p_grafo g);

void insere_aresta(p_grafo g, int u, int v);

void remove_aresta(p_grafo g, int u, int v);

int tem_aresta(p_grafo g, int u, int v);

void imprime_arestas(p_grafo g);