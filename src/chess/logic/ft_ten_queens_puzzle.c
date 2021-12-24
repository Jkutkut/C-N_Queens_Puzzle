typedef struct s_chess_style t_chess_style;

int	ft_ten_queens_puzzle(t_chess_style style)
{
	char	board[N];
	int		i;

	i = 0;
	while (i < N)
		board[i++] = EMPTY;
	i = 0;
	ft_solve(board, &i, style);
	return (i);
}
