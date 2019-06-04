Estoque criaEstoqueVazio(){
    Estoque estoque;
    estoque.num_produtos =0;
    return estoque;
}


Estoque adicionaProduto(Estoque estoque, Produto prod){
    estoque.produtos[estoque.num_produtos] =prod;
    estoque.num_produtos++;

    return estoque;
}

/*
 * Procura um produto no estoque pelo nome e devolve esse produto.
 */
Produto procuraProduto(Estoque estoque, char nome[]){
    int i;
    for(i=0; i <= estoque.num_produtos; i++){
        if(strcmp (estoque.produtos[i].nome, nome) == 0)
            return estoque.produtos[i];
    }
    return NULL;
}