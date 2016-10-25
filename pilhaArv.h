/*=================================================================================*/
/*                 TRABALHO 2 DE AED II - AVALIACAO DE EXPRESSAO                   */
/* AUTOR: ARTHUR ALEXSANDER MARTINS TEODORO - 0022427             DATA: 25/10/2016 */
/*=================================================================================*/

#ifndef _PILHA_ARVORE_
#define _PILHA_ARVORE_

/*=================================================================================*/
/*                                 TIPOS CRIADOS                                   */
/*=================================================================================*/
typedef struct pilhaArv *PilhaArv;

/*==================================================================================*/
/*                               OPERACOES CRIADAS                                  */
/*==================================================================================*/
extern PilhaArv criaPilhaArv(void);
extern void inserePilhaArv(PilhaArv stack, Arv arvore);
extern Arv retiraPilhaArv(PilhaArv stack);
extern int vaziaPilhaArv(PilhaArv stack);
extern Arv consultaPilhaArv(PilhaArv stack);
extern void destroiPilhaArv(PilhaArv stack);

#endif