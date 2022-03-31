# ifndef buscabinaria_h
# define buscabinaria_h

long int *alocaTiras(long int *comp, int n);
void mergesort(long int *comp, int esq, int dir);
void merge(long int *comp, int esq, int m, int dir);
double busca(long int *comp , int a, int n);
long int *desalocaTiras(long int *comp);

# endif