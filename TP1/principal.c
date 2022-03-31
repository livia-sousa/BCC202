#include "corretor.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    int n, s=0, p = 0;
    Correcao *C;

    lerNumSubmissoes(&n);
    C = alocaSubmissoes(C, n);
    lerSubmissoes(C, n);
    somarTempo(C, n, &s, &p);
    imprimirResultado(C, &s, &p);
    desalocaSubmissoes(C);
    
    return 0;
}