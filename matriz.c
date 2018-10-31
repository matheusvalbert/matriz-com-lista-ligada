#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matriz.h"

struct matriz {

    char nome[10];
    int linha, coluna;
    M *prox, *mat;
};

int transporMatriz (M **plista, char nomeMatriz[], char nomeNovo[]) {

    M *lista = *plista, *lista1 = *plista;

    int flag = 0, flag1 = 0;

    while (lista != NULL) {

        if(strcmp(lista->nome, nomeMatriz) == 0){

            flag = 1;
            break;
        }
    lista = lista->prox;
    }

    while (lista1 != NULL) {

        if(strcmp(lista1->nome, nomeNovo) == 0){

            flag1 = 1;
            break;
        }
        lista1 = lista1->prox;
    }

    if(flag == 0 || flag1 == 1)
        return(-1);

    else {
        int linha = lista->linha, coluna = lista->coluna, i, j;
        adicionarMatriz(plista, nomeNovo, coluna, linha);

        M *lista1 = *plista;

        while (lista1 != NULL) {

        if(strcmp(lista1->nome, nomeNovo) == 0){
            break;
            }
        lista1 = lista1->prox;
        }

        float **matriz = lista->mat, **matriz1 = lista1->mat;

        for (i = 0; i < linha; ++i) {

            for (j = 0; j < coluna; ++j) {

                matriz1[j][i] = matriz[i][j];
            }
        }
    }
}

int somarMatriz(M **plista, char nomeMat1[], char nomeMat2[], char nomeResult[]) {

    M *lista = *plista, *lista1 = *plista, *lista2 = *plista;

    int flag = 0, flag1 = 0, flag2 = 0, linha, coluna, linha1, coluna1;

    while (lista != NULL) {

        if(strcmp(lista->nome, nomeMat1) == 0){

            flag = 1;
            break;
        }
    lista = lista->prox;
    }

    while (lista1 != NULL) {

        if(strcmp(lista1->nome, nomeMat2) == 0){

            flag1 = 1;
            break;
        }
        lista1 = lista1->prox;
    }

    while (lista2 != NULL) {

    if(strcmp(lista2->nome, nomeResult) == 0){

        flag2 = 1;
        break;
        }
    lista2 = lista2->prox;
    }

    if(flag == 0 || flag1 == 0 || flag2 == 1)
        return(-1);

    else{
        
        linha = lista->linha;
        coluna = lista->coluna;
        linha1 = lista1->linha;
        coluna1 = lista1->coluna;

        if(linha != linha1 || coluna != coluna1)
            return(-1);

        adicionarMatriz(plista, nomeResult, linha, coluna);

        M *lista3 = *plista;
        int i, j;

        while (lista3 != NULL) {

        if(strcmp(lista3->nome, nomeResult) == 0){
            break;
            }
        lista3 = lista3->prox;
        }

        float **matriz = lista->mat, **matriz1 = lista1->mat, **matriz3 = lista3->mat;

        for (i = 0; i < linha; ++i) {

            for (j = 0; j < coluna; ++j) {

                matriz3[i][j] = matriz[i][j] + matriz1[i][j];
            }
        }

        return(1);
    }
}

int dividirMatriz(M **plista, char nomeMat1[], char nomeMat2[], char nomeResult[]) {

        M *lista = *plista, *lista1 = *plista, *lista2 = *plista;

    int flag = 0, flag1 = 0, flag2 = 0, linha, coluna, linha1, coluna1;

    while (lista != NULL) {

        if(strcmp(lista->nome, nomeMat1) == 0){

            flag = 1;
            break;
        }
    lista = lista->prox;
    }

    while (lista1 != NULL) {

        if(strcmp(lista1->nome, nomeMat2) == 0){

            flag1 = 1;
            break;
        }
        lista1 = lista1->prox;
    }

    while (lista2 != NULL) {

    if(strcmp(lista2->nome, nomeResult) == 0){

        flag2 = 1;
        break;
        }
    lista2 = lista2->prox;
    }

    if(flag == 0 || flag1 == 0 || flag2 == 1)
        return(-1);

    else {
        
        linha = lista->linha;
        coluna = lista->coluna;
        linha1 = lista1->linha;
        coluna1 = lista1->coluna;

        if(linha != linha1 || coluna != coluna1)
            return (-1);

        adicionarMatriz(plista, nomeResult, linha, coluna);

        M *lista3 = *plista;
        int i, j;

        while (lista3 != NULL) {

        if(strcmp(lista3->nome, nomeResult) == 0){
            break;
            }
        lista3 = lista3->prox;
        }

        float **matriz = lista->mat, **matriz1 = lista1->mat, **matriz3 = lista3->mat;

        for(i = 0; i < linha; i++) {

            for(j = 0; j <coluna; j++) {

                if(matriz[i][j] == 0 || matriz1[i][j] == 0)
                    return(-1);
            }
        }

        for (i = 0; i < linha; ++i) {

            for (j = 0; j < coluna; ++j) {

                matriz3[i][j] = matriz[i][j] / matriz1[i][j];
            }
        }

        return(1);
    }
}

