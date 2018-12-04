/*
Nome: Maurilio dos Santos Gonçalves 
RA:203648
*/
#include <stdio.h>
#include <stdlib.h>
#include "portfolio.h"
#include "acao.h"

int main() {
    char nome[MAX_SIZE_NAME], sobrenome[MAX_SIZE_NAME], empresa[MAX_SIZE_NAME];
    int n, i, j, m;
    double valor;
    acao acao;
    portfolio portfolio;
    scanf("%s %s %d", nome, sobrenome, &n);
    portfolio = criar_portfolio(nome, sobrenome);

    for(i = 0; i < n; i++) {
        scanf("%s %lf %d", empresa, &valor, &m);
        acao = criar_acao(empresa, valor);
        for(j =0; j < m; j++) {
            scanf(" %lf", &valor);
            acao = adicionar_variacao(acao, valor);
        }
        portfolio = adicionar_acao(portfolio, acao);
    }

    criar_relatorio(portfolio);

    return 0;
}
