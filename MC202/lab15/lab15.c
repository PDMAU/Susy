#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

int maiorDistancia(int *vetor,int vertice, int t);
int main() {
    int qtosAlunos, qtosGrupos, m, i, j, k, *vetorGrupo, *vetorArvore;
    p_grafo grafo;
    scanf("%d %d", &qtosAlunos, &qtosGrupos);
    grafo = criar_grafo(qtosAlunos);

    /*Faz a leitura do grupo e de seus participantes*/
    for(i = 0; i < qtosGrupos; i++){
        scanf("%d", &m);
        vetorGrupo = malloc(sizeof(int)*m);
        if(vetorGrupo == NULL){
		    exit(1);
        }
        for(j=0; j < m; j++){
            scanf("%d", &vetorGrupo[j]);
        }
        /*faz a permutacao para ligar todos os membros do grupo no grafo*/
        for(j=0; j < m; j++){
            for(k=j+1; k < m; k++){
                insere_aresta(grafo, vetorGrupo[j], vetorGrupo[k]);
            }
        }
        free(vetorGrupo);
    }
    /*faz a busca em largura para cada vertice*/
    for(i=0; i < qtosAlunos; i++){
        vetorArvore = busca_em_largura(grafo, i);
        for(j =0; j < qtosAlunos; j++ ){
            if(vetorArvore[j] == -1){
                printf("%d ", j);
            }

        }
        printf("- %d\n", maiorDistancia(vetorArvore, i, qtosAlunos));
        free(vetorArvore);
    }

    destroi_grafo(grafo);
    return 0;
}

int maiorDistancia(int *vetor,int vertice, int t){
    int contador =0, maior = 0,  i, aux;

    for(i=0; i < t; i++ ){
        contador =0;
        aux = i;
        while((aux != -1)&&(aux != vertice)){
            aux = vetor[aux];
            contador++;
        }
        if(contador > maior){
            maior = contador;
        }
    }
    return maior;
}
