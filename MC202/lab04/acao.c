/*
Nome: Maurilio dos Santos Gonçalves
RA:203648
*/
#include "acao.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

acao criar_acao(char *nome, double investimento) {
    acao a;
    strcpy(a.nome,nome);
    a.investimento = investimento;
    a.n_variacoes = 0;
    return a;

}

acao adicionar_variacao(acao a, double variacao) {
    a.variacoes[a.n_variacoes] = variacao;
    a.n_variacoes++;
    return a;
}

double calcula_acao(acao a) {
    int i;
    double aux;

    for(i = 0; i<a.n_variacoes; i++) {
        aux = (a.variacoes[i]/100)+1;
        a.investimento = a.investimento*aux;
    }

    return a.investimento;
}

void reportar_acao(acao a) {

    double  novoValorInvestimento = calcula_acao(a);

    printf("%s %.2f ", a.nome, novoValorInvestimento);
    if(novoValorInvestimento > a.investimento) {
        printf("GANHO\n");
    } else {
        printf("PERDA\n");
    }
}



