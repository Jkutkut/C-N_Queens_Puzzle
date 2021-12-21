
# Compiler options
CC=gcc
FLAGS=-Wall -Wextra
COMPILE=$(CC) $(FLAGS)


EXE_NAME=representation

H_FILES=src/output/output.h src/project.h  #src/style/chess_style.h

# Style
# STYLE=src/style/classic_chess_style.h

MAIN=src/main.c
OUTPUT_O=ft_putstr.o ft_putstrlen.o ft_strlen.o
OUTPUT=$(wildcard bin/output/*.o)


all: $(MAIN) $(H_FILES) $(STYLE)  $(OUTPUT_O)
	$(info Compiling all into $(EXE_NAME))
	$(COMPILE) $(MAIN) $(H_FILES) $(STYLE) $(OUTPUT) -o $(EXE_NAME)

# Binary files
bin:
	mkdir bin
bin/output: bin
	mkdir bin/output

# General Output
ft_putstr.o: bin/output src/output/ft_putstr.c
	$(COMPILE) -c src/output/ft_putstr.c -o bin/output/ft_putstr.o

ft_putstrlen.o: bin/output src/output/ft_putstrlen.c
	$(COMPILE) -c src/output/ft_putstrlen.c -o bin/output/ft_putstrlen.o

ft_strlen.o: bin/output src/output/ft_strlen.c
	$(COMPILE) -c src/output/ft_strlen.c -o bin/output/ft_strlen.o


# Clean logic
fclean: clean_main clean_bin

clean_main:
	$(info Removing $(EXE_NAME))
	rm -f $(EXE_NAME)

clean_bin:
	$(info Removing binary directory)
	rm -rf ./bin
