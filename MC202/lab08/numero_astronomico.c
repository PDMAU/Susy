p_no inserir(p_no lista, int valor){

    p_no novoNo = malloc(sizeof(No));    
    novoNo->valor = valor;
    novoNo->prox = lista;
    novoNo->ant = NULL;

    return novoNo;
}

p_no pegarUltimoNo(p_no lista) {
    while(lista->prox != NULL)
        lista = lista->prox;
    return lista;
}