#include "ordenacao.h"
#include <stdio.h>
#include <stdlib.h>

//Manter como especificado
int *alocaVetor(int *vetor, int n){
    vetor = (int*) malloc(n * sizeof (int));
	if(vetor == NULL)
        exit (1);
	return vetor;
}

//Manter como especificado
int *desalocaVetor(int *vetor){
    free(vetor);
}

void ordenacao(int *vetor, int n, int *movimentos){

    if (n > 1){
		ordenacao(vetor, n / 2, movimentos);
		ordenacao(vetor + (n / 2), (n + 1) / 2, movimentos);
		int i = 0, j = n / 2, aux[n];

		for(int k = 0; k < n; k++){
            if(i < n / 2 && j < n){
                if(vetor[j] < vetor[i]){
					aux[k] = vetor[j];
                    *movimentos += (n / 2) - i;
                    j++;     
                }
				else if(vetor[i] < vetor[j]){
					aux[k] = vetor[i];
                    i++;
                }
				else{
					aux[k] = vetor[i];
                    i++;
                }	
			}
			else if (i < n / 2){
				aux[k] = vetor[i];
                i++;
            }
			else{
				aux[k] = vetor[j];
                j++;
            }
		}
	}
}
