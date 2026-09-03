all: item.o fila_prioridade.o todo.o
	gcc item.o fila_prioridade.o todo.o -o todo -std=c99 -Wall

item.o:
	gcc -c item.c -o item.o

fila_prioridade.o:
	gcc -c fila_prioridade.c -o fila_prioridade.o

todo.o:
	gcc -c todo.c -o todo.o
	 
clean:
	rm *.o todo

run:
	./todo