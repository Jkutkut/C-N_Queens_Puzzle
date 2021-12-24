#define N
int	ft_possible_queen(char board[N], int index, char h)
{
	int	i;

	i = 0;
	while (i < index)
	{
		if (board[i] == h)
			return (0);
		if (board[i] + (index - i) == h || board[i] - (index - i) == h)
			return (0);
		i++;
	}
	return (1);
}
