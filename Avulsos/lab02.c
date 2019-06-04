/*
* Maurilio dos Santos Goncalves 
* 203648 
*/
#include <stdio.h>
#include <stdlib.h>
#define TAMANHO_MAX_PALAVRA 47
#define TAMANHO_BILHETE 50000
#define TAMANHO_VETOR 1000


void quebrarEmVetorDeString(char bilhete[], char palavras[][TAMANHO_MAX_PALAVRA]);
int ehLetra(char caracter);

int main(){
    char bilhete[TAMANHO_BILHETE];
    int i, j, numeros[TAMANHO_VETOR];
    char palavras[TAMANHO_VETOR][TAMANHO_MAX_PALAVRA];

    scanf("%[^\n]", bilhete);
    quebrarEmVetorDeString(bilhete, palavras);

    scanf("%d", &i);// faz um vetor com as posicoes das palavras q serao utilizadas
    for(j = 0; j < i; j++){
        scanf("%d", &numeros[j]);
    }

    for(j=0; j < i; j++){//monta a frase
        printf("%s", palavras[numeros[j]]);
        if( j != (i-1)){//necessario para nao printar ' ' no final da frase
            printf(" ");
        }
    }
    return 0;
}


void quebrarEmVetorDeString(char bilhete[], char palavras[][TAMANHO_MAX_PALAVRA]){
    int linha = 0, coluna, caracter = 0;
    while(bilhete[caracter] != '\0'){ //ate acabar o bilhete
        if(ehLetra(bilhete[caracter])){//caso se inicie uma palavra
            coluna = 0;
            while(ehLetra(bilhete[caracter])){//enquanto esta naquela palavra
                palavras[linha][coluna] = bilhete[caracter];//vai adicionando letra por letra no vetor de string na posicao 'linha'
                coluna++;
                caracter++;
            }
            palavras[linha][coluna+1] = '\0';//leu algo que nao eh letra, logo terminou a palavra, eh adicionado um \0 para indicar o fim da string
            linha++; //vai para proxima posicao do vetor de string
        }
        else{
            caracter++;
        }
    }
}

int ehLetra(char caracter){
    return (('A' <= caracter) && ('Z' >= caracter)) || (('a' <= caracter) && ('z' >= caracter));
}
