/*=================================================================================*/
/*                 TRABALHO 2 DE AED II - AVALIACAO DE EXPRESSAO                   */
/* AUTOR: ARTHUR ALEXSANDER MARTINS TEODORO - 0022427             DATA: 25/10/2016 */
/*=================================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"

/*=================================================================================*/
/*                                ESTRUTURA CRIADA                                 */
/*=================================================================================*/
struct arv
{
	char valor;
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
Arv criaArvore(char valor, Arv esq, Arv dir)
{
	Arv raiz = (Arv) malloc(sizeof(struct arv));
	raiz->valor = valor;
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