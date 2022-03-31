#include "fib.h"
#include<stdio.h>
#include<stdlib.h>

long int fibonacci(int i, TADfib *f){

    if(i == 0){
        //f->chamadas ++;
        return 0;
    }
    else if(i == 1){
        //f->chamadas ++;
        return 1;
    }
    /*else if(i == 2){
        f->chamadas ++;
        return 1;
    }*/
    else{
        f->chamadas += 2;
        return fibonacci (i - 1, f) + fibonacci (i - 2, f);
    }
}