int multiplicar1(M **plista, char nomeMat1[], char nomeMat2[], char nomeResult[]) {

    M *lista = *plista, *lista1 = *plista, *lista2 = *plista;

    int flag = 0, flag1 = 0, flag2 = 0, linha, coluna, linha1, coluna1;

    while (lista != NULL) {

        if(strcmp(lista->nome, nomeMat1) == 0){

            flag = 1;
            break;
        }
    lista = lista->prox;
    }

    while (lista1 != NULL) {

        if(strcmp(lista1->nome, nomeMat2) == 0){

            flag1 = 1;
            break;
        }
        lista1 = lista1->prox;
    }

    while (lista2 != NULL) {

    if(strcmp(lista2->nome, nomeResult) == 0){

        flag2 = 1;
        break;
        }
    lista2 = lista2->prox;
    }

    if(flag == 0 || flag1 == 0 || flag2 == 1)
        return(-1);

    else{
        
        linha = lista->linha;
        coluna = lista->coluna;
        linha1 = lista1->linha;
        coluna1 = lista1->coluna;

        if(linha != coluna1 || coluna !=  linha1)
            return(-1);

        adicionarMatriz(plista, nomeResult, linha, coluna);

        M *lista3 = *plista;
        int i, j;

        while (lista3 != NULL) {

        if(strcmp(lista3->nome, nomeResult) == 0){
            break;
            }
        lista3 = lista3->prox;
        }

        float **matriz = lista->mat, **matriz1 = lista1->mat, **matriz3 = lista3->mat;

        for (i = 0; i < linha; ++i) {

            for (j = 0; j < coluna; ++j) {

                matriz3[i][j] = matriz[i][j] * matriz1[j][i];
            }
        }

        return(1);
    }
}

int multiplicar2(M **plista, char nomeMat1[], char nomeMat2[], char nomeResult[]) {

    M *lista = *plista, *lista1 = *plista, *lista2 = *plista;

    int flag = 0, flag1 = 0, flag2 = 0, linha, coluna, linha1, coluna1;

    while (lista != NULL) {

        if(strcmp(lista->nome, nomeMat1) == 0){

            flag = 1;
            break;
        }
    lista = lista->prox;
    }

    while (lista1 != NULL) {

        if(strcmp(lista1->nome, nomeMat2) == 0){

            flag1 = 1;
            break;
        }
        lista1 = lista1->prox;
    }

    while (lista2 != NULL) {

    if(strcmp(lista2->nome, nomeResult) == 0){

        flag2 = 1;
        break;
        }
    lista2 = lista2->prox;
    }

    if(flag == 0 || flag1 == 0 || flag2 == 1)
        return(-1);

    else{
        
        linha = lista->linha;
        coluna = lista->coluna;
        linha1 = lista1->linha;
        coluna1 = lista1->coluna;

        if(linha != linha1 || coluna !=  coluna1)
            return(-1);

        adicionarMatriz(plista, nomeResult, linha, coluna);

        M *lista3 = *plista;
        int i, j;

        while (lista3 != NULL) {

        if(strcmp(lista3->nome, nomeResult) == 0){
            break;
            }
        lista3 = lista3->prox;
        }

        float **matriz = lista->mat, **matriz1 = lista1->mat, **matriz3 = lista3->mat;

        for (i = 0; i < linha; ++i) {

            for (j = 0; j < coluna; ++j) {

                matriz3[i][j] = matriz[i][j] * matriz1[i][j];
            }
        }

        return(1);
    }
}