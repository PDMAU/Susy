/*
Nome: Maurilio dos Santos Gonçalves 
RA:203648
*/
#define MAX 2048


typedef struct{
    char nome[17];
    unsigned int *artigos;
} Autor;
/*O autor possui o nome e um vetor de n posicoes onde n é o numero total de artigos
    cada posicao do vetor começa com 0 e caso o autor tenha participacao em determinado artigo k,
    a posicao k do vetor artigos tera o valor 1, q indica tal participacao
*/

typedef Autor *p_autor;

typedef struct{
    p_autor vetor[MAX];
    int qtsArtigos;
} Hash;

typedef Hash *p_hash;

p_hash criar_hash(int numeroArtigos);

void destruir_hash(p_hash t);

void inserir(p_hash t, char *chave, p_autor dado);

p_autor buscar(p_hash t, char *chave);
