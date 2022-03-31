#include "buscabinaria.h"
#include <stdio.h>

int main(){

    int n, a;
    long int *comp;
    double soma = 0;

    do{
        scanf("%d %d", &n, &a);
        comp = alocaTiras(comp, n);

        if(n != 0 && a != 0){
            for(int i = 0; i < n; i++){
                scanf("%ld", &comp[i]);
                soma += comp[i];
            }
            if(soma == a)
                printf(":D\n");
            
            else if(soma < a)
                printf("-.-\n");
            
            else{
                mergesort(comp, 0, n-1);
                soma = busca(comp, a, n);
                printf("%.4lf\n", soma);
            }
            soma = 0;
            comp = desalocaTiras(comp);
        }

    }while(n!=0 && a!=0);
}