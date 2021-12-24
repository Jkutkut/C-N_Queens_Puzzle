#include "n_queens.h"

void	ft_solve(char *board, int N, int *solutions, t_chess_style style)
{
	int	i;
	int	h;

	i = 0;
	while (i < N)
	{
		if (board[i] == EMPTY)
		{
			h = 0;
			while (h < N)
			{
				if (ft_possible_queen(board, N, i, h))
				{
					board[i] = h;
					ft_solve(board, N, solutions, style);
					board[i] = EMPTY;
				}
				h++;
			}
			return ;
		}
		i++;
	}
	*solutions = *solutions + 1;
	print_board(board, N, style);
}
