#include "n_queens.h"

int	ft_n_queens_puzzle(int N, t_chess_style style)
{
	char	board[N];
	int		i;

	i = 0;
	while (i < N)
		board[i++] = EMPTY;
	i = 0;
	ft_solve(board, N, &i, style);
	return (i);
}
