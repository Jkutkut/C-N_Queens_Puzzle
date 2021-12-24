#ifndef N_QUEENS_H
#define N_QUEENS_H

#define EMPTY -1

// typedef struct s_chess_style {} t_chess_style;
#include "../style/chess_style.h"

int		ft_possible_queen(char *board, int N, int index, char h);
void	ft_solve(char *board, int N, int *solutions, t_chess_style style);
int		ft_n_queens_puzzle(int N, t_chess_style);

// Print board
void	print_board(char *board, int N, t_chess_style style);

#endif
