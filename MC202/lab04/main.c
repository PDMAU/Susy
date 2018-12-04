#include <stdio.h>
#include <stdlib.h>
#include "portfolio.h"
#include "acao.h"

int main(){
    char nome[30], sobrenome[30], empresa[30];
    int n, i, j, m;
    double valor;
    acao acao;
    portfolio portfolio;
    scanf("%s %s %d", nome, sobrenome, &n);
    portfolio = criar_portfolio(nome, sobrenome);
    
    for(i = 0; i < n; i++){
       scanf("%s %lf %d", empresa, &valor, &m);
       acao = criar_acao(empresa, valor);
       for(j =0; j < m; j++){           
           scanf(" %lf", &valor);
           acao = adicionar_variacao(acao, valor);
       }
       portfolio = adicionar_acao(portfolio, acao);
    }

    criar_relatorio(portfolio);

    return 0;
}
