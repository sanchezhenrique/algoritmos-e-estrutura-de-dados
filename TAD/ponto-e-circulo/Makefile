# Compilador C que sera usado.
CC = gcc

# Opcoes de compilacao:
# -std=c99   -> usa o padrao C99
# -Wall      -> habilita avisos importantes
# -Wextra    -> habilita avisos adicionais
# -pedantic  -> cobra maior conformidade com o padrao C
CFLAGS = -std=c99 -Wall -Wextra -pedantic

# Nome do programa final.
PROGRAMA = ponto_circulo

# Regra principal.
# Para gerar o programa, precisamos dos tres arquivos objeto.
$(PROGRAMA): main.o ponto.o circulo.o
	$(CC) main.o ponto.o circulo.o -o $(PROGRAMA)

# Compila apenas o cliente.
# O main depende tambem das interfaces dos dois TADs.
main.o: main.c ponto.h circulo.h
	$(CC) $(CFLAGS) -c main.c

# Compila a implementacao do TAD ponto.
ponto.o: ponto.c ponto.h
	$(CC) $(CFLAGS) -c ponto.c

# Compila a implementacao do TAD circulo.
circulo.o: circulo.c circulo.h
	$(CC) $(CFLAGS) -c circulo.c

# Remove os arquivos produzidos pela compilacao.
clean:
	rm -f *.o $(PROGRAMA)

# Diz ao make que clean nao e o nome de um arquivo.
.PHONY: clean
