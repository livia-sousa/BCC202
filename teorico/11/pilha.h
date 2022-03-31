# ifndef pilha_h
# define pilha_h

typedef struct {
   char nome[20];
} TItem;

typedef struct celula {
    TItem item;
    struct celula *prox;
} TCelula;

typedef struct {
    TCelula *primeiro;
    TCelula *ultimo;
} TLista;

//Inicializa a lista
void TLista_Inicia(TLista *pLista);
//Retorna se a lista esta vazia
int TLista_EhVazia(TLista *pLista);
// Insere um item no final da lista
int TLista_InsereFinal(TLista *pLista, TItem x);

int TLista_RetiraPrimeiro(TLista *pLista, TItem *pX);
void TPilha_Inicia ( Pilha **) ;
void TPilha_EhVazia ( Pilha *) ;
void TPilha_Push ( Pilha *, int );/* insere no inicio */
int TPilha_Pop ( Pilha *) ;/* retira do inicio */
# endif
