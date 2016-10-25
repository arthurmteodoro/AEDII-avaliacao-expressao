#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"

int main(void)
{

	Arv raiz = criaArvore("+", criaArvore("5.3",NULL,NULL),criaArvore("5",NULL,NULL));

	caminha(raiz);

	destroiArvore(raiz);

	return 0;
}