int	ft_ten_queens_puzzle(void)
{
	char	board[N];
	int		i;

	i = 0;
	while (i < N)
		board[i++] = EMPTY;
	i = 0;
	solve(board, &i);
	return (i);
}
