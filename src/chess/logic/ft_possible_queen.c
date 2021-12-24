#include "n_queens.h"
int	ft_possible_queen(char *board, int N, int index, char h)
{
	int	i;

	i = 0;
	while (i < index && i < N)
	{
		if (board[i] == h)
			return (0);
		if (board[i] + (index - i) == h || board[i] - (index - i) == h)
			return (0);
		i++;
	}
	return (1);
}
