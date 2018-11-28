#define MAX 2048


typedef struct
{
    char nome[17];
    unsigned int *artigos;
} Autor;

typedef Autor *p_autor;

typedef struct
{
    p_autor vetor[MAX];
    int qtsArtigos;
} Hash;

typedef Hash *p_hash;

p_hash criar_hash(int numeroArtigos);

void destruir_hash(p_hash t);

void inserir(p_hash t, char *chave, p_autor dado);

p_autor buscar(p_hash t, char *chave);
