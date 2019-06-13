#include "produto.h"
#include "data.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

Produto criaProduto(char nome[], float preco, int quantidade, Data validade){
    Produto produto;
    strcpy(produto.nome,nome);
    produto.preco = preco;
    produto.quantidade =quantidade;
    produto.validade = validade;

    return produto;
}

Produto leProduto(){
    char nome[MAX_NOME_PRODUTO];
    float preco;
    int quantidade;
    Data data;
    scanf("%s %f %d ",nome,&preco, &quantidade);
    data = leData();

    return criaProduto(nome, preco, quantidade, data);
}

int produtoEstaVencido(Produto prod, Data hoje){
    return comparaData(prod.validade, hoje) <=0  ;
}
