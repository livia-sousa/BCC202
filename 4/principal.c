#include "fib.h"
#include <stdio.h>
#include<stdlib.h>

int main()
{
    int num, n;
    TADfib *f;

    scanf("%d", &num);
    
    f = (TADfib*) malloc (num*sizeof(TADfib));
    
    if(f == NULL)
        printf("error");

   
    for(int cont = 0; cont < num; cont ++){
        scanf("%d", &f[cont].i);
        f[cont].resultado = fibonacci(f[cont].i, f);
    }
    for(int cont = 0; cont < num; cont ++){
        printf("fib(%d) = %ld chamadas %ld\n", f[cont].i,f[f[cont].i].chamadas, f[cont].resultado);
    }
    //printf("fib(%d) = %ld chamadas = %ld\n", f->i, f->chamadas, f->resultado );
    
    //fazer a leitura do numero de casos de teste
    //ler o caso de teste e processar antes de ler o proximo
    //imprimir a resposta no formato adequado
    return 0;//nao remova
}
