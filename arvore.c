/*=================================================================================*/
/*                 TRABALHO 2 DE AED II - AVALIACAO DE EXPRESSAO                   */
/* AUTOR: ARTHUR ALEXSANDER MARTINS TEODORO - 0022427             DATA: 25/10/2016 */
/*=================================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "arvore.h"

/*=================================================================================*/
/*                                ESTRUTURA CRIADA                                 */
/*=================================================================================*/
struct arv
{
	int tipoDado;
	char operador;
	float operando;
	struct arv* esq;
	struct arv* dir;
};

/*=================================================================================*/
/*CRIA AROVRE VAZIA - FUNCAO QUE CRIA UMA ARVORE VAZIA                             */
/*IN: VOID                                               OUT: PORNTEIRO PARA ARVORE*/
/*=================================================================================*/
Arv criaArvoreVazia(void)
{
	return NULL;
}

/*=================================================================================*/
/*CRIA ARVORE - FUNCAO QUE CRIA UMA ARVORE DADO SEU VALOR E SEUS FILHOS            */
/*IN: CHAVE, SAE, SAD                                    OUT: PORNTEIRO PARA ARVORE*/
/*=================================================================================*/
Arv criaArvore(char* valor, int tipo, Arv esq, Arv dir)
{
	Arv raiz = (Arv) malloc(sizeof(struct arv));

	/*caso for float ou inteiro*/
	if(tipo == OPERANDO)
	{
		raiz->operando = atof(valor);
		raiz->tipoDado = OPERANDO;
	}
	else
	{
		raiz->operador = valor[0];
		raiz->tipoDado = OPERADOR;
	}
	raiz->esq = esq;
	raiz->dir = dir;

	return raiz;
}

/*=================================================================================*/
/*DESTROI ARVORE - FUNCAO QUE DESALOCA TODA A MEMORIA DA ARVORE                    */
/*IN: NO RAIZ                                                   OUT: PORNTEIRO NULO*/
/*=================================================================================*/
Arv destroiArvore(Arv raiz)
{
	if(raiz != NULL)
	{
		destroiArvore(raiz->esq);
		destroiArvore(raiz->dir);
		free(raiz);
	}
	return NULL;
}

/*=================================================================================*/
/*LINK - FUNCAO QUE LIGA OS FILHOS À UMA RAIZ                                      */
/*IN: NO RAIZ, SAE, SAD                                                   OUT: VOID*/
/*=================================================================================*/
void link(Arv raiz, Arv dir, Arv esq)
{
	if(raiz != NULL)
	{
		raiz->dir = dir;
		raiz->esq = esq;
		return;
	}
	return;
}

/*=================================================================================*/
/*QUANTIDADE NOS ARVORE - FUNCAO QUE RETORNA A QUANTIDADE DE NOS DA ARVORE         */
/*IN: NO RAIZ                                                OUT: QUANTIDADE DE NOS*/
/*=================================================================================*/
int quantidadeNosArvore(Arv raiz)
{
	if(raiz == NULL)
		return 0;
	return 1 + quantidadeNosArvore(raiz->esq) + quantidadeNosArvore(raiz->dir);
}

/*=================================================================================*/
/*CAMINHA POS ORDEM - FUNCAO QUE CAMINHA NA ARVORE EM POS ORDEM                    */
/*IN: NO RAIZ, VETOR DE SAIDA                                             OUT: VOID*/
/*=================================================================================*/
void caminhaPosOrdem(Arv raiz, char* vetor)
{
	if(raiz == NULL)
		return;

	char string[500];

	caminhaPosOrdem(raiz->esq, vetor);
	caminhaPosOrdem(raiz->dir, vetor);
	if(raiz->tipoDado == OPERANDO)
	{
		/*imprime o valor em uma string para esta ser concatenada*/
		sprintf(string, "%f ", raiz->operando);
		strcat(vetor, string);
	}
	else
	{
		sprintf(string, "%c ", raiz->operador);
		strcat(vetor, string);
	}
}

/*=================================================================================*/
/*CAMINHA PRE ORDEM - FUNCAO QUE CAMINHA NA ARVORE EM PRE ORDEM                    */
/*IN: NO RAIZ, VETOR DE SAIDA                                             OUT: VOID*/
/*=================================================================================*/
void caminhaPreOrdem(Arv raiz, char* vetor)
{
	if(raiz == NULL)
		return;

	char string[500];

	if(raiz->tipoDado == OPERANDO)
	{
		/*imprime o valor em uma string para esta ser concatenada*/
		sprintf(string, "%f ", raiz->operando);
		strcat(vetor, string);
	}
	else
	{
		sprintf(string, "%c ", raiz->operador);
		strcat(vetor, string);
	}
	caminhaPreOrdem(raiz->esq, vetor);
	caminhaPreOrdem(raiz->dir, vetor);
}

void caminha(Arv raiz)
{
	if(raiz == NULL)
		return;
	printf("(");
	caminha(raiz->esq);
	if(raiz->tipoDado == OPERANDO)
	{
		//printf("eh operando\n");
		printf("%.2f", raiz->operando);
	}
	else
		printf("%c", raiz->operador);
	caminha(raiz->dir);
	printf(")");
}