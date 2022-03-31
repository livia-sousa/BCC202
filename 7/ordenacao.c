#include "ordenacao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Manter como especificado
TipoAluno *alocaAlunos(TipoAluno *alunos, int n){
	alunos = (TipoAluno*) malloc(n * sizeof (TipoAluno));
	if(alunos == NULL){
        exit (1);
    }
	return alunos;
}

//Manter como especificado
TipoAluno *desalocaAlunos(TipoAluno *alunos){
	free(alunos);
}

void ordena(TipoAluno *alunos, int n){
	char trocar[20];
	for(int i = 0; i < n; i++){
		int troca = 0;
 		for(int j = 1; j < n - i; j++){
 			if (strcmp(alunos[j - 1].nome, alunos[j].nome ) > 0){
				strcpy(trocar, alunos[j - 1].nome);
				strcpy(alunos[j - 1].nome, alunos[j].nome);
				strcpy(alunos[j].nome, trocar);
				troca += 1;
			}
		}
		if(troca == 0){
			break;
		}
	}
}
