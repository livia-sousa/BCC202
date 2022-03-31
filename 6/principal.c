#include "pilha.h"
#include <stdio.h>
#include <string.h>

int main()
{
	Pilha pilha;
	char ch;
	Item item;
	int p;

	Pilha_Inicia(&pilha);

	while (scanf("%c", &ch)!=EOF){
		if(ch == '('){
			item.caracter = ch;
			Pilha_Push(&pilha, item);
		}
		else if(ch == ')'){
			p = Pilha_Pop(&pilha, &item);
		}
	}

	if(Pilha_EhVazia(&pilha) && p == 1)
		printf("correto\n");

	else
		printf("incorreto\n");
	
	//determinar o resultado

	Pilha_Esvazia(&pilha);

	return 0;//nao remova
}
