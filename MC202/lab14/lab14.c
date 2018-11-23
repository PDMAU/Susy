
#include <stdio.h>
#include <stdlib.h>

int **pessoas;// primeiro campo é a sua idade, o segundo é se esta entediado 0 -Nao, 1- Sim
int main()
{
    printf("Hello world!\n");
    return 0;
}


int calcularTriangulos(){
	int f;
	for(f = 0; f < n; f++){
		for(g = p_grafo[f]->adjacencia; g != NULL; g = g->prox){
			
			for(h = p_grafo[g->v]->adjacencia; h != NULL; h = h->prox){
				if(tem_aresta(p_grafo, f, h->v)){
					index = calcularSeTemEntediado(p_grafo[f]->n,g->v,h->v);					
				}
			}		
		}
	}
}

int calcularSeTemEntediado(p_no f,p_no g, p_no h){
	int media = (f->v+g->v+h->v)/3;

	if(media > f->v || media > g->v || media > h->v){
		return 1;
	}

	return 0;
}
