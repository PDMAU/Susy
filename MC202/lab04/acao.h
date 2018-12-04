#ifndef ACAO_H_INCLUDED
#define ACAO_H_INCLUDED
#define MAX_SIZE_NAME 30
#define MAX_SIZE_VAR 20

#include<string.h>


typedef struct {
    char nome[MAX_SIZE_NAME];
    double investimento;
    double variacoes[MAX_SIZE_VAR];
    int n_variacoes;
} acao;

acao inicializa(acao a);

acao criar_acao(char *nome, double investimento);

acao adicionar_variacao(acao a, double variacao);

void reportar_acao(acao a);


#endif // ACAO_H_INCLUDED
