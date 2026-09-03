all: item.o fila.o  pilha.o ping.o
	gcc item.o fila.o pilha.o ping.o -o ping -std=c99 -Wall

item.o:
	gcc -c item.c -o item.o

fila.o:
	gcc -c fila.c -o fila.o

pila.o:
	gcc -c pilha.c -o pilha.o

ping.o:
	gcc -c ping.c -o ping.o
	 
clean:
	rm *.o ping

run:
	./ping