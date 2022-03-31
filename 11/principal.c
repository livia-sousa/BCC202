#include "hash.h"
#include <stdio.h>

int main(){
	THash hash;
	TItem x;
	int n, q;
	
	scanf("%d %d", &n, &q);
	THash_Inicia(&hash, n);
	
	//printf("%d\n", hash.n);
	for(int i = 0; i < q; i++){
		scanf("%d", &x.chave);
		THash_Insere(&hash, x);
		//printf("%d\n", hash.n);
	}

	for(int i = 0; i < hash.nro_listas; i++){
		TCelula *aux = hash.v[i].pPrimeiro;
		printf("%d -> ", i);
		while(aux != NULL){
			printf("%d -> ", aux->item.chave);
			aux = aux->pProx;
		}
		printf("\\\n");
	}
   return 0;
}
