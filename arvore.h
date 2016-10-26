/*=================================================================================*/
/*                 TRABALHO 2 DE AED II - AVALIACAO DE EXPRESSAO                   */
/* AUTOR: ARTHUR ALEXSANDER MARTINS TEODORO - 0022427             DATA: 25/10/2016 */
/*=================================================================================*/

#ifndef _ARVORE_
#define _ARVORE_

/*=================================================================================*/
/*                                 TIPOS CRIADOS                                   */
/*=================================================================================*/
typedef struct arv *Arv;
#define OPERANDO 0
#define OPERADOR 1

/*=================================================================================*/
/*                                OPERECOES CRIADOS                                */
/*=================================================================================*/
extern Arv criaArvoreVazia(void);
extern Arv criaArvore(char* valor, int tipo, Arv esq, Arv dir);
extern Arv destroiArvore(Arv raiz);
extern void link(Arv raiz, Arv dir, Arv esq);
extern int quantidadeNosArvore(Arv raiz);
extern void caminhaPosOrdem(Arv raiz, char* vetor);
extern void caminhaPreOrdem(Arv raiz, char* vetor);
void caminha(Arv raiz);

#endif