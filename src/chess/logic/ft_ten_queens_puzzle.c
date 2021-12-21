/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 20:10:13 by jre-gonz          #+#    #+#             */
/*   Updated: 2021/12/20 16:08:44 by jkutkut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define N 8
#define EMPTY ':'

void	print(char board[N])
{
	write(1, board, N);
	write(1, "\n", 1);
}

int	possible(char board[N], int index, char h)
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

void	solve(char board[N], int *solutions)
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
