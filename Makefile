CC=gcc
FLAGS=-Wall -Wextra

EXE_NAME=representation

# H_FILES=src/project.h src/output/output.h
# H_FILES=$(wildcard src/*/*.h)

# main: main.o $(H_FILES)
# 	$(CC) bin/main.o $(H_FILES) -o $(EXE_NAME)

OUTPUT = ft_putstr.o ft_putstrlen.o ft_strlen.o


all: $(OUTPUT)
	tree bin/
	echo "$(OUTPUT)"

# Binary files
bin:
	mkdir bin
bin/output: bin
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


# Clean logic
fclean: clean_main clean_bin

clean_main:
	$(info Removing $(EXE_NAME))
	rm -f $(EXE_NAME)

clean_bin:
	$(info Removing binary directory)
	rm -rf ./bin
