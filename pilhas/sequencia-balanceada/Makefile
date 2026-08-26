all: item.o Pilha.o balanceada.o main.o
	gcc item.o Pilha.o balanceada.o main.o -o balanceada

item.o:
	gcc -c item.c -o item.o -std=c99 -Wall

Pilha.o:
	gcc -c Pilha.c -o Pilha.o -std=c99 -Wall
 
balanceada.o:
	gcc -c balanceada.c -o balanceada.o -std=c99 -Wall

main.o:
	gcc -c main.c -o main.o -std=c99 -Wall
	 
clean:
	rm *.o balanceada

run:
	./balanceada
