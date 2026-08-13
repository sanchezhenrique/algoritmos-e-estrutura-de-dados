# Compilador C que sera usado.
CC = gcc

# Opcoes de compilacao:
# -std=c99   -> usa o padrao C99
# -Wall      -> habilita avisos importantes
# -Wextra    -> habilita avisos adicionais
# -pedantic  -> cobra maior conformidade com o padrao C
CFLAGS = -std=c99 -Wall -Wextra -pedantic

# Nome do programa final.
PROGRAMA = rpg

# Regra principal.
$(PROGRAMA): main.o personagem.o
	$(CC) main.o personagem.o -o $(PROGRAMA)

# Compila apenas o cliente.
main.o: main.c personagem.h
	$(CC) $(CFLAGS) -c main.c

# Compila a implementacao do TAD personagem.
personagem.o: personagem.c personagem.h
	$(CC) $(CFLAGS) -c personagem.c

# Remove os arquivos produzidos pela compilacao.
clean:
	rm -f *.o $(PROGRAMA)

# Diz ao make que clean nao e o nome de um arquivo.
.PHONY: clean
