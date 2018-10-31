#ifndef LISTA_MEXER
#define LISTA_MEXER

typedef struct matriz M;

int AdicionarMatriz(M **plista, char nome[], int linha, int coluna);

float **criarMatriz(int linha, int coluna);

int destruir(M **plista, char nome[]);

int imprimir(M *lista, char nome[]);

void imprimeMatriz(M *lista);

int atribuirElemento(M **plista, char nome[], int c, int l, float valor);

int atribuirLinha(M **plista, char nome[], int linha, float valores[], int count);

int atribuirColuna(M **plista, char nome[], int coluna, float valores[], int count);

int transporMatriz (M **plista, char nomeMatriz[], char nomeNovo[]);

# endif