#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

int haColaboracao(p_hash tabela, char* nomeAutor1, char* nomeAutor2){
    int i;
    p_autor autor1, autor2;
    autor1 = buscar(tabela, nomeAutor1);
    autor2 = buscar(tabela, nomeAutor2);

    for(i =0; i < tabela->qtsArtigos; i++){
        if(autor1->artigos[i] == autor2->artigos[i] != 0){
            return 1;
        }
    }

    return 0;
}

void inserirParticipacaoEmArtigo(p_autor autor,int numeroArtigo){
    autor->artigos[numeroArtigo]=1;
}
//refazer o destruir
void processarAutor(p_hash tabela, char* nome,int numeroArtigo){
    int i;
    p_autor autor = buscar(tabela, nome);
    if(autor == NULL){
        autor = malloc(sizeof(Autor));
        autor->artigos = malloc(sizeof(unsigned int)* tabela->qtsArtigos);
        //inicializar esse vetor com 0 em tudo
        for(i=0; i < tabela->qtsArtigos; i++){
          autor->artigos[i] = 0;
        }

        inserir(tabela, nome, autor);
    }
    inserirParticipacaoEmArtigo(autor, numeroArtigo);
}

void ler_artigos(p_hash hash, int artigos) {
    int i;

    for(i = 1; i <= artigos; i++) {
        char nome[17] = "\0", inicial, sobrenome[17], separador;

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

void ler_consultas(p_hash hash, int consultas) {
    int i;
    p_autor autor1, autor2;

    for(i = 1; i <= consultas; i++) {
        char nome1[17] = "\0", nome2[17] = "\0", inicial, sobrenome[17], separador;

        scanf(" %c. %[^.,]%c", &inicial, sobrenome, &separador);

        nome1[0] = inicial;
        strcat(nome1, sobrenome);

        scanf(" %c. %[^.,]%c", &inicial, sobrenome, &separador);

        nome2[0] = inicial;
        strcat(nome2, sobrenome);
        if (haColaboracao(hash,nome1,nome2))
            printf("S\n");
        else
            printf("N\n");
    }
}

int main() {
    p_hash hash;
    int artigos, consultas;
    scanf("%d %d", &artigos, &consultas);
    hash = criar_hash(artigos);


    ler_artigos(hash, artigos);
    ler_consultas(hash, consultas);

    return 0;
}
