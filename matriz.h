#ifndef MATRIZ_MEXER
#define MATRIZ_MEXER

typedef struct matriz M;

int somarMatriz(M **plista, char nomeMat1[], char nomeMat2[], char nomeResult[]);

int dividirMatriz(M **plista, char nomeMat1[], char nomeMat2[], char nomeResult[]);

int multiplicar1(M **plista, char nomeMat1[], char nomeMat2[], char nomeResult[]);

int multiplicar2(M **plista, char nomeMat1[], char nomeMat2[], char nomeResult[]);

# endif