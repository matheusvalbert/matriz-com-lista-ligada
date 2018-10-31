#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "matriz.h"

int main () {

	M *lista = NULL;

	char opcaoMenu[3];

	do {

	scanf("%s", opcaoMenu);

	if (strcmp(opcaoMenu, "cm") == 0 || strcmp(opcaoMenu, "CM") == 0) {
		
		char nome[10];
		int linha, coluna, controle;

		scanf("%s", nome);
		scanf("%i %i", &linha, &coluna);

		if (linha > 0 && linha < 51 && coluna > 0 && coluna < 51){

			controle = adicionarMatriz(&lista, nome, linha, coluna);

			if(controle == 1) {

				printf("OK\n");
			}

			else{

				printf("ERRO\n");
			}
		}

		else {

			printf("ERRO\n");
		}

	}

	if (strcmp(opcaoMenu, "dm") == 0 || strcmp(opcaoMenu, "DM") == 0) {

		int resp = 0;
		char nome[10];
		scanf("%s", nome);
		resp = destruir(&lista, nome);

		if(resp == 1)
			printf("OK\n");
		else
			printf("ERRO\n");
	}

	if (strcmp(opcaoMenu, "im") == 0 || strcmp(opcaoMenu, "IM") == 0) {

		char nome[10];
		int resp = 0;

		scanf("%s", nome);

		resp = imprimir(lista, nome);

		if(resp == -1)
			printf("ERRO\n");
	}

	if (strcmp(opcaoMenu, "ae") == 0 || strcmp(opcaoMenu, "AE") == 0) {

		char nome[10];
		int linha, coluna, resposta = 0;
		float valor;

		scanf("%s", nome);
		scanf("%i %i %f", &linha, &coluna, &valor);

		resposta = atribuirElemento(&lista, nome, linha, coluna, valor);

		if(resposta == -1)
			printf("ERRO\n");
		if(resposta == 1)
			printf("OK\n");
	}

	if (strcmp(opcaoMenu, "al") == 0 || strcmp(opcaoMenu, "AL") == 0) {

	float vetor[50];
	int numero, count = 0, i, linha, resp = 0;
	char proxChar, nome[10];

	for(i = 0; i < 50; i++)
		vetor[i] = 0;

	scanf("%s", nome);
	scanf("%i", &linha);

	while(scanf("%f%c", &vetor[count], &proxChar) == 2) {

		count++;

        if(proxChar == '#') 
        	break;
	}

	resp = atribuirLinha(&lista, nome, linha, vetor, count);

	if(resp == -1)
		printf("ERRO\n");
	if(resp == 1)
		printf("OK\n");
	}

	if (strcmp(opcaoMenu, "ac") == 0 || strcmp(opcaoMenu, "AC") == 0) {

	float vetor[50];
	int numero, count = 0, i, coluna, resp = 0;
	char proxChar, nome[10];

	for(i = 0; i < 50; i++)
		vetor[i] = 0;

	scanf("%s", nome);
	scanf("%i", &coluna);

	while(scanf("%f%c", &vetor[count], &proxChar) == 2) {

		count++;

        if(proxChar == '#') 
        	break; 
	}

	resp = atribuirColuna(&lista, nome, coluna, vetor, count);

	if(resp == -1)
		printf("ERRO\n");
	if(resp == 1)
		printf("OK\n");
	}

	if (strcmp(opcaoMenu, "tm") == 0 || strcmp(opcaoMenu, "TM") == 0) {

		char nomeMatriz[10], nomeNovo[10];
		int resp = 0;

		scanf("%s", nomeMatriz);
		scanf("%s", nomeNovo);

		resp = transporMatriz(&lista, nomeMatriz, nomeNovo);

		if(resp == -1)
			printf("ERRO\n");
		else
			imprimir(lista, nomeNovo);
	}

	if (strcmp(opcaoMenu, "sm") == 0 || strcmp(opcaoMenu, "SM") == 0) {

		char nome1[10], nome2[10], nomeNovo[10];

		scanf("%s", nome1);
		scanf("%s", nome2);
		scanf("%s", nomeNovo);
		int resp;

		resp = somarMatriz(&lista, nome1, nome2, nomeNovo);

		if(resp == -1)
			printf("ERRO\n");
		else
			imprimir(lista, nomeNovo);
	}

	if (strcmp(opcaoMenu, "dv") == 0 || strcmp(opcaoMenu, "DV") == 0) {

	char nome1[10], nome2[10], nomeNovo[10];

	scanf("%s", nome1);
	scanf("%s", nome2);
	scanf("%s", nomeNovo);
	int resp;

	resp = dividirMatriz(&lista, nome1, nome2, nomeNovo);

	if(resp == -1)
		printf("ERRO\n");
	else
		imprimir(lista, nomeNovo);
	}

	if (strcmp(opcaoMenu, "mm") == 0 || strcmp(opcaoMenu, "MM") == 0) {

	char nome1[10], nome2[10], nomeNovo[10];

	scanf("%s", nome1);
	scanf("%s", nome2);
	scanf("%s", nomeNovo);
	int resp;

	resp = multiplicar1(&lista, nome1, nome2, nomeNovo);

	if(resp == -1)
		printf("ERRO\n");
	else
		imprimir(lista, nomeNovo);
	}

	if (strcmp(opcaoMenu, "me") == 0 || strcmp(opcaoMenu, "ME") == 0) {

	char nome1[10], nome2[10], nomeNovo[10];

	scanf("%s", nome1);
	scanf("%s", nome2);
	scanf("%s", nomeNovo);
	int resp;

	resp = multiplicar2(&lista, nome1, nome2, nomeNovo);

	if(resp == -1)
		printf("ERRO\n");
	else
		imprimir(lista, nomeNovo);
	}

}while(strcmp(opcaoMenu, "fe") != 0 && strcmp(opcaoMenu, "FE") != 0);

	free(lista);
	return 0;
}