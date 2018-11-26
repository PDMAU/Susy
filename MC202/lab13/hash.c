#include <hash.h>


p_hash criar_hash(){
    return  malloc(sizeof(Hash));
}
int hash(char *chave)
{
    int i, n = 0;
    for (i = 0; i < strlen(chave); i++)
        n = (256 * n + chave[i]) % MAX;
    return n;
}

void inserir(p_hash t, char *chave, int dado)
{
    int n = hash(chave);
    t->vetor[n] = inserir_lista(t->vetor[n], chave, dado);
}

void remover(p_hash t, char *chave)
{
    
    int n = hash(chave);
    t->vetor[n] = remover_lista(t->vetor[n], chave);
}

p_hash criar_hash(){
    
}
