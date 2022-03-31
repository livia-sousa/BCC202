#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void TLista_Inicia(TLista *pLista) {
    pLista->primeiro = (TCelula*) malloc (sizeof(TCelula));
    pLista->ultimo = pLista->primeiro;
    pLista->primeiro->prox = NULL;
}

int TLista_EhVazia(TLista *pLista) {
    return (pLista->primeiro == pLista->ultimo );
}

int TLista_InsereFinal(TLista *pLista, TItem x) {

    pLista->ultimo->prox = (TCelula*) malloc( sizeof (TCelula));
    pLista->ultimo = pLista->ultimo->prox;
    pLista->ultimo->item = x;
    pLista->ultimo->prox = NULL;
    return 1;
}

int TLista_RetiraPrimeiro(TLista *pLista, TItem *pX) {
    if (TLista_EhVazia(pLista))
        return 0; 
    TCelula *aux = pLista->primeiro->prox;
    TCelula *aux = pLista->ultimo->prox;
    TCelula *aux2 = pLista;
    while(aux->prox != NULL){
        aux2 = aux;
        
    }
    *pX = aux->item;
    pLista->primeiro->prox = aux->prox;
    free(aux);
    return 1;
}

void TLista_Imprime(TLista *pLista) {

    for(TCelula *i = pLista->primeiro->prox; i != NULL; i = i->prox){
        if( i == pLista->ultimo)
            printf("%s\n", i->item.nome);  
        else
            printf("%s ", i->item.nome);
    }
}

void TLista_Esvazia(TLista *pLista) {
    TCelula* aux = pLista->primeiro;
    while (aux != NULL){
        TCelula* aux2 = aux->prox;
        aux = aux2;
        free(aux);
    }   
    //free(pLista);
}

void TLista_append(TLista *pLista1, TLista *pLista2){
    pLista1->ultimo->prox = pLista2->primeiro->prox;
    pLista1->ultimo = pLista2->ultimo;
}

void TLista_include(TLista *pLista1, TLista *pLista2, char *str){
    TCelula* ant = NULL;
    TCelula* proximo = pLista1->primeiro;
    while (proximo != NULL && strcmp(proximo->item.nome,str) != 0){
        ant = proximo;
        proximo = proximo->prox;
    }
    ant->prox = pLista2->primeiro->prox;
    pLista2->ultimo->prox = proximo;
}

