#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"
#include "pilhaArv.h"
#include "expressao.h"

int main(int argc, char const *argv[])
{

	/*Variaveis usadas*/
	Arv arvore;
	char expressao[1000] = "";
	char caminhamento[2000] = "";
	float resultado;
	FILE* entrada = stdin;
	FILE* saida = stdout;
	/*Flags para dizerem se usara ou nao o teclado, 0 nao usar*/
	int teclado = 1;

	/*============ MANIPULACAO DOS ARQUIVOS ===================*/
	/*Caso nao passar nada por parametro, sera usada entrada e saida padrao - teclado e monitor*/
  if(argc == 2 && !strcmp(argv[1],"-h"))
  {
    printf("Uso do sistema:\n");
    printf("./main.out -i <nome_arquivo_entrada> -o <nome_arquivo_saida>\n");
    printf("As diretivas -i e -o pode ser omitida\n");
    return 1;
  }
	if(argc == 1)
	{
		entrada = stdin;
		saida = stdout;
	}
	else
	{
		/*entrada e saida por aquivos*/
		if(argc == 5)
		{
			entrada = fopen(argv[2], "rt");
			saida = fopen(argv[4], "wt");
			teclado = 0;

			if(entrada == NULL || saida == NULL)
			{
				fprintf(stderr, "Arquivos nao existentes\n");
				return 1;
			}

		}
		else
		{

			if(!strcmp(argv[1], "-i"))
			{
				entrada = fopen(argv[2], "rt");
				teclado = 0;
				
				if(entrada == NULL)
				{
					fprintf(stderr, "Arquivos nao existentes\n");
					return 1;
				}

			}

			if(!strcmp(argv[1], "-o"))
			{
				saida = fopen(argv[2], "wt");
				
				if(saida == NULL)
				{
					fprintf(stderr, "Arquivos nao existentes\n");
					return 1;
				}

			}
		}
	}
	/*============ FIM DA MANIPULACAO DOS ARQUIVOS ===================*/

	/*entrada por teclado e saida por monitor ou entrada teclado e saida arquivo*/
	if(teclado == 1)
	{
		printf("Digite a expressao na notacao polonesa inversa:\n");
		fgets(expressao, 1000, entrada);
		expressao[strlen(expressao)-1] = '\0';

		arvore = geraExpressao(expressao);
		resultado = calculaExpressao(arvore);
		fprintf(saida, "O resultado da expressao eh %f\n", resultado);

		caminhaPreOrdem(arvore, caminhamento);
		fprintf(saida, "A expressao em notacao polonesa eh %s\n", caminhamento);
		strcpy(caminhamento, "");
		caminhaInOrdem(arvore, caminhamento);
		fprintf(saida ,"A expressao em notacao infixa eh %s\n", caminhamento);
		destroiArvore(arvore);
	}

	if(teclado == 0)
	{
		while(fgets(expressao, 1000, entrada) != NULL)
		{
			if(expressao[strlen(expressao)-1] == '\n')
				expressao[strlen(expressao)-1] = '\0';

			fprintf(saida, "Analisando a expressao %s\n", expressao);
			arvore = geraExpressao(expressao);
			resultado = calculaExpressao(arvore);
			fprintf(saida, "O resultado da expressao eh %f\n", resultado);

			caminhaPreOrdem(arvore, caminhamento);
			fprintf(saida, "A expressao em notacao polonesa eh %s\n", caminhamento);
			strcpy(caminhamento, "");
			caminhaInOrdem(arvore, caminhamento);
			fprintf(saida ,"A expressao em notacao infixa eh %s\n\n", caminhamento);
			destroiArvore(arvore);
			strcpy(caminhamento, "");
		}
	}

	return 0;
}