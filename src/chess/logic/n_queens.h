#ifndef N_QUEENS_H
#define N_QUEENS_H

#define EMPTY -1

typedef struct s_chess_style t_chess_style;

int		ft_possible_queen(char *board, int N, int index, char h);
void	ft_solve(char *board, int N, int *solutions);
int		ft_ten_queens_puzzle(int N, t_chess_style);

#endif
