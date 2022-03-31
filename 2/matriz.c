#include "matriz.h"
#include <stdio.h>
#include <stdlib.h>

void lerOrdem(int *ordem){
    scanf("%d", ordem);
}

double **alocaMatriz(double **M, int ordem){
    M = (double**) malloc(ordem * sizeof(double*));
    if(M == NULL){
        exit(1);
    }
    for(int i = 0; i < ordem; i++){
        M[i] = (double*) malloc (ordem * sizeof(double));
        if(M == NULL){
            exit(1);
        }
    }
    return M;
}

double **desalocaMatriz(double **M, int ordem){
    for(int i = 0; i < ordem; i++)
        free(M[i]);
    free (M);
}

//manter como especificado
void lerOperacao(char *operacao){
    scanf(" %c", operacao);
}

void lerMatriz(double **M, int ordem){
    for(int i = 0; i < ordem; i++){
        for(int j = 0; j < ordem; j++){
            scanf("%lf", &M[i][j]);
        }
    }
}

double somaMatriz(double **M, int ordem){
    int x = 1, y = ordem - 1, contador = 0;
    double soma = 0;
    for(int i = 0; i < ordem / 2.0; i++){
        for(int j = x; j < y; j++){
            soma += M[i][j];
            contador++;
        }
        x++;
        y--;
    }
    return soma;
}

double media(double resultado, int ordem){
    double total;
    total = resultado / (((ordem * ordem)/4) - ordem / 2); 
    return total;
}

void printResultado(double resultado){
    printf("%.1lf", resultado);
}
