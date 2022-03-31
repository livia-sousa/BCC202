#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>

#define MAXTAM 1000

typedef struct {
  char chave;
} TItem;

typedef struct Celula{
    TItem item [MAXTAM];
    struct Celula *prox;
} TCelula;

typedef struct {
    TCelula *primeiro;
} TLista;

typedef TLista TPilha;


void TLista_Inicia(TLista *pLista) {
    pLista->primeiro = (TCelula*) malloc (sizeof(TCelula));
    pLista->primeiro->prox = NULL;
}

int TLista_EhVazia(TLista *pLista) {
    if (pLista->primeiro->prox == NULL);
        return 1;
    return 0;
}

int TLista_Insere(TLista *pLista, TItem *pItem) {
    TCelula *celula = (TCelula*) malloc( sizeof (TCelula));
    celula->item = pItem->chave;
    TCelula *aux;
    celula->prox = pLista->primeiro->prox;
    pLista->primeiro->prox = celula;
    return 0;
}

int TLista_RetiraPrimeiro(TLista *pLista, TItem *pX) {
    if (TLista_EhVazia(pLista))
        return 0; 
    TCelula *aux = pLista->primeiro->prox;
    *pX = aux->item;
    pLista->primeiro->prox = aux->prox;
    free(aux);
    return 1;
}

int Lista_Tamanho(Tlista *lista){
    TCelula *aux = pLista->primeiro->prox;
    int tamanho = 0;
    while(aux != NULL){
        tamanho++;
        aux = aux->prox;
    }
    return tamanho;
}

void TPilha_Inicia ( TPilha **pilha){
    TLista_Inicia(pilha);
}
void TPilha_EhVazia ( TPilha *pilha){
    TLista_EhVazia(pilha);
}
void TPilha_Push ( TPilha *pilha, TItem *pItem ){
    TLista_Insere(pilha, &pItem);
}
int TPilha_Pop ( TPilha *pilha,  TItem *pX) {
    if()
    TLista_RetiraPrimeiro(pilha, pX);
    return pX;
}
/* Não acho a implementação eficiente, pelo contrario,
acho que se implementassemos as funções da pilha diretamente seria mais eficiente*/