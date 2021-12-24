#include "../../project.h"
typedef struct s_chess_style t_chess_style;

void	ft_solve(char board[N], int *solutions, t_chess_style style)
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
				if (possible(board, i, h + 48))
				{
					board[i] = h + 48;
					ft_solve(board, solutions, style);
					board[i] = EMPTY;
				}
				h++;
			}
			return ;
		}
		i++;
	}
	print_board(board, style);
	*solutions = *solutions + 1;
}
