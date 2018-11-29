#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hash.h"
#define MAX 2048

int hashPrincipal(char *chave) {
    int i, n = 0;
    for (i = 0; i < strlen(chave); i++) {
        n = (64 * n + chave[i]) % MAX;
    }
    return n;
}

int hashSecundario(char *chave) {
    int i, n = 0;
    for (i = 0; i < strlen(chave); i++) {
        n = (37 * n + chave[i]) % MAX;
    }
    if (n % 2 == 0)
        return n + 1;
    return n;
}

p_hash criar_hash(int numeroArtigos){
    int i;
    p_hash hash = malloc(sizeof(Hash));
    if(hash == NULL)
        return NULL;
    for(i=0; i < MAX; i++){
        hash->vetor[i] = NULL;
    }
    hash->qtsArtigos = numeroArtigos;
    return hash;
}

void inserir(p_hash t, char *chave, p_autor dado){
    int n = hashPrincipal(chave);
    if(t->vetor[n]== NULL){
        t->vetor[n] = dado;
    }else{
        while(t->vetor[n] != NULL){
            n = ((n+hashSecundario(chave)) % MAX);
        }
        t->vetor[n] = dado;
    }
}
p_autor buscar(p_hash t, char *chave){
    int n = hashPrincipal(chave);

    while((t->vetor[n] != NULL )&& strcmp(chave, t->vetor[n]->nome) != 0 ){
         n = ((n+hashSecundario(chave)) % MAX);
    }
    return t->vetor[n];
}

void destruir_hash(p_hash t){
    int i;
    for(i=0; i < MAX; i++){
        if(t->vetor[i] != NULL){
            free(t->vetor[i]->artigos);
        }
    }
    free(t);
}
