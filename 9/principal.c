#include "prioridade.h"
#include <stdio.h>

int main ()
{
	int n, m;
	TipoCaixa *heap;

	scanf("%d %d", &n, &m);

	heap = alocaVetor(heap, n);

	for(int i = 0; i < n; i++){
		scanf("%d", &heap[i].tempo);
		heap[i].chave = i + 1;
		heap[i].disponivel = 0;
	}

	Heap_Constroi(heap, n);

	while (m--) {
		int c;
		scanf("%d", &c);
		heap[0].disponivel += heap[0].tempo * c;
		Heap_Constroi(heap, n);
	}

	int resultado = 0;
	for(int i = 0; i < n; i++){
		if(heap[i].disponivel > heap[i+1].disponivel && heap[i].disponivel > resultado )
			resultado = heap[i].disponivel;
	}

	desalocaVetor(heap);
	printf("%d\n", resultado);
	return 0;
}
