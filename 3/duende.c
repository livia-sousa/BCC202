#include "duende.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct duende {
	char nome[20];
	int idade;
	int escalado;
};

struct time {
	char lider[20];
	char entregador[20];
	char piloto[20];
	int idadeLider;
	int idadeEntregador;
	int idadePiloto;
};

void lerQuantidade(int *qtd){
	scanf("%d", qtd);
}

TADduende *alocaDuendes(TADduende *D, int qtd){
	D = (TADduende*) malloc (qtd * sizeof(TADduende));
	if(D == NULL){
        exit(1);
    }
	return D;
}

//Manter como especificado
TADtime *alocaTimes(TADtime *T, int qtd){
	T = (TADtime*) malloc (qtd * sizeof(TADtime));
	if(T == NULL){
        exit(1);
    }
	return T;
}

//Manter como especificado
TADduende *desalocaDuendes(TADduende *D){
	free(D);
}

//Manter como especificado
TADtime *desalocaTimes(TADtime *T){
	free(T);
}

//Manter como especificado
void lerDuendes(TADduende *D, int qtd){
  int i;
  for(i=0; i < qtd; i++){
    scanf("%s %d", D[i].nome, &D[i].idade);
    D[i].escalado = 0;
  }
  //ler nome e idade de cada duente
  //aproveitar para colocar o valor 0 no campo escalado
}

//Manter como especificado
void escalarTimes(TADduende *D, TADtime *T, int qtd){
	int i, indice;

	for (i=0; i < qtd/3; i++){
		indice = proximoMaisVelho(D, qtd);
		D[indice].escalado = 1;
    	strcpy(T[i].lider, D[indice].nome);
    	T[i].idadeLider = D[indice].idade;
 	}
	for (i=0; i < qtd/3; i++){
    	indice = proximoMaisVelho(D, qtd);
		D[indice].escalado = 1;
    	strcpy(T[i].entregador, D[indice].nome);
    	T[i].idadeEntregador = D[indice].idade;
 	}
	for (i=0; i < qtd/3; i++){
    	indice = proximoMaisVelho(D, qtd);
		D[indice].escalado = 1;
    	strcpy(T[i].piloto, D[indice].nome);
    	T[i].idadePiloto = D[indice].idade;
 	}
}

int proximoMaisVelho(TADduende *D, int qtd){
	int indice, maiorIdade = 0;
	for(int i = 0; i < qtd; i++){
		if(D[i].escalado == 0){
			if(maiorIdade < D[i].idade){
				maiorIdade = D[i].idade;
				indice = i;
			}
		}
	}
	return indice;
}

//Manter como especificado
void printTimes(TADtime *T, int qtd){
	for(int i = 0; i < qtd; i++){
		printf("Time %d\n", i+1);
		printf("%s %d\n", T[i].lider, T[i].idadeLider);
		printf("%s %d\n",T[i].entregador, T[i].idadeEntregador);
		printf("%s %d\n",T[i].piloto, T[i].idadePiloto);
		printf("\n");
	}
}
