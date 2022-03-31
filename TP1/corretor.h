# ifndef corretor_h
#define corretor_h

typedef struct correcao Correcao;
void lerNumSubmissoes(int *n);
Correcao *alocaSubmissoes (Correcao *C, int n);
void lerSubmissoes(Correcao *C, int n);
void somarTempo(Correcao *C, int n, int *s, int *p);
void imprimirResultado(Correcao *C, int *s, int *p);
void desalocaSubmissoes(Correcao *C);

#endif