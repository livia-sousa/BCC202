#include "fib.h"
#include <stdio.h>
#include<stdlib.h>

int main()
{
    int num, aux = 0;
    
    TADfib f;

    scanf("%d", &num);
   do{
        f.chamadas = 0;
        scanf("%d", &f.i);
        f.resultado = fibonacci(f.i, &f);

        printf("fib(%d) = %ld chamadas = %ld\n", f.i, f.chamadas, f.resultado);
        aux++;

   }while(aux < num);
   
    
    //fazer a leitura do numero de casos de teste
    //ler o caso de teste e processar antes de ler o proximo
    //imprimir a resposta no formato adequado
    return 0;//nao remova
}
