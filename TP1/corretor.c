#include "corretor.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct correcao{
    char problema[26];
	char julgamento[20];
	int t[300];
};

void lerNumSubmissoes(int *n){
	scanf("%d", n);
}

Correcao *alocaSubmissoes (Correcao *C, int n){
    C = (Correcao*) malloc (n * sizeof(Correcao));
    if(C == NULL){
        exit(1);
    }
    return C;
}

void lerSubmissoes(Correcao *C, int n){
    for(int i = 0; i < n; i++){
        scanf(" %c", C[i].problema);
        scanf("%d", C[i].t);
        scanf("%s",  C[i].julgamento);
    }
}

void somarTempo(Correcao *C, int n, int *s, int *p){
    for(int i = 0; i < n; i++){
        if(strcmp(C[i].julgamento, "correto") == 0){
            *p +=  *C[i].t;
            *s += 1;
            for(int j = 0; j < n; j++){
                if(strcmp(C[i].problema, C[j].problema) == 0 && strcmp(C[j].julgamento, "incompleto") == 0){
                    *p += 20;
                } 
            } 
        }
    }
}  

void imprimirResultado(Correcao *C, int *s, int *p){
    printf("%d %d\n", *s, *p);
}

void desalocaSubmissoes(Correcao *C){
    free(C);
    C = NULL;
}
