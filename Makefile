# Compiler options
CC=gcc
FLAGS=-Wall -Wextra
COMPILE=@$(CC) $(FLAGS)


EXE_NAME=representation

MAIN=src/main.c
OUTPUT=bin/output/ft_putstr.o bin/output/ft_strlen.o bin/output/ft_putstrlen.o
CHESS_LOGIC=bin/chess/logic/ft_possible_queen.o bin/chess/logic/ft_solve.o bin/chess/logic/ft_n_queens_puzzle.o bin/chess/output/print_board.o bin/atoi/ft_atoi.o


all: classic

classic: classic_chess_style.h $(EXE_NAME)
alternative: alternative_chess_style.h $(EXE_NAME)

# Style
%_chess_style.h: src/chess/style/$@
	$(info Usign the style from ./src/chess/style/$@)
	@cp -f src/chess/style/$@ src/chess/style/style.h

# Binary files
$(EXE_NAME): $(MAIN) binaries  src/chess/style/style.h
	$(info Compiling all into $(EXE_NAME))
	$(COMPILE) $(MAIN) $(OUTPUT) $(CHESS_LOGIC) -o $(EXE_NAME)

bin:
	$(info Creating bin directory to store all the object files)
	@echo "bin\n├─chess\n│   ├─logic\n│   └─output\n├─output\n└─atoi"
	@mkdir bin

bin/output: bin
	@mkdir bin/output

bin/chess: bin
	@mkdir bin/chess

bin/atoi: bin
	@mkdir bin/atoi

bin/chess/logic: bin/chess
	@mkdir bin/chess/logic

bin/chess/output: bin/chess
	@mkdir bin/chess/output

binaries: bin/output bin/chess/logic bin/chess/output bin/atoi $(OUTPUT) $(CHESS_LOGIC)
	$(info Code compiled if needed. Object files are:)
	@for f in $(OUTPUT) $(CHESS_LOGIC); do echo "- $$f"; done

bin/%.o:
	@echo "- Compiling $@ -> $%"

# Atoi
bin/atoi/ft_atoi.o: src/atoi/ft_atoi.c
	$(COMPILE) -c src/atoi/ft_atoi.c -o bin/atoi/ft_atoi.o

# General Output
bin/output/ft_putstr.o: src/output/ft_putstr.c
	$(COMPILE) -c src/output/ft_putstr.c -o bin/output/ft_putstr.o

bin/output/ft_putstrlen.o: src/output/ft_putstrlen.c
	$(COMPILE) -c src/output/ft_putstrlen.c -o bin/output/ft_putstrlen.o

bin/output/ft_strlen.o: src/output/ft_strlen.c
	$(COMPILE) -c src/output/ft_strlen.c -o bin/output/ft_strlen.o

# Chess logic
bin/chess/logic/ft_possible_queen.o: src/chess/logic/ft_possible_queen.c
	$(COMPILE) -c src/chess/logic/ft_possible_queen.c -o bin/chess/logic/ft_possible_queen.o

bin/chess/logic/ft_solve.o: src/chess/logic/ft_solve.c
	$(COMPILE) -c src/chess/logic/ft_solve.c -o bin/chess/logic/ft_solve.o

bin/chess/logic/ft_n_queens_puzzle.o: src/chess/logic/ft_n_queens_puzzle.c
	$(COMPILE) -c src/chess/logic/ft_n_queens_puzzle.c -o bin/chess/logic/ft_n_queens_puzzle.o

# Print_board
bin/chess/output/print_board.o: bin/chess/output src/chess/output/print_board.c
	$(COMPILE) -c src/chess/output/print_board.c -o bin/chess/output/print_board.o

# Clean logic
.DELETE_ON_ERROR:
fclean: clean_main clean_bin clean_style
	$(info Project cleaned.)
clean_main:
	$(info Removing $(EXE_NAME))
	@rm -f $(EXE_NAME)

clean_bin:
	$(info Removing binary directory)
	@rm -rf ./bin

clean_style:
	$(info Removing style file)
	@rm -f src/chess/style/style.h
