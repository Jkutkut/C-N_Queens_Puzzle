
# Compiler options
CC=gcc
FLAGS=-Wall -Wextra
COMPILE=$(CC) $(FLAGS)


EXE_NAME=representation

MAIN=src/main.c
OUTPUT=bin/output/ft_putstr.o bin/output/ft_strlen.o bin/output/ft_putstrlen.o
CHESS_LOGIC=bin/chess/logic/ft_possible_queen.o bin/chess/logic/ft_solve.o bin/chess/logic/ft_n_queens_puzzle.o bin/chess/output/print_board.o
STYLE_FILE=src/chess/style/classic_chess_style.h
#STYLE_FILE=src/chess/style/alternative_chess_style.h

all: $(MAIN) binaries bin/atoi/ft_atoi.o  src/chess/style/style.h
	$(info Compiling all into $(EXE_NAME))
	$(COMPILE) $(MAIN) $(OUTPUT) $(CHESS_LOGIC) bin/atoi/ft_atoi.o  -o $(EXE_NAME)

# Binary files
bin:
	$(info Creating bin directory to store all the object files)
	mkdir -p bin
bin/output: bin
	mkdir -p bin/output
bin/chess: bin
	mkdir -p bin/chess
bin/atoi: bin
	mkdir -p bin/atoi

bin/chess/logic: bin/chess
	mkdir bin/chess/logic
bin/chess/output: bin/chess
	mkdir bin/chess/output
binaries: bin/output bin/chess/logic bin/chess/output $(OUTPUT) $(CHESS_LOGIC)

# Atoi
bin/atoi/ft_atoi.o: bin/atoi src/atoi/ft_atoi.c
	$(COMPILE) -c src/atoi/ft_atoi.c -o bin/atoi/ft_atoi.o

# General Output
bin/output/ft_putstr.o: bin/output src/output/ft_putstr.c
	$(COMPILE) -c src/output/ft_putstr.c -o bin/output/ft_putstr.o

bin/output/ft_putstrlen.o: bin/output src/output/ft_putstrlen.c
	$(COMPILE) -c src/output/ft_putstrlen.c -o bin/output/ft_putstrlen.o

bin/output/ft_strlen.o: bin/output src/output/ft_strlen.c
	$(COMPILE) -c src/output/ft_strlen.c -o bin/output/ft_strlen.o

# Chess logic
bin/chess/logic/ft_possible_queen.o: bin/chess/logic src/chess/logic/ft_possible_queen.c
	$(COMPILE) -c src/chess/logic/ft_possible_queen.c -o bin/chess/logic/ft_possible_queen.o
bin/chess/logic/ft_solve.o: bin/chess/logic src/chess/logic/ft_solve.c
	$(COMPILE) -c src/chess/logic/ft_solve.c -o bin/chess/logic/ft_solve.o
bin/chess/logic/ft_n_queens_puzzle.o: bin/chess/logic src/chess/logic/ft_n_queens_puzzle.c
	$(COMPILE) -c src/chess/logic/ft_n_queens_puzzle.c -o bin/chess/logic/ft_n_queens_puzzle.o

# Print_board
bin/chess/output/print_board.o: bin/chess/output src/chess/output/print_board.c
	$(COMPILE) -c src/chess/output/print_board.c -o bin/chess/output/print_board.o

# Style
src/chess/style/style.h:
	$(info Usign the style from $(STYLE_FILE))
	cp $(STYLE_FILE) src/chess/style/style.h

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
