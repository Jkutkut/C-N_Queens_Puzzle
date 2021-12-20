#include <unistd.h>
#include <stdio.h>

#define QUEEN "♛"

#define CORNER "┼"
#define CORNER_SIZE 4

#define H_BORDER    "──────"
#define WHITE_QUEEN "  ♛   "
#define BLACK_QUEEN "··♛ ··"
#define WHITE_FILL  "      "
#define BLACK_FILL  "······"

#define V_BORDER "│"

#define N 8

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

void	print_line_piece(int board[N], int h)
{
	char	*fill_even;
	char	*fill_odd;
	int		fill_even_size;

	if (h % 2 == 0)
	{
		fill_even = WHITE
}

void	print_board(int	board[N])
{
	int	i;

	printf("\n");
	print_line(CORNER, H_BORDER, H_BORDER);
	i = 0;
	while (i < N)
	{
		if (i % 2 == 0)
		{
			print_line(V_BORDER, "      ", "······");
			print_line_piece(board, i);
			print_line(V_BORDER, "      ", "······");
		}
		else
		{
			print_line(V_BORDER, "······", "      ");
			print_line_piece(board, i);
			print_line(V_BORDER, "······", "      ");
		}
		print_line(CORNER, H_BORDER, H_BORDER);
		i++;
	}
	printf("\n");
}

int	main(void)
{
	int	board[N];
	int	i;

	i = 0;
	while (i < N)
		board[i++] = 0;
	print_board(board);
}
