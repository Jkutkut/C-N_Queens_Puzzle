#include "project.h"

#define SIZE 8

int	main(int argc, char **argv)
{
	t_chess_style style;
	int s;

	s = SIZE;
	style = STYLE;
	if (argc == 2)
		s = ft_atoi(argv[1]);
	if (s < 4)
	{
		ft_putstr("The minimum size is 4\n");
		return (1);
	}
	ft_n_queens_puzzle(s, style);
	return (0);
}
