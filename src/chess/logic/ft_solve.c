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
				if (ft_possible_queen(board, N, i, h + 48))
				{
					board[i] = h + 48;
					ft_solve(board, N, solutions, style);
					board[i] = EMPTY;
				}
				h++;
			}
			return ;
		}
		i++;
	}
	print_board(board, N, style);
	*solutions = *solutions + 1;
}
