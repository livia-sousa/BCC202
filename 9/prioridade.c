#include "prioridade.h"
#include <stdio.h>
#include <stdlib.h>

//Manter como especificado
TipoCaixa *alocaVetor(TipoCaixa *heap, int n){
    heap = (TipoCaixa*) malloc(n * sizeof (TipoCaixa));
	if(heap == NULL)
        exit(1);
	return heap;
}

//Manter como especificado
TipoCaixa *desalocaVetor(TipoCaixa *heap){
    free(heap);
    heap = NULL;
    return heap;
}

//Manter como especificado
void Heap_Constroi(TipoCaixa *heap, int n){
    int esq;
    esq = (n / 2) - 1; // esq = no anterior ao primeiro no folha do heap
    while (esq >= 0) {
        Heap_Refaz(heap, esq, n-1);
        esq--;
    }
}

//Manter como especificado
void Heap_Refaz(TipoCaixa *heap, int esq, int dir){

    int i = esq;
    int j = i*2 + 1;

    TipoCaixa aux = heap[i];

    while (j <= dir){
        if (j < dir){
            if (heap[j].disponivel > heap[j+1].disponivel)
                j++;
            else if( heap[j].disponivel == heap[j+1].disponivel){
                if( heap[j].chave > heap[j+1].chave)
                    j++;
            }
        }
        if (aux.disponivel < heap[j].disponivel)
            break;
        else if(aux.disponivel == heap[j].disponivel){
            if(aux.chave < heap[j].chave)
                break;
        }
        heap[i] = heap[j];
        i = j;
        j = i*2 + 1;
    }
    heap[i] = aux;
}
