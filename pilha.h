/*=================================================================================*/
/*                 TRABALHO 2 DE AED II - AVALIACAO DE EXPRESSAO                   */
/* AUTOR: ARTHUR ALEXSANDER MARTINS TEODORO - 0022427             DATA: 25/10/2016 */
/*=================================================================================*/

#ifndef PILHA
#define PILHA

typedef struct pilha *Pilha;

/*==================================================================================*/
/*                               OPERACOES CRIADAS                                  */
/*==================================================================================*/
extern Pilha criaPilha(void);
extern void inserePilha(Pilha stack, float valor);
extern float retirarPilha(Pilha stack);
extern int vaziaPilha(Pilha stack);
extern float consultaPilha(Pilha stack);
extern void destroiPilha(Pilha stack);

#endif