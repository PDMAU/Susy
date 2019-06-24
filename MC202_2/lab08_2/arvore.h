typedef struct No
{
    int chave;
    int vezes_atingidas;
    struct No *esq, *dir; /* *pai */
} No;

typedef No * p_no;

p_no criar_arvore();
p_no buscar(p_no raiz, int chave);
void printar_arvore(p_no raiz);
void destruir_arvore(p_no raiz);
