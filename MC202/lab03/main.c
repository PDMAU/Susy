/*Maurilio dos Santos Gonçalves 203648*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int string_igual(char stringA[], char stringB[]){
    int i = 0;/*Vai comparando caracter por caracter se achar algum diferente devolve falso*/
    while(stringA[i] !='\0' || stringB[i] != '\0'){
          if(stringA[i] != stringB[i])
            return 0;
          i++;
    }
    /*caso nao ache nenhum caracter diferente, as strings sao iguais*/
    return 1;
}

void concatena(char str[],char buffer[]){
    int i,j;
    /*posiciona o indice i no final do buffer*/
    for(i=0; buffer[i]!= '\0'; i++);
    for(j=0; str[j]!='\0'; j++,i++){/*a partir do final do buffer vai adicionando a nova string*/
        buffer[i] = str[j];
    }
    buffer[i] ='\0';

}

void compara(char str[],char buffer[]){
    int isIgual = string_igual(str, buffer);
    if(isIgual)
        printf("IGUAL\n");
    else
        printf("DIFERENTE\n");

}
void substr(int inicio, int tamanho, char buffer[]){
    int i, j;
    for(i= inicio, j=0; j < tamanho; i++, j++){
        buffer[j] = buffer[i];
    }
    buffer[j] = '\0';
}

int main(){
    char buffer[MAX];
    buffer[0] ='\0';
   while(1){
    char comando[4];
    scanf("%s", comando);
    if(string_igual(comando,"CAT")){
        char palavra[MAX];
        scanf("%s", palavra);
        concatena(palavra, buffer);
        printf("%s\n",buffer);
    }
    else if(string_igual(comando,"SUB")){
        int x, tam;
        scanf("%d %d", &x, &tam);
        substr(x,tam, buffer);
        printf("%s\n",buffer);
    }
    else if(string_igual(comando,"CMP")){
        char palavra[MAX];
        scanf("%s", palavra);
        compara(palavra, buffer);
    }
    else if(string_igual(comando,"END")){
        break;
    }
   }
    return 0;
}
