#include "project.h"

int	main(void)
{
	t_chess_style style;
	char	board[N];
	int	i;

	i = -1;
	while (++i < N)
		board[i] = (i + 3) % N;
	style = STYLE;
	print_board(board, N, style);
}
