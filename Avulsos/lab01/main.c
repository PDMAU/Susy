#include <stdio.h>
#include <stdlib.h>
#define TAMANHO_MAX_PALAVRA 47
#define TAMANHO_BILHETE 50000
#define TAMANHO_VETOR 1000


void quebrarEmVetorDeString(char bilhete[], char palavras[][TAMANHO_MAX_PALAVRA]);

int ehLetra(char caracter);

int main()
{
    char bilhete[TAMANHO_BILHETE];
    int i, j, numeros[TAMANHO_VETOR];
    char palavras[TAMANHO_VETOR][TAMANHO_MAX_PALAVRA];

    scanf("%[^\n]", bilhete);
    quebrarEmVetorDeString(bilhete, palavras);
    scanf("%d", &i);
    for(j = 0; j < i; j++){
        scanf("%d", &numeros[j]);
    }
    for(j=0; j < i; j++){
        printf("%s", palavras[numeros[j]]);
        if( j != (i-1)){
            printf(" ");
        }
    }
    return 0;
}


void quebrarEmVetorDeString(char bilhete[], char palavras[][TAMANHO_MAX_PALAVRA]){
    int linha = 0, coluna, caracter = 0;
    while(bilhete[caracter] != '\0'){
        if(ehLetra(bilhete[caracter])){
            coluna = 0;
            while(ehLetra(bilhete[caracter])){
                palavras[linha][coluna] = bilhete[caracter];
                coluna++;
                caracter++;
            }
            palavras[linha][coluna+1] = '\0';
            linha++;
        }
        else{
            caracter++;
        }
    }
}

int ehLetra(char caracter){
    return (('A' <= caracter) && ('Z' >= caracter)) || (('a' <= caracter) && ('z' >= caracter));
}
