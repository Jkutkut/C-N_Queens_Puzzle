#ifndef N_QUEENS_H
#define N_QUEENS_H

#define EMPTY -1

#ifndef N
#define N 8
#endif

int		ft_possible_queen(char board[N], int index, char h);
void	ft_solve(char board[N], int *solutions);
int		ft_ten_queens_puzzle(void);

#endif
