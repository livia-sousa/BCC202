#include <stdio.h>

#define INICIO 0
#define MAXTAM 1000

typedef struct{
    int chave; 
}TItem;

typedef struct{
    TItem item [MAXTAM];
    int primeiro, ultimo;
}TLista;

TLista concatena(TLista* lista1, TLista* lista2){
    int ultimo1 = lista1->item;
    int ultimo2 = lista2->ultimo;
    TLista listaConcatenada;
    for(int i = 0; i < ultimo1; i++){
        listaConcatenada.item[i] = lista1->item[i];
    }
    int aux = 0;
    for(int i = ultimo1; i < ultimo1 + ultimo2; i++){
        listaConcatenada.item[i] = lista2->item[aux];
        aux++;
    }
    listaConcatenada.primeiro = lista1->primeiro; 
    listaConcatenada.ultimo = lista1->ultimo + lista2->ultimo;
    return listaConcatenada;
}

void divide(TLista* lista1, TLista* lista2, int n){
    int aux = 0;
    for(int i = n; i < lista1->ultimo; i++){
        lista2->item[aux].chave = lista1->item[i].chave;
        aux++;
    }
    lista2->primeiro = 0;
    lista2->ultimo = aux;
    lista1->ultimo = n - aux;
}

TLista copia(TLista* lista){
    TLista copiar;
    for(int i = 0; i < lista->ultimo; i++){
       copiar.item[i] = lista->item[i];
    }
    copiar.primeiro = lista->primeiro; 
    copiar.ultimo = lista->ultimo;
    return copiar;
}

void pesquisa(TLista* lista, int chave){
    for(int i = 0; i < lista->ultimo; i++){
       if(lista->item[i].chave == chave){
           printf("Elemento encontrado!\n");
           return;
        }
    }
    printf("Elemento não encontrado!\n");
}