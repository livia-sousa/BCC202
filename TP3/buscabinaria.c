#include "buscabinaria.h"
#include <stdio.h>
#include  <stdlib.h>

long int *alocaTiras(long int *comp, int n){
    comp = (long int*) malloc(n * sizeof(long int));
    if(comp == NULL)
        exit(1);
    return comp;
}

void mergesort(long int *comp, int esq, int dir){
    if (esq < dir){
        int m = (esq + dir) / 2;
        mergesort(comp, esq, m);
        mergesort(comp, m + 1, dir);
        merge(comp, esq, m, dir);
    }
}

void merge(long int *comp, int esq, int m, int dir){
    int tamE = (m - esq + 1);
    int tamD = (dir - m);

    double *vetE = (double*) malloc (tamE * sizeof(double));
    double *vetD = (double*) malloc (tamD * sizeof(double));

    for (int i = 0; i < tamE; i++)
        vetE[i] = comp[i + esq];
    
    for (int j = 0; j < tamD; j++)
        vetD[j] = comp[m + j + 1];

    int i = 0, j = 0, k = 0;

    for (k = esq; k <= dir; k++){

        if (i == tamE)
            comp[k] = vetD[j++];

        else if(j == tamD)
            comp[k] = vetE[i++];
        
        else if(vetE[i] <= vetD[j])
            comp[k] = vetE[i++];
        
        else
            comp[k] = vetD[j++];
    }
    free(vetE);
    free(vetD);
} 


double busca(long int *comp , int a, int n){
    double esq = comp[0], dir = comp[n - 1], corte, soma;
	while(soma != a && esq <= dir){
		soma = 0;
		corte = (esq + dir) / 2;
        for (int i = n - 1; i > 0; i--){
            if (comp[i] > corte)
                soma += comp[i] - corte;
            else
                break;
        }
		if(soma > a)
            esq = corte + 0.000001;
        
		else if(soma < a)
            dir = corte - 0.000001;
	}
    return corte;
}


long int *desalocaTiras(long int *comp){
    free(comp);
    comp = NULL;
    return comp;
}