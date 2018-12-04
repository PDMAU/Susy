/*
Nome: Maurilio dos Santos Gonçalves 
RA:203648
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM_NOME 31

typedef struct Participante{
    char nome[TAM_NOME];
    int telefone;
}Participante;

void copiarParticipante(Participante* destino, Participante* origem){
    strcpy((*destino).nome, (*origem).nome);
    (*destino).telefone = (*origem).telefone;
}

Participante* aumentarTamanhoVetor(Participante* participantes, int tamanhoAtual, int aumentarPara){
    Participante *novoVetor = NULL;
    int i;
    if(tamanhoAtual < aumentarPara){
        novoVetor = malloc(sizeof(Participante)*aumentarPara);
        if(novoVetor == NULL){
            exit(1);
        }
    }
    /*Move todos os participantes do vetor antigo para o novo*/
    for(i =0; i < tamanhoAtual; i++){
        strcpy(novoVetor[i].nome, participantes[i].nome);
        novoVetor[i].telefone = participantes[i].telefone;
    }
    free(participantes);
    return novoVetor;
}

void ordenarVetor(Participante* participantes, int tamanho){
    int i, j;
    Participante* aux = malloc(sizeof(Participante));
    if(aux == NULL){
        exit(1);
    }
    for(i =0; i < tamanho-1; i++){
        for(j =i+1; j < tamanho; j++){
            if(participantes[j].telefone < participantes[i].telefone){
                copiarParticipante(aux,&participantes[i]);
                copiarParticipante(&participantes[i],&participantes[j]);
                copiarParticipante(&participantes[j], aux);
            }
        }
    }
    free(aux);
}

int main(){
    Participante* participantes = malloc(sizeof(Participante)*4); 
    char palavra[TAM_NOME];/*String q pode representar tanto um nome, quanto o comando "fim" q faz o programa ser encerrado*/
    int numero,/*numero pode representar tanto um numero de telefone, quanto o numero do participante sorteado*/
        numeroParticipantes = 0,
        tamanhoVetor        = 4;        

    if(participantes == NULL){ /*caso nao exista espaço disponivel*/
        exit(1);
    }

    while(1){
        scanf("%s %d",palavra, &numero);

        if(strcmp("fim\0", palavra) == 0){
            ordenarVetor(participantes, numeroParticipantes);
            printf("%s %d\n", participantes[numero-1].nome, participantes[numero-1].telefone);
            break;
        }else{ /*else desnecessario mas facilita a leitura do codigo*/
            numeroParticipantes++;
            if(numeroParticipantes > tamanhoVetor){
                tamanhoVetor *=2;
                participantes = aumentarTamanhoVetor(participantes, tamanhoVetor,tamanhoVetor *2);
            }
            strcpy(participantes[numeroParticipantes-1].nome, palavra);
            participantes[numeroParticipantes-1].telefone = numero;
        }
    }
    free(participantes);
    return 0;
}