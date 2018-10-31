#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

struct matriz {

	char nome[10];
	int linha, coluna;
	M *prox, *mat;
};

int adicionarMatriz(M **plista, char nome[], int linha, int coluna) {

	int i, j, flag = 0;
    M *lista = *plista;

    while (lista != NULL) {

        if(strcmp(lista->nome, nome) == 0){

            flag = 1;
            break;
        }
        lista = lista->prox;
    }

    if(flag == 1)
        return (-1);

    else {

	   M *aux = (M *) malloc(sizeof(M));

        if (aux == NULL)
    	   return (-1);

        strcpy(aux->nome, nome);

        aux->linha = linha;

        aux->coluna = coluna;

   	    aux->prox = (*plista);

        float **matriz = criarMatriz(linha, coluna);

        aux->mat = matriz;

        (*plista) = aux;

        return (1);
    }
}

float **criarMatriz(int linha, int coluna) {

	float **matriz;
    int   i;

    matriz = (float **) malloc(linha * sizeof(float *));

    for (i = 0; i < linha; i++)
    	matriz[i] = (float*) malloc (coluna * sizeof(float));

    return matriz;
}

int destruir(M **plista, char nome[]) {

    M *a = NULL, *p = *plista;

    while(p != NULL && strcmp((p)->nome, nome) != 0) {

        a = p;
        p = p->prox;
    }

    if(p != NULL) {

        if(strcmp(p->nome, nome) == 0) {

            if(a == NULL)
                *plista = p->prox;

            else
                a->prox = p->prox;

            free(p);
            return(1);
        }
    }
    return(-1);
}

int imprimir(M *lista, char nome[]) {

    int flag = 0;

	while (lista != NULL) {

		if(strcmp(lista->nome, nome) == 0){

            flag = 1;
            break;
        }
        lista = lista->prox;
    }

    if (flag == 1) {

        imprimeMatriz(lista);
        return (1);
    }

    else
        return(-1);
}

void imprimeMatriz(M *lista) {

	float **matriz = lista->mat;

	int i, j, linha = lista->linha, coluna = lista->coluna;

    for (i = 0; i < linha; ++i) {

    	for (j = 0; j < coluna; ++j) {

    		printf("%6.2f ", matriz[i][j]);
    	}
    	printf("\n");
    }
}

int atribuirElemento(M **plista, char nome[], int c, int l, float valor) {

    M *lista = *plista;

    int linha = lista->linha, coluna = lista->coluna, flag = 0;

    if (l > (linha -1) || c > (coluna - 1))
        return(-1);

    else {

       while (lista != NULL) {

            if(strcmp(lista->nome, nome) == 0){

                flag = 1;
                break;
            }
            lista = lista->prox;
        }

        if (flag == 0)
            return(-1);

        if (flag == 1) {

            float **matriz = lista->mat;

            matriz[c][l] = valor;
            return(1);
        }
    }
}

int atribuirLinha(M **plista, char nome[], int linha, float valores[], int count) {

    M *lista = *plista;
    int i, flag = 0;

    while (lista != NULL) {

    if(strcmp(lista->nome, nome) == 0){

        flag = 1;
        break;
        }
    lista = lista->prox;
    }

    if(count > lista->coluna || linha >= lista->linha) {

        return (-1);
    }

    else {

        float **matriz = lista->mat;

        for(i = 0; i < count; i++) {

            matriz[linha][i] = valores[i];
        }

        return(1);
    }
}

int atribuirColuna(M **plista, char nome[], int coluna, float valores[], int count) {

    M *lista = *plista;
    float **matriz = lista->mat;
    int i, flag = 0;

    while (lista != NULL) {

    if(strcmp(lista->nome, nome) == 0){

        flag = 1;
        break;
        }
    lista = lista->prox;
    }

    if(count > lista->linha || coluna >= lista->coluna) {

        return (-1);
    }

    else {

        float **matriz = lista->mat;

        for(i = 0; i < count; i++) {

            matriz[i][coluna] = valores[i];
        }

        return(1);
    }
}