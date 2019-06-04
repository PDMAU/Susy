#include <stdio.h>
#include <stdlib.h>

int main()
{
    Data dataCompra;
    char produto[MAX_NOME_PRODUTO];
    int qtsProdutosEstoque, i, numeroPedidos, qtdVenda;
    Estoque estoque;
    estoque = criaEstoqueVazio();
    dataCompra = leData(); 
    scanf(" %d", &qtsProdutosEstoque);
    for(i=0; i < qtsProdutosEstoque; i++){
        adicionaProduto(estoque, leProduto());
    }
    scanf(" %d", &numeroPedidos);
    for(i=0; i < numeroPedidos; i++){  

    }
    printf("Hello world! %d %d\n", dia, numero);
    return 0;
}
