# Compiler options
CC=gcc
FLAGS=-Wall -Wextra
COMPILE=@$(CC) $(FLAGS)


EXE_NAME=representation

MAIN=bin/main.o
OUTPUT=bin/output/ft_putstr.o bin/output/ft_strlen.o bin/output/ft_putstrlen.o
CHESS_LOGIC=bin/chess/logic/ft_possible_queen.o bin/chess/logic/ft_solve.o bin/chess/logic/ft_n_queens_puzzle.o bin/chess/output/print_board.o bin/atoi/ft_atoi.o


all: classic

classic: classic_chess_style.h $(EXE_NAME)
classic_centered: classic_centered_chess_style.h $(EXE_NAME)
alternative: alternative_chess_style.h $(EXE_NAME)
#YYYY: YYYY_chess_style.h $(EXE_NAME)

# Style
%_chess_style.h: src/chess/style/$@
	$(info Usign the style from ./src/chess/style/$@)
	@cp -f src/chess/style/$@ src/chess/style/style.h

# Binary files
$(EXE_NAME): $(MAIN) binaries  src/chess/style/style.h
	$(info Compiling all into $(EXE_NAME))
	$(COMPILE) $(MAIN) $(OUTPUT) $(CHESS_LOGIC) -o $(EXE_NAME)

binaries: $(OUTPUT) $(CHESS_LOGIC)
	$(info Object files ready)

bin:
	$(info Creating bin directory to store all object files)
	@mkdir bin

bin/%.o: src/%.c bin
	@if [ ! -d $(dir $@) ]; then echo "Creating $(dir $@)"; mkdir -p $(dir $@); fi
	@echo "- Compiling $< -> $@"
	@$(COMPILE) -c $< -o $@


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
