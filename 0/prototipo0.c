#include <stdio.h>
int main()
{
    double M[12][12], soma = 0, media = 0;
    int i, j, x = 1, y = 11;
    char O;
    scanf("%s" , &O);

    for(i = 0; i < 12; i++){
        for(j = 0; j < 12; j++){
            scanf("%lf" , &M[i][j] );
        }
	}

    for(i = 0; i < 5; i++){
         for(j = x; j < y; j++){
            soma += M[i][j];
            
        }
        x++;
        y--;
    }

    if(O == 'S'){
        printf("%.1lf", soma);
    }
    else if(O == 'M'){
        media = soma / 30;
        printf("%.1lf", media);
    }

    return 0;
}
