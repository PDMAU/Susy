
#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"


int main(){
      int **pessoas, i, m, n, u, v;
      p_grafo grafo;
      scanf("%d %d",n,m);
      grafo = criar_grafo(n);
      pessoas = (int **)malloc(sizeof(int *)*n);
      for(i =0; i < n; i++){
        pessoas[i] = (int *)malloc(sizeof(int)*2);
        scanf("%d", pessoas[i][0]);
        pessoas[i][1] = 0;
      }

      for(i = 0; i < m; i++){
        scanf("%d %d",u,v);
        insere_aresta(grafo, u, v);
      }

      calcularTriangulos(grafo, pessoas);

      for(i =0; i < n; i++){
        if(pessoas[i][0] == 1){
          printf("%d\n", i);
        }
      }

      return 0;
}


void calcularTriangulos(p_grafo grafo, int **pessoas){
	int f;
  p_no *g, *h;

	for(f = 0; f < n; f++){
		for(g = grafo[f]->adjacencia; g != NULL; g = g->prox){

			for(h = grafo[g->v]->adjacencia; h != NULL; h = h->prox){
				if(tem_aresta(grafo, f, h->v)){
					if(estaEntediado(grafo[f]->n,g->v,h->v)){
            pessoas[grafo[f]->n][1] = 1;
            pessoas[g->v][1] = 1;
            pessoas[h->v][1] = 1;
          }
				}
			}
		}
	}
}

int estaEntediado(int **pessoas, int f,int  g, int  h){
  int idadePessoa1 = pessoas[f][0],idadePessoa2 = pessoas[g][0],idadePessoa3= pessoas[h][0];
	int media = (idadePessoa1+idadePessoa2+idadePessoa3)/3;

	if(media > idadePessoa1 || media > idadePessoa2 || media > idadePessoa3){
		return 1;
	}

	return 0;
}
