/*
Nome: Maurilio dos Santos Gonçalves 
RA:203648
*/
#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#define DIV_MEDIA 3.0
#define MULT_MAX_IDADE 2

int estaEntediado(int **pessoas, int f,int  g, int  h){
    int idadePessoa1 = pessoas[f][0],idadePessoa2 = pessoas[g][0],idadePessoa3= pessoas[h][0];
    float media = (idadePessoa1+idadePessoa2+idadePessoa3)/DIV_MEDIA;

    if(media > idadePessoa1*MULT_MAX_IDADE || media > idadePessoa2*MULT_MAX_IDADE || media > idadePessoa3*MULT_MAX_IDADE){
        return 1;
    }

    return 0;
}

/*o f representa o indice da primeira pessoa, ele vai percorrer o vetor de indices, o g vai entrar dentro da lista de adjacencia e apartir dos 
valores obtidos ele vai voltar pro vetor de indices na posicao obtida do g, ai com o h ele ira percorrer essa lista de adjacencia e ver se esses 
indices tem licação com o f*/
void calcularGruposEntediados(p_grafo grafo, int **pessoas, int n){
    int f;
    p_no g, h;
    for(f = 0; f < n; f++) {
        for(g = grafo->adjacencia[f]; g != NULL; g = g->prox){
            for(h =  grafo->adjacencia[g->v]; h != NULL; h = h->prox){
                if(tem_aresta(grafo, f, h->v)) {
                    if(estaEntediado(pessoas, f,g->v,h->v)){
                        pessoas[f][1] = 1;
                        pessoas[g->v][1] = 1;
                        pessoas[h->v][1] = 1;
                    }
                }
            }
        }
    }
}

int main(){
    int **pessoas;/*Matriz de pessoas, onde a coluna 0 corresponde a idade e a coluna 1 indica se a pessoa esta entendia ou nao*/
    int  i, m, n, u, v;
    p_grafo grafo;

    scanf("%d %d",&n,&m);

    grafo = criar_grafo(n);    
    if(grafo == NULL){
        return 1;
    }  

    pessoas = (int **)malloc(sizeof(int *)*n);
    if(pessoas == NULL){
        return 1;
    }
    for(i =0; i < n; i++){
        pessoas[i] = (int *)malloc(sizeof(int)*2);
        if(pessoas[i] == NULL){
            return 1;
        }
        scanf("%d", &pessoas[i][0]);
        pessoas[i][1] = 0;
    }

    for(i = 0; i < m; i++){
        scanf("%d %d",&u,&v);
        insere_aresta(grafo, u, v);
    }

    calcularGruposEntediados(grafo, pessoas, n);

    for(i =0; i < n; i++){
        if(pessoas[i][1] == 1) {
            printf("%d\n", i);
        }
    }

    destroi_grafo(grafo);

    /*Liberar matriz pessoas*/
    for(i =0; i < n; i++){        
        free(pessoas[i]);
    }
    free(pessoas);

    return 0;
}

