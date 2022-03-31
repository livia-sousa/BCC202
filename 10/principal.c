#include "arvore.h"
#include <stdio.h>

int main (){
	int n, no;
	TArvore *arvore;
	TItem x;

	TArvore_Inicia(arvore);

	scanf("%d", &n);
	scanf("%d", &no);
	x.Chave = no;
	TArvore_Insere_Raiz(arvore, x);

	for(int i = 1; i<n; i++) {
		scanf("%d", &no);
		x.Chave = no;
		TArvore_Insere(arvore, x);
	}
	printf("PREFIXA: ");
	Prefixa(*arvore);
	printf("\n");

	printf("INFIXA: ");
	Infixa(*arvore);
	printf("\n");

	printf("POSFIXA: ");
	Posfixa(*arvore);
	return 0;
}
