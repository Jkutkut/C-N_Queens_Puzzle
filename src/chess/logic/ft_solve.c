void	ft_solve(char board[N], int *solutions)
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
					solve(board, solutions);
					board[i] = EMPTY;
				}
				h++;
			}
			return ;
		}
		i++;
	}
	print(board);
	*solutions = *solutions + 1;
}
