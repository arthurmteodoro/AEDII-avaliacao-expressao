/*=================================================================================*/
/*                 TRABALHO 2 DE AED II - AVALIACAO DE EXPRESSAO                   */
/* AUTOR: ARTHUR ALEXSANDER MARTINS TEODORO - 0022427             DATA: 25/10/2016 */
/*=================================================================================*/

/*=================================================================================*/
/*                                      BIBLIOTECAS                                */
/*=================================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

struct nodoPilha
{
	float valor;
	struct nodoPilha *prox;
};

typedef struct nodoPilha *NodoPilha;

struct pilha
{
	int tam;
	NodoPilha inicio;
};

/*==================================================================================*/
/*                                  FUNÇÕES DA PILHA                                */
/*==================================================================================*/

/*==================================================================================*/
/* CRIA PILHA - FUNCAO RESPONSAVEL POR CRIAR A PILHA                                */
/* IN = VOID                                               OUT = PONTEIRO PARA PILHA*/
/*==================================================================================*/
Pilha criaPilha(void)
{
	Pilha stack = (Pilha) malloc(sizeof(struct pilha));
	stack->tam = 0;
	stack->inicio = NULL;
	return stack;
}

/*==================================================================================*/
/* INSERE PILHA - FUNCAO RESPONSAVEL POR INSERIR VALOR NA PILHA                     */
/* IN = VALOR A SER INSERIDO, PILHA A INSERIR                             OUT = VOID*/
/*==================================================================================*/
void inserePilha(Pilha stack, float valor)
{
	NodoPilha novoNodo = (NodoPilha) malloc(sizeof(struct nodoPilha));
	novoNodo->valor = valor;
	if(vaziaPilha(stack))
	{
		novoNodo->prox = NULL;
		stack->inicio = novoNodo;
		stack->tam++;
		return;
	}
	novoNodo->prox = stack->inicio;
	stack->inicio = novoNodo;
	stack->tam++;
	return;
}

/*==================================================================================*/
/* RETIRAR PILHA - FUNCAO RESPONSAVEL POR RETIRAR UM ELEMENTO DA PILHA              */
/* IN = PONTEIRO PARA PILHA                                     OUT = VALOR RETIRADO*/
/*==================================================================================*/
float retirarPilha(Pilha stack)
{
	if(!vaziaPilha(stack))
	{
		NodoPilha retirar = stack->inicio;
		float valor = retirar->valor;
		/*Caso existir somente um elemento da pilha*/
		if(stack->tam == 1)
		{
			free(retirar);
			stack->inicio = NULL;
			stack->tam--;
			return valor;
		}
		stack->inicio = retirar->prox;
		free(retirar);
		stack->tam--;
		return valor;
	}
	return 0;
}

/*==================================================================================*/
/* VAZIA PILHA - FUNCAO PARA VERIFICAR SE A PILHA ESTA VAZIA                        */
/* IN = PONTEIRO PARA PILHA                                OUT = VALOR SE ESTA VAZIA*/
/*==================================================================================*/
int vaziaPilha(Pilha stack)
{
	return (stack->tam == 0);
}

/*==================================================================================*/
/* CONSULTA PILHA - FUNCAO RESPONSAVEL POR RETORNAR O ELEMENTO DO TOPO DA PILHA     */
/* IN = PONTEIRO PARA PILHA                             OUT = VALOR DO TOPO DA PILHA*/
/*==================================================================================*/
float consultaPilha(Pilha stack)
{
	if(!vaziaPilha(stack))
	{
		return (stack->inicio->valor);
	}
	return 0;
}

/*==================================================================================*/
/* DESTROI PILHA - FUNCAO RESPONSAVEL POR DESTROIR A PILHA                          */
/* IN = PONTEIRO PARA PILHA                                               OUT = VOID*/
/*==================================================================================*/
void destroiPilha(Pilha stack)
{
	if(!vaziaPilha(stack))
	{
		while(!vaziaPilha(stack))
		{
			retirarPilha(stack);
		}
	}
}