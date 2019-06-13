#include <stdio.h>
#include <stdlib.h>
#include "estoque.h"

int main()
{
    Data dataCompra;
    char produto[MAX_NOME_PRODUTO];
    int qtsProdutosEstoque, i, numeroPedidos, qtdVenda;
    Estoque estoque;
    Produto prod;
    estoque = criaEstoqueVazio();
    dataCompra = leData();
    scanf(" %d", &qtsProdutosEstoque);
    for(i=0; i < qtsProdutosEstoque; i++){
        estoque = adicionaProduto(estoque, leProduto());
    }
    scanf(" %d", &numeroPedidos);
    for(i=0; i < numeroPedidos; i++){
        scanf(" %s %d", produto, &qtdVenda);
        prod = procuraProduto(estoque,produto);
        if(produtoEstaVencido(prod,dataCompra)){
            printf("%s %.2f\n", prod.nome,prod.preco*qtdVenda);
        }else{
            if(prod.quantidade < qtdVenda)
                printf("%s %.2f\n", prod.nome,prod.preco*(qtdVenda-prod.quantidade));
            else
                printf("%s %.2f\n", prod.nome,0.00);
        }

    }

    return 0;
}
