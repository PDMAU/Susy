/*
Nome: Maurilio dos Santos Gonçalves 
RA:203648
*/
#include <stdio.h>
#include <stdlib.h>

float  ** alocaMatriz(int tam) {
    int i, j;	
    float ** matriz = (float**)malloc(tam * sizeof(float*));
	if(matriz == NULL){
		exit(1);
	}

    for(i =0; i < tam; i++) {
        matriz[i] = (float*) malloc(tam * sizeof(float));
		if(matriz[i] == NULL){
			exit(1);
		}
        for (j = 0; j < tam; j++) {
            matriz[i][j] = 0;
        }
    }
    return matriz;
}

void destruirMatriz( float **matriz, int tam){
	int i;
    for(i =0; i < tam; i++) {
        free(matriz[i]);
    }
	free(matriz);
}

void exibeMatriz(float ** matriz, int tam) {
    int i, j;
    for(i =0; i < tam; i++) {
        for(j =0; j < tam; j++) {
            if(j==tam-1)
                printf("%0.1f", matriz[i][j]);
            else
                printf("%0.1f ", matriz[i][j]);
        }
        printf("\n");
    }
}

float ** tranformaMatrizPermutacao(int * vetor, int tam) {
    float ** matriz = alocaMatriz(tam);
    int i;

    for(i=0; i<tam; i++) {
        matriz[vetor[i]-1][i]=1;
    }

    return matriz;
}



float ** multiplicaMatriz(float **a, float **b, int tam) {
    float ** matriz = alocaMatriz(tam);
    int i, k, j;
    for (i= 0; i < tam; i++) {
        for (j= 0; j<tam; j++) {
            for (k= 0; k<tam; k++) {
                matriz[i][j] = matriz[i][j] + (a[i][k] * b[k][j]);
            }
        }
    } 
	return matriz;
}

int main() {
    int tam, i, j;
    int * vetor;
    float ** matrizPermutacao ;
    float ** matriz ;
	float ** matrizResultado;

    scanf("%d\n", &tam);
	/*Leitura e processamento do vetor q representa uma matriz na forma reduzida*/
    vetor = (int*) malloc(tam * sizeof(int));	
	if(vetor == NULL){
		exit(1);
	}
    for(i =0; i < tam; i++) {
        scanf("%d ", &vetor[i]);
    }

    matrizPermutacao = tranformaMatrizPermutacao(vetor, tam);
    matriz = alocaMatriz(tam);
    for(i =0; i < tam; i++) {
        for(j =0; j < tam; j++) {
            scanf("%f", &matriz[i][j]);
        }
    }
    matrizResultado = multiplicaMatriz(matrizPermutacao, matriz, tam);
	exibeMatriz(matrizResultado, tam);

	free(vetor);
	destruirMatriz(matrizPermutacao, tam);
	destruirMatriz(matriz, tam);
	destruirMatriz(matrizResultado, tam);

    return 0;
}
