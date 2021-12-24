#include "project.h"

#define SIZE 8

int	main(void)
{
	t_chess_style style;
	/*char	board[SIZE];
	int	i;

	i = -1;
	while (++i < SIZE)
		board[i] = (i + 3) % SIZE;
	style = STYLE;
	print_board(board, SIZE, style);*/
	style = STYLE;
	ft_n_queens_puzzle(SIZE, style);
}
