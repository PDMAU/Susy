/*
Nome: Maurilio dos Santos Gonçalves 
RA:203648
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CARACTER_OBSTACULO 'X'
#define CARACTER_CAMINHO '*'


int posicaoValida(int x,int y,char** matriz,int numLinhas, int numColunas){
    if((x>= numColunas) ||(x<0) ||(y >= numLinhas) ||(y < 0) ||(matriz[y][x] == CARACTER_OBSTACULO))
        return 0;
    return 1;
}


int achouCaminho(int x_atual, int y_atual,int x_final,int y_final,char** matriz,int numLinhas, int numColunas){

    if(!posicaoValida(x_atual,y_atual,matriz,numLinhas,numColunas)){/*Posicao invalida*/
        return 0;
    }
    if(x_final == x_atual && y_final == y_atual){ /*Se chegou na saida*/
        matriz[y_atual][x_atual] = CARACTER_CAMINHO;
        return 1;
    }

    matriz[y_atual][x_atual] = CARACTER_OBSTACULO ;    
    if(achouCaminho(x_atual+1,y_atual,x_final,y_final,matriz,numLinhas,numColunas)){ /*Testa posicao da direita*/
        matriz[y_atual][x_atual] = CARACTER_CAMINHO;
        return 1;
    }else if(achouCaminho(x_atual,y_atual+1,x_final,y_final,matriz,numLinhas,numColunas)){/*Testa posicao de cima*/
        matriz[y_atual][x_atual] = CARACTER_CAMINHO;
        return 1;
    }else if(achouCaminho(x_atual-1,y_atual,x_final,y_final,matriz,numLinhas,numColunas)){/*Testa posicao da esquerda*/
        matriz[y_atual][x_atual] = CARACTER_CAMINHO;
        return 1;
    }else if(achouCaminho(x_atual,y_atual-1,x_final,y_final,matriz,numLinhas,numColunas)){/*Testa posicao de baixo*/
        matriz[y_atual][x_atual] = CARACTER_CAMINHO;
        return 1;
    }
    return 0;

}
char** alocarMatriz(int numeroLinhas, int numeroColunas){
    char** matriz;
    int i;
    matriz = malloc(sizeof(char*)*numeroLinhas);
    for(i=0; i < numeroLinhas; i++){
        matriz[i] = malloc(sizeof(char)*(numeroColunas));
    }
    return matriz;
}
void desalocarMatriz(char **matriz, int numeroLinhas){
    int i;
    for(i=0; i < numeroLinhas; i++){
        free(matriz[i]);
    }
    free(matriz);
}

int main(){
    int lt, ct, le, ce, ls, cs, i, j;
    char **matriz;
    scanf("%d %d %d %d %d %d", &lt,&ct,&le,&ce,&ls,&cs);
    matriz = alocarMatriz(lt,ct+1);/*Aloca uma matriz com uma coluna a mais para comportar o \0, entretanto nunca eh acessado essa posicao*/
    for(i=0; i < lt; i++){
        scanf("%s", matriz[i]);
    }
    achouCaminho(ce,le,cs,ls, matriz, lt, ct);
    for(i=0; i < lt; i++){
        for(j=0; j < ct; j++){
            if(matriz[i][j] != CARACTER_CAMINHO){/*Qualquer caracter q nao eh o de caminho eh printado espaco vazio*/
                printf("%c",' ');
            }else{
                printf("%c",matriz[i][j]);
            }
        }
        printf("\n");
    }
    desalocarMatriz(matriz, lt);
   return 0;
}
