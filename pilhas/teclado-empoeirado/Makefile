all: item.o Pilha.o teclado.o main.o
	gcc item.o Pilha.o teclado.o main.o -o teclado_app -std=c99 -Wall

item.o:
	gcc -c item.c -o item.o -std=c99 -Wall

Pilha.o:
	gcc -c Pilha.c -o Pilha.o -std=c99 -Wall

teclado.o:
	gcc -c teclado.c -o teclado.o -std=c99 -Wall

main.o:
	gcc -c main.c -o main.o -std=c99 -Wall
	 
clean:
	rm *.o teclado_app

run:
	./teclado_app
