#include <stdio.h>

typedef struct elementoLista{   
    char *dado;   
    struct elementoLista *anterior;   
    struct elementoLista *seguinte;   
}elemento;

typedef struct Lista{   
    elemento *inicio;   
    elemento *fim;   
    int tamanho;   
}Lista;   

void inicia(Lista *lista){   
    lista->inicio = NULL;   
    lista->fim = NULL;   
    lista->tamanho = 0;   
}   

int insere(Lista* lista, char* dado){   
    elemento *novoelemento;   
    
    if((novoelemento = aloc(novoelemento)) == NULL){ 
        return -1;   
    }
    strcpy(novoelemento->dado, dado);   

    novoelemento->seguinte = NULL;   
    novoelemento->anterior = lista->fim;
       
    lista->fim->seguinte = novoelemento;   
    lista->fim = novoelemento;   
    lista->tamanho++;   
    return 0;   
}  

int retira(Lista *lista, int pos){   
    int i;   
    elemento *retiraelemento;   

    if(lista->tamanho == 0){  
        return -1; 
    }  
    if(pos == 1){ 
        retiraelemento = lista->inicio;   
        lista->inicio = lista->inicio->seguinte;  

        if(lista->inicio == NULL){  
            lista->fim = NULL;   
        }
        else{  
            lista->inicio->anterior == NULL;   
        }
    }
    
    free(retiraelemento->dado);   
    free(retiraelemento);   

    lista->tamanho--;   
    return 0;   
}

void imprime(Lista *lista){ 
    elemento *emandamento;   
    emandamento = lista->inicio;  

    while(emandamento != NULL){   
        printf("%s ",emandamento->dado);   
        emandamento = emandamento->seguinte;   
    }   
}  