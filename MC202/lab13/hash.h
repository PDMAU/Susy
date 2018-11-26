#define MAX 1783

typedef struct
{
    char chave[10];
    int dado;
    No *prox;
} No;

typedef No *p_no;

typedef struct
{
    p_no vetor[MAX];
} Hash;

typedef Hash *p_hash;

p_hash criar_hash();

void destruir_hash(p_hash t);

void inserir(p_hash t, char *chave, int dado);

void remover(p_hash t, char *chave);

p_no buscar(p_hash t, char *chave);