all:
	gcc -ansi -Wall -o arvore.o -c arvore.c
	gcc -ansi -Wall -o pilha.o -c pilha.c
	gcc -ansi -Wall -o pilhaArv.o -c pilhaArv.c
	gcc -ansi -Wall -o expressao.o -c expressao.c
	gcc -ansi -Wall -o main.out arvore.o pilha.o pilhaArv.o expressao.o main.c