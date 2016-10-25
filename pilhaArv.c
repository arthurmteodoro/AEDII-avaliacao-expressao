/*=================================================================================*/
/*                 TRABALHO 2 DE AED II - AVALIACAO DE EXPRESSAO                   */
/* AUTOR: ARTHUR ALEXSANDER MARTINS TEODORO - 0022427             DATA: 25/10/2016 */
/*=================================================================================*/

/*=================================================================================*/
/*                                      BIBLIOTECAS                                */
/*=================================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"
#include "pilhaArv.h"

/*=================================================================================*/
/*                                ESTRUTURA CRIADA                                 */
/*=================================================================================*/
struct nodoPilhaArv
{
	Arv valor;
	struct nodoPilhaArv *prox;
};

typedef struct nodoPilhaArv *NodoPilhaArv;

struct pilhaArv
{
	int tam;
	NodoPilhaArv topo;
};

/*==================================================================================*/
/* CRIA PILHA - FUNCAO RESPONSAVEL POR CRIAR A PILHA                                */
/* IN = VOID                                               OUT = PONTEIRO PARA PILHA*/
/*==================================================================================*/
PilhaArv criaPilhaArv(void)
{
	PilhaArv stack = (PilhaArv) malloc(sizeof(struct pilhaArv));
	stack->tam = 0;
	stack->topo = NULL;
	return stack;
}

/*==================================================================================*/
/* INSERE PILHA - FUNCAO RESPONSAVEL POR INSERIR VALOR NA PILHA                     */
/* IN = ARVORE A SER INSERIDO, PILHA A INSERIR                            OUT = VOID*/
/*==================================================================================*/
void inserePilhaArv(PilhaArv stack, Arv arvore)
{
	NodoPilhaArv novoNodo = (NodoPilhaArv) malloc(sizeof(struct nodoPilhaArv));
	novoNodo->valor = arvore;
	if(vaziaPilhaArv(stack))
	{
		novoNodo->prox = NULL;
		stack->topo = novoNodo;
		stack->tam++;
		return;
	}
	novoNodo->prox = stack->topo;
	stack->topo = novoNodo;
	stack->tam++;
}

/*==================================================================================*/
/* RETIRAR PILHA - FUNCAO RESPONSAVEL POR RETIRAR UM ELEMENTO DA PILHA              */
/* IN = PONTEIRO PARA PILHA                                    OUT = ARVORE RETIRADA*/
/*==================================================================================*/
Arv retiraPilhaArv(PilhaArv stack)
{
	if(!vaziaPilhaArv(stack))
	{
		NodoPilhaArv retirar = stack->topo;
		Arv arvRetirar = retirar->valor;

		if(stack->tam == 1)
		{
			free(retirar);
			stack->topo = NULL;
			stack->tam--;
			return arvRetirar;
		}
		stack->topo = retirar->prox;
		free(retirar);
		stack->tam--;
		return arvRetirar;
	}
	return NULL;
}

/*==================================================================================*/
/* VAZIA PILHA - FUNCAO PARA VERIFICAR SE A PILHA ESTA VAZIA                        */
/* IN = PONTEIRO PARA PILHA                                OUT = VALOR SE ESTA VAZIA*/
/*==================================================================================*/
int vaziaPilhaArv(PilhaArv stack)
{
	return (stack->tam == 0);
}

/*==================================================================================*/
/* CONSULTA PILHA - FUNCAO RESPONSAVEL POR RETORNAR O ELEMENTO DO TOPO DA PILHA     */
/* IN = PONTEIRO PARA PILHA                            OUT = ARVORE DO TOPO DA PILHA*/
/*==================================================================================*/
Arv consultaPilhaArv(PilhaArv stack)
{
	if(!vaziaPilhaArv(stack))
	{
		return stack->topo->valor;
	}
	return NULL;
}

/*==================================================================================*/
/* DESTROI PILHA - FUNCAO RESPONSAVEL POR DESTROIR A PILHA                          */
/* IN = PONTEIRO PARA PILHA                                               OUT = VOID*/
/*==================================================================================*/
void destroiPilhaArv(PilhaArv stack)
{
	while(!vaziaPilhaArv(stack))
	{
		retiraPilhaArv(stack);
	}
	stack = NULL;
}