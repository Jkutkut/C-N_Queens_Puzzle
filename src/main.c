#include "project.h"

void	print_line(char *border, char *fill_even, char *fill_odd)
{
	int	i;
	int	border_size;
	int	fill_even_size;
	int	fill_odd_size;	

	i = 0;
	border_size = ft_strlen(border);
	fill_even_size = ft_strlen(fill_even);
	fill_odd_size = ft_strlen(fill_odd);
	ft_putstrlen(border, border_size);
	while (i < N)
	{
		if (i % 2 == 0)
			ft_putstrlen(fill_even, fill_even_size);
		else
			ft_putstrlen(fill_odd, fill_odd_size);
		ft_putstrlen(border, border_size);
		i++;
	}
	write(1, "\n", 1);
}

void	print_line_piece(char board[N], t_chess_style style, int h)
{
	int	i;

	i = 0;
	ft_putstr(style.v_border);
	while (i < N)
	{
		if ((i + h) % 2 == 0)
		{
			if (board[i] == h)
				ft_putstr(style.white_queen);
			else
				ft_putstr(style.white_fill);
			ft_putstr(style.v_border);
		}
		else
		{
			if (board[i] == h)
				ft_putstr(style.black_queen);
			else
				ft_putstr(style.black_fill);
			ft_putstr(style.v_border);
			
		}
		i++;
	}
	ft_putstrlen("\n", 1);
}


void	print_board(char	board[N], t_chess_style style)
{
	int	i;

	i = 0;
	print_line(style.corner, style.h_border, style.h_border);
	while (i < N)
	{
		if (i % 2 == 0)
		{
			print_line(style.v_border, style.white_fill, style.black_fill);
			print_line_piece(board, style, i);
			print_line(style.v_border, style.white_fill, style.black_fill);
		}
		else
		{
			print_line(style.v_border, style.black_fill, style.white_fill);
			print_line_piece(board, style, i);
			print_line(style.v_border, style.black_fill, style.white_fill);
		}
		print_line(style.corner, style.h_border, style.h_border);
		i++;
	}
	ft_putstrlen("\n", 1);
}

int	main(void)
{
	t_chess_style style;
	char	board[N];
	int	i;

	i = -1;
	while (++i < N)
		board[i] = i;
	style = STYLE;
	print_board(board, style);
}
