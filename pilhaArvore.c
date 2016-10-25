/*=================================================================================*/
/*                 TRABALHO 2 DE AED II - AVALIACAO DE EXPRESSAO                   */
/* AUTOR: ARTHUR ALEXSANDER MARTINS TEODORO - 0022427             DATA: 25/10/2016 */
/*=================================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"
#include "pilhaArvore.h"

/*=================================================================================*/
/*                                ESTRUTURA CRIADA                                 */
/*=================================================================================*/
struct pilhaArv
{
	Arv valor;
	struct pilhaArv* prox;
};

/*=================================================================================*/
/*CRIA PILHA - FUNCAO QUE CRIA UMA PILHA VAZIA                                     */
/*IN: VOID                                                OUT: PORNTEIRO PARA PILHA*/
/*=================================================================================*/
PilhaArv criaPilhaArv(void)
{
	return NULL;
}

/*=================================================================================*/
/*INSERE PILHA - FUNCAO QUE INSERE UM VALOR NA PILHA                               */
/*IN: PONTEIRO PARA PILHA E NO                                            OUT: VOID*/
/*=================================================================================*/
void inserePilhaArv(PilhaArv pilha, Arv valor)
{
	PilhaArv aux = (PilhaArv) malloc(sizeof(struct pilhaArv));
	aux->valor = valor;

	/*Caso a pilha estiver vazia*/
	if(pilha == NULL)
	{
		aux->prox = NULL;
		pilha = aux;
		return;
	}

	/*Caso possuir valores ja na pilha*/
	aux->prox = pilha;
	pilha = aux;
	return;
}

/*=================================================================================*/
/*RETIRA PILHA - FUNCAO QUE RETIRA O TOPO DA PILHA                                 */
/*IN: PONTEIRO PARA PILHA                                          OUT: NO RETIRADO*/
/*=================================================================================*/
Arv retiraPilhaArv(PilhaArv pilha)
{
	if(pilha != NULL)
	{
		PilhaArv aux = pilha;
		pilha = aux->prox;
		Arv valor = aux->valor;
		free(aux);
		return valor;
	} 
	return NULL;
}

/*=================================================================================*/
/*VAZIA PILHA - FUNCAO QUE VERIFICA SE A PILHA ESTA VAZIA                          */
/*IN: PONTEIRO PARA PILHA                                             OUT: BOOLEANO*/
/*=================================================================================*/
int vaziaPilhaArv(PilhaArv pilha)
{
	return (pilha == NULL);
}

/*=================================================================================*/
/*DESTROI PILHA - FUNCAO QUE DESTROI A PILHA                                       */
/*IN: PONTEIRO PARA PILHA                                        OUT: PONTEIRO NULO*/
/*=================================================================================*/
PilhaArv destroiPilhaArv(PilhaArv pilha)
{
	while(!vaziaPilhaArv(pilha))
	{
		retiraPilhaArv(pilha);
	}
	return NULL;
}