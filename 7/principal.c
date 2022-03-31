#include "ordenacao.h"
#include <stdio.h>

int main ()
{
	int i;
	int n, k;
	TipoAluno *alunos;
	scanf("%d %d", &n, &k);
	alunos = alocaAlunos(alunos, n);
	for(int i = 0; i < n; i++){
		scanf("%s", alunos[i].nome);
	}
	ordena(alunos, n);
	printf("%s\n", alunos[k-1].nome);
	
	desalocaAlunos(alunos);


	//ler as quantidades
	//alocar o vetor
	//preencher o vetor
	//ordenar
	//imprimir o resultado
	//desalocar o vetor
  return 0;
}
