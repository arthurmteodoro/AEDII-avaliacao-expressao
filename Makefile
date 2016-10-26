all:
	gcc -Wall -o arvore.o -c arvore.c
	gcc -Wall -o pilha.o -c pilha.c
	gcc -Wall -o pilhaArv.o -c pilhaArv.c
	gcc -Wall -o expressao.o -c expressao.c
	gcc -Wall -o main.out arvore.o pilha.o pilhaArv.o expressao.o main.c