#include "hash.h"
#include <stdlib.h>
#include <stdio.h>


//Manter como especificado
void TLista_Inicia(TLista *pLista){
    pLista->pPrimeiro = NULL;
    pLista->pUltimo = NULL;
}

//Manter como especificado
int TLista_EhVazia(TLista *pLista){
    return (pLista->pPrimeiro == NULL);
}

//Manter como especificado
int TLista_Insere(TLista *pLista , TItem x){
    TCelula *aux = (TCelula*)malloc(sizeof(TCelula));
    if(aux == NULL)
        exit(1);
    aux->item = x;
    aux->pProx = NULL;
    if(TLista_EhVazia(pLista)){
        pLista->pPrimeiro = aux;
        pLista->pUltimo = aux;
    }
    else{
        pLista->pUltimo->pProx = aux;
        pLista->pUltimo = aux;
    }
    return 1;
}

//Manter como especificado
void THash_Inicia(THash *hash, int nro_listas){
    int i;
    hash->n = 0;
    hash->nro_listas = nro_listas;
    hash->v = (TLista*)malloc(nro_listas * sizeof(TLista));
    for(i = 0; i < nro_listas; i++)
        TLista_Inicia(&hash->v[i]);
}

//Manter como especificado
int THash_H(THash *hash, TChave chave){
    return(chave % hash->nro_listas);
}

//Manter como especificado
TCelula *THash_PesquisaCelula(THash *hash, TChave chave){
    int i = THash_H(hash, chave);
    TCelula *aux;

    if (TLista_EhVazia (&hash->v[i]))
        return NULL; // pesquisa sem sucesso
    aux = hash->v[i].pPrimeiro;
    while (aux->pProx != NULL && aux->item.chave != chave)
        aux = aux->pProx;
    if (chave == aux->item.chave)
        return aux;
    else
        return NULL; // pesquisa sem sucesso
}

//Manter como especificado
int THash_Insere (THash *hash, TItem x){
    if (THash_PesquisaCelula (hash, x.chave) == NULL){
        TLista_Insere(&hash->v[THash_H(hash, x.chave)], x);
        hash->n++;
        return 1;
    }
    return 0;
}
