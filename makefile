compila:
		gcc musicas.c -c -g
		gcc pilha.c -c -g
		gcc fila.c -c -g
		gcc -g spotyfom.c musicas.o pilha.o fila.o -o exec
		./exec
clear:
		rm musicas.o
		rm fila.o
		rm pilha.o
		rm exec