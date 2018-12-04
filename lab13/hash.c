/*
Nome: Maurilio dos Santos Gonçalves 
RA:203648
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"
#define HASH_PRICINPAL 64
#define HASH_SECUNDARIO 37

int hashPrincipal(char *chave) {
    int i, n = 0;
    for (i = 0; i < strlen(chave); i++) {
        n = (HASH_PRICINPAL * n + chave[i]) % MAX;
    }
    return n;
}

int hashSecundario(char *chave) {
    int i, n = 0;
    for (i = 0; i < strlen(chave); i++) {
        n = (HASH_SECUNDARIO * n + chave[i]) % MAX;
    }
    if (n % 2 == 0)
        return n + 1;
    return n;
}
/*cria tabela hash e garante q todas as posicoes ja estejam nulas*/
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
/*primeiro vai na posicao dada pelo hash principal, caso esteja vago já, da saltos do tamanho de hashSecundadario*/
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

/*busca o autor utilizando o nome como chave, para buscar se faz o processo inverso do de inserir*/
p_autor buscar(p_hash t, char *chave){
    int n = hashPrincipal(chave);
    /*enquanto esta em uma posicao ocupada e que o nome seja diferente do buscado*/
    while((t->vetor[n] != NULL )&& strcmp(chave, t->vetor[n]->nome) != 0 ){
         n = ((n+hashSecundario(chave)) % MAX);
    }
    return t->vetor[n];
}

/*Primeiro libera os vetores de artigos caso o autor exista, depois libera o vetor de autor*/
void destruir_hash(p_hash t){
    int i;
    for(i=0; i < MAX; i++){
        if(t->vetor[i] != NULL){
            free(t->vetor[i]->artigos);
        }
    }
    free(t);
}
