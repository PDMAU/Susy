


int calcularTriangulos(){
	for(f = grafo; f != NULL; f = f ->prox){
		for(g = f ->adjacencia; g != NULL; g = g->prox){
			for(h = acharElemento(g->v); h != NULL; h = h->prox){
				if(tem_aresta(grafo, h->v, f->n))
			}		
		}
	}


}
