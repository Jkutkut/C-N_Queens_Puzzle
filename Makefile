CC=gcc
FLAGS=-Wall -Wextra

H_FILE=src/project.h

EXE_NAME=representation

main: main.o $(H_FILE)
	$(CC) bin/main.o $(H_FILE) -o $(EXE_NAME)

# Binary files
bin:
	mkdir bin

main.o: bin
	$(CC) -c src/main.c -o bin/main.o

fclean:
	rm $(EXE_NAME)
	rm -rf bin
