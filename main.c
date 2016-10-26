#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"
#include "pilhaArv.h"
#include "expressao.h"

int main(void)
{

	char entrada[80] = "5 1 2 + 4 * + 3 -";

	Arv raiz = geraArvore(entrada);

	char isso[300] = "";

	caminhaPreOrdem(raiz, isso);
	printf("%s\n", isso);

	caminha(raiz);
	printf("\n");

	float resultado = calculaExpressao(raiz);
	printf("O resultado eh %f\n", resultado);

	destroiArvore(raiz);

	return 0;
}