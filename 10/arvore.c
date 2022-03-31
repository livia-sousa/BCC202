#include "arvore.h"
#include <stdio.h>
#include <stdlib.h>


void TArvore_Inicia (TNo **pRaiz){
    *pRaiz = NULL;
}

void TArvore_Insere_Raiz (TNo **ppRaiz , TItem x){
    if (*ppRaiz == NULL){
        *ppRaiz = TNo_Cria(x);
        return;
    }
    TArvore_Insere(ppRaiz, x);
}

int TArvore_Insere (TNo **pRaiz , TItem x){
    TNo **ppAux;
    ppAux = pRaiz;

    while(*ppAux != NULL ){
        if(x.Chave < (*ppAux)->item.Chave)
            ppAux = &((*ppAux)->pEsq);
        else if(x.Chave > (*ppAux)->item.Chave)
            ppAux = &((*ppAux)->pDir);
        else
            return 0;
    }
    *ppAux = TNo_Cria(x);
    return 1;
}

TNo *TNo_Cria (TItem x){
    TNo *pAux = (TNo*)malloc(sizeof(TNo));
    pAux->item = x;
    pAux->pEsq = NULL;
    pAux->pDir = NULL;
    return pAux;
}

void Prefixa(TNo *p){
    if (p == NULL)
        return;
    printf ("%ld ", p->item.Chave);
    Prefixa(p->pEsq);
    Prefixa(p->pDir);
}

void Infixa(TNo *p){
    if (p == NULL)
        return;
    Infixa(p->pEsq);
    printf ("%ld ", p->item.Chave);
    Infixa(p->pDir);
}

void Posfixa(TNo *p){
    if (p == NULL)
        return;
    Posfixa(p->pEsq);
    Posfixa(p->pDir);
    printf ("%ld ", p->item.Chave);
}
