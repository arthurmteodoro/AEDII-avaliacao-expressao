/*=================================================================================*/
/*                 TRABALHO 2 DE AED II - AVALIACAO DE EXPRESSAO                   */
/* AUTOR: ARTHUR ALEXSANDER MARTINS TEODORO - 0022427             DATA: 26/10/2016 */
/*=================================================================================*/

/*=================================================================================*/
/*                                      BIBLIOTECAS                                */
/*=================================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "arvore.h"
#include "pilhaArv.h"
#include "pilha.h"

/*=================================================================================*/
/*GERA ARVORE - FUNCAO RESPONSAVEL POR GERAR A ARVORE                              */
/*IN: EXPRESSAO                                          OUT: PORNTEIRO PARA ARVORE*/
/*=================================================================================*/
Arv geraArvore(char* expressao)
{
	if(expressao == NULL)
		return NULL;

	/*Declaracao das variaveis usadas*/
	PilhaArv stack = criaPilhaArv();
	char* token;

	token = strtok(expressao, " ");

	while(token != NULL)
	{

		/*Se nao for operando*/
		if(strcmp(token, "+") && strcmp(token, "-") && strcmp(token, "*") && strcmp(token, "/"))
		{
			inserePilhaArv(stack, criaArvore(token, OPERANDO, NULL, NULL));
		}
		else
		{
			Arv dir = retiraPilhaArv(stack);
			Arv esq = retiraPilhaArv(stack);

			inserePilhaArv(stack, criaArvore(token, OPERADOR, esq, dir));
		}
		token = strtok(NULL, " ");
	}

	Arv raiz = retiraPilhaArv(stack);
	destroiPilhaArv(stack);

	return raiz;
}
/*=================================================================================*/
/*CALCULA EXPRESSAO - FUNCAO RESPONSAVEL POR CALCULAR O VALOR DA EXPRESSAO         */
/*IN: ARVORE DE EXPRESSAO                                      OUT: VALOR CALCULADO*/
/*=================================================================================*/
float calculaExpressao(Arv arvore)
{
	if(arvore == NULL)
		return -123456789;

	Pilha stack = criaPilha();
	char* token;
	char expressao[1000] = "";

	caminhaPosOrdem(arvore, expressao);

	token = strtok(expressao, " ");

	while(token != NULL)
	{

		/*Se nao for operando*/
		if(strcmp(token, "+") && strcmp(token, "-") && strcmp(token, "*") && strcmp(token, "/"))
		{
			inserePilha(stack, atof(token));;
		}
		else
		{
			float num2 = retirarPilha(stack);
			float num1 = retirarPilha(stack);

			if(!strcmp(token, "+"))
				inserePilha(stack, num1+num2);

			if(!strcmp(token, "-"))
				inserePilha(stack, num1-num2);

			if(!strcmp(token, "*"))
				inserePilha(stack, num1*num2);

			if(!strcmp(token, "/"))
				inserePilha(stack, num1/num2);
		}

		token = strtok(NULL, " ");
	}

	float resultado = retirarPilha(stack);
	destroiPilha(stack);
	return resultado;
}

