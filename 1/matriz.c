#include "matriz.h"
#include<stdio.h>

void lerOperacao(char *operacao){
    scanf(" %c" , operacao);
    
}

void lerMatriz(double M[][12]){
    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 12; j++){
            scanf("%lf" , &M[i][j] );
        }
	}
}

double somaMatriz(double M[][12]){
    int x = 1, y = 11;
    double soma = 0;
    for(int i = 0; i < 5; i++){
         for(int j = x; j < y; j++){
            soma += M[i][j];
        }
        x++;
        y--;

    }
    return soma;
}

double media(double resultado){
    double m = resultado / 30;
    return m;
}

void printResultado(double resultado){
    printf("%.1lf", resultado);
}
