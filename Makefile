
# Compiler options
CC=gcc
FLAGS=-Wall -Wextra
COMPILE=$(CC) $(FLAGS)


EXE_NAME=representation

MAIN=src/main.c
OUTPUT=$(wildcard src/output/*.c)
OUTPUT_O=bin/output/ft_putstr.o bin/output/ft_strlen.o bin/output/ft_putstrlen.o


all: $(MAIN) binaries src/chess/style/style.h
	$(info Compiling all into $(EXE_NAME))
	$(COMPILE) $(MAIN) $(OUTPUT_O) -o $(EXE_NAME)

# Binary files
bin:
	mkdir bin
bin/output: bin
	mkdir bin/output

binaries: bin/output $(OUTPUT_O)

# General Output
bin/output/ft_putstr.o: src/output/ft_putstr.c
	$(COMPILE) -c src/output/ft_putstr.c -o bin/output/ft_putstr.o

bin/output/ft_putstrlen.o: src/output/ft_putstrlen.c
	$(COMPILE) -c src/output/ft_putstrlen.c -o bin/output/ft_putstrlen.o

bin/output/ft_strlen.o: src/output/ft_strlen.c
	$(COMPILE) -c src/output/ft_strlen.c -o bin/output/ft_strlen.o

# Style
src/chess/style/style.h:
	cp src/chess/style/alternative_chess_style.h src/chess/style/style.h

# Clean logic
.DELETE_ON_ERROR:
fclean: clean_main clean_bin clean_style

clean_main:
	$(info Removing $(EXE_NAME))
	rm -f $(EXE_NAME)

clean_bin:
	$(info Removing binary directory)
	rm -rf ./bin

clean_style:
	$(info Removing style file)
	rm -f src/chess/style/style.h
