#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int posicaoValida(int x,int y,char** matriz,int numLinhas, int numColunas);


int achouCaminho(int x_atual, int y_atual,int x_final,int y_final,char** matriz,int numLinhas, int numColunas){

    if(!posicaoValida(x_atual,y_atual,matriz,numLinhas,numColunas)){
        return 0;
    }
    if(x_final == x_atual && y_final == y_atual){
        return 1;
    }

    matriz[y_atual][x_atual] = '*';
    if(achouCaminho(x_atual+1,y_atual,x_final,y_final,matriz,numLinhas,numColunas)){
        matriz[y_atual][x_atual] = ' ';
        return 1;
    }else if(achouCaminho(x_atual,y_atual+1,x_final,y_final,matriz,numLinhas,numColunas)){
        matriz[y_atual][x_atual] = ' ';
        return 1;
    }else if(achouCaminho(x_atual-1,y_atual,x_final,y_final,matriz,numLinhas,numColunas)){
        matriz[y_atual][x_atual] = ' ';
        return 1;
    }else if(achouCaminho(x_atual,y_atual-1,x_final,y_final,matriz,numLinhas,numColunas)){
        matriz[y_atual][x_atual] = ' ';
        return 1;
    }
    return 0;

}


int main()
{
   return 0;
}
