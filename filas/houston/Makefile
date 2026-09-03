all: item.o fila.o houston.o
	gcc item.o fila.o houston.o -o houston -std=c99 -Wall

item.o:
	gcc -c item.c -o item.o

fila.o:
	gcc -c fila.c -o fila.o

houston.o:
	gcc -c houston.c -o houston.o
	 
clean:
	rm *.o houston

run:
	./houston