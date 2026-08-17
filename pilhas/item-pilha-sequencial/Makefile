# Compilador C que sera usado.
CC = gcc

# Opcoes de compilacao:
# -std=c99   -> usa o padrao C99
# -Wall      -> habilita avisos importantes
# -Wextra    -> habilita avisos adicionais
# -pedantic  -> cobra maior conformidade com o padrao C
CFLAGS = -std=c99 -Wall -Wextra -pedantic

# Nome do programa final.
PROGRAMA = pilhaItens

# Regra principal.
# Para gerar o programa, precisamos dos tres arquivos objeto.
$(PROGRAMA): main.o item.o pilha.o
	$(CC) main.o item.o pilha.o -o $(PROGRAMA)

# Compila apenas o cliente.
# O main depende tambem das interfaces dos dois TADs.
main.o: main.c item.h pilha.h
	$(CC) $(CFLAGS) -c main.c

# Compila a implementacao do TAD item.
item.o: item.c item.h
	$(CC) $(CFLAGS) -c item.c

# Compila a implementacao do TAD pilha.
pilha.o: pilha.c pilha.h
	$(CC) $(CFLAGS) -c pilha.c

# Remove os arquivos produzidos pela compilacao.
clean:
	rm -f *.o $(PROGRAMA)

# Diz ao make que clean nao e o nome de um arquivo.
.PHONY: clean
