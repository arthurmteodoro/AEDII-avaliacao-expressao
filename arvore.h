/*=================================================================================*/
/*                 TRABALHO 2 DE AED II - AVALIACAO DE EXPRESSAO                   */
/* AUTOR: ARTHUR ALEXSANDER MARTINS TEODORO - 0022427             DATA: 25/10/2016 */
/*=================================================================================*/

/*=================================================================================*/
/*                                 TIPOS CRIADOS                                   */
/*=================================================================================*/
typedef struct arv *Arv;

/*=================================================================================*/
/*                                OPERECOES CRIADOS                                */
/*=================================================================================*/
extern Arv criaArvoreVazia(void);
extern Arv criaArvore(char valor, Arv esq, Arv dir);
extern Arv destroiArvore(Arv raiz);
extern void link(Arv raiz, Arv dir, Arv esq);