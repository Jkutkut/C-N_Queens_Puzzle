#include "project.h"

int	ft_strlen(char *str)
{
	int l;

	l = 0;
	while (str[l])
		l++;
	return (l);
}

void	ft_putstr(char *str, int l)
{
	write(1, str, l);
}

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
	ft_putstr(border, border_size);
	while (i < N)
	{
		if (i % 2 == 0)
			ft_putstr(fill_even, fill_even_size);
		else
			ft_putstr(fill_odd, fill_odd_size);
		ft_putstr(border, border_size);
		i++;
	}
	write(1, "\n", 1);
}

/*void	print_line_piece(int board[N], int h)
{
	char	*fill_even;
	char	*fill_odd;
	int		fill_even_size;

	if (h % 2 == 0)
	{
		fill_even = WHITE
}
*/

void	print_board(int	board[N], t_chess_style style)
{
	int	i;

	i = 0;
	print_line(style.corner, style.h_border, style.h_border);
	while (i < N)
	{
		if (i % 2 == 0)
		{
			print_line(style.v_border, style.white_fill, style.black_fill);
			print_line(style.v_border, style.white_queen, style.black_queen);
			print_line(style.v_border, style.white_fill, style.black_fill);
		}
		else
		{
			print_line(style.v_border, style.black_fill, style.white_fill);
			print_line(style.v_border, style.black_queen, style.white_queen);
			print_line(style.v_border, style.black_fill, style.white_fill);
		}
		print_line(style.corner, style.h_border, style.h_border);
		i++;
	}
	ft_putstr("\n", 1);
}

int	main(void)
{
	t_chess_style style;
	int	board[N];
	int	i;

	i = 0;
	while (i < N)
		board[i++] = 0;
	style = CLASSIC_STYLE;
	print_board(board, style);
}
