#include <stdio.h>
#include <stdlib.h>

float * reverso ( int n , float* v);
float * reverso ( int n , float* v){
    
    float* vetor;
    vetor = (float*) malloc(n*sizeof(float));
    if(vetor == NULL){
        printf("Memoria insuficiente.\n");
        exit(0) ;
    }
    int m = n;
    for(int i = 0; i < n; i++){
        vetor[i] = v[m-1];
        m--;
    }
    for(int i = 0; i < n; i++){
      printf("%f  \n", vetor[i]);
    }
    return vetor;

}
int main(){
    int n; 
    float *v;
    scanf("%d" , &n);
    v = (float*) malloc(n*sizeof(float));
    if (v == NULL) {
        printf("Memoria insuficiente.\n");
        exit(0);
    }
    for (int i = 0; i < n; i++){
        scanf("%f", &v[i]);
    }
    reverso (n,v);
    free(v);
    return 0;
}