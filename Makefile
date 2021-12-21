CC=gcc
FLAGS=-Wall -Wextra

# H_FILES=src/project.h src/output/output.h
H_FILES=$(wildcard src/*/*.h)

EXE_NAME=representation

main: main.o $(H_FILES)
	$(CC) bin/main.o $(H_FILES) -o $(EXE_NAME)

# Binary files
bin:
	mkdir bin
bin/output:
	mkdir bin/output

main.o: bin src/main.c
	$(CC) -c src/main.c -o bin/main.o

# General Output
ft_putstr.o: bin/output src/output/ft_putstr.c
	$(CC) -c src/output/ft_putstr.c -o bin/output/ft_putstr.o

ft_putstrlen.o: bin/output src/output/ft_putstrlen.c
	$(CC) -c src/output/ft_putstrlen.c -o bin/output/ft_putstrlen.o

ft_strlen.o: bin/output src/output/ft_strlen.c
	$(CC) -c src/output/ft_strlen.c -o bin/output/ft_strlen.o




fclean:
	rm $(EXE_NAME)
	rm -rf bin
