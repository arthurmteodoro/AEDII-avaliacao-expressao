/*=================================================================================*/
/*                 TRABALHO 2 DE AED II - AVALIACAO DE EXPRESSAO                   */
/* AUTOR: ARTHUR ALEXSANDER MARTINS TEODORO - 0022427             DATA: 25/10/2016 */
/*=================================================================================*/

/*=================================================================================*/
/*                                 TIPOS CRIADOS                                   */
/*=================================================================================*/
typedef struct pilhaArv *PilhaArv;

/*=================================================================================*/
/*                                OPERECOES CRIADOS                                */
/*=================================================================================*/
extern PilhaArv criaPilhaArv(void);
extern void inserePilhaArv(PilhaArv pilha, Arv valor);
extern Arv retiraPilhaArv(PilhaArv pilha);
extern int vaziaPilhaArv(PilhaArv pilha);
extern PilhaArv destroiPilhaArv(PilhaArv pilha);