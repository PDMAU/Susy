/*
Nome: Maurilio dos Santos Gonçalves 
RA:203648
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"
#define MAX 2048

/*Busca o autor1 e autor2, dentro desses autores é percorrido o vetor de artigos, caso ache algum artigo 
que os dois participam é retornado 1
*/
int haColaboracao(p_hash tabela, char* nomeAutor1, char* nomeAutor2){
    int i;
    p_autor autor1, autor2;
    autor1 = buscar(tabela, nomeAutor1);
    autor2 = buscar(tabela, nomeAutor2);

    if(autor1 == NULL || autor2 == NULL){
        return 0;
    }

    for(i =0; i < tabela->qtsArtigos; i++){
        if(autor1->artigos[i] != 0 && autor2->artigos[i] != 0){
            return 1;
        }
    }
    return 0;
}

/* insere 1 na posicao do vetor q representa o artigo indicando q o autor participa */
void inserirParticipacaoEmArtigo(p_autor autor,int numeroArtigo){
    autor->artigos[numeroArtigo]=1;
}

void processarAutor(p_hash tabela, char* nome,int numeroArtigo){
    int i;
    p_autor autor = buscar(tabela, nome);
    /*verifica se o autor ja existe, caso sim só adiciona a participação dele no artigo, caso nao, cria um novo
        e ao final adiciona a participação dele no artigo
    */
    if(autor == NULL){
        autor = malloc(sizeof(Autor));
        if(autor == NULL){
		    exit(1);
	    }
        strcpy(autor->nome,nome);
        /*inicia o vetor de artigos*/
        autor->artigos = malloc(sizeof(unsigned int)* tabela->qtsArtigos);
        if(autor->artigos == NULL){
		    exit(1);
	    }
        for(i=0; i < tabela->qtsArtigos; i++){
          autor->artigos[i] = 0;
        }

        inserir(tabela, nome, autor);
    }
    inserirParticipacaoEmArtigo(autor, numeroArtigo);
}
/*Leitura dos artigos*/
void processarArtigos(p_hash hash, int numeroArtigos) {
    int i;

    for(i = 0; i < numeroArtigos; i++) {
        char nome[17] = "\0", inicial, sobrenome[16], separador;

        while (separador != '.') {
            scanf(" %c. %[^.,]%c", &inicial, sobrenome, &separador);

            nome[0] = inicial;
            strcat(nome, sobrenome);

            processarAutor(hash, nome, i);

            memset(nome, 0, 17);
        }
        separador = '0';
    }
}
/*leitura das consultas e printar se ha ou nao participacao*/
void processarConsultas(p_hash hash, int numeroConsultas) {
    int i;

    for(i = 0; i < numeroConsultas; i++) {
        char nome[17] = "\0", nome2[17] = "\0", inicial, sobrenome[16], separador;

        scanf(" %c. %[^.,]%c", &inicial, sobrenome, &separador);

        nome[0] = inicial;
        strcat(nome, sobrenome);

        scanf(" %c. %[^.,]%c", &inicial, sobrenome, &separador);

        nome2[0] = inicial;
        strcat(nome2, sobrenome);
        if (haColaboracao(hash,nome,nome2)){
            printf("S\n");
        } else{
            printf("N\n");
        }            
    }
}

int main() {
    p_hash hash;
    int artigos, consultas;
    scanf("%d %d", &artigos, &consultas);
    hash = criar_hash(artigos);

    processarArtigos(hash, artigos);
    processarConsultas(hash, consultas);

    destruir_hash(hash);

    return 0;
}
