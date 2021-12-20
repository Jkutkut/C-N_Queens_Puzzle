/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 20:10:13 by jre-gonz          #+#    #+#             */
/*   Updated: 2021/12/11 12:28:46 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#define SIZE 10
#define EMPTY ':'

void	print(char board[SIZE])
{
	write(1, board, SIZE);
	write(1, "\n", 1);
}

int	possible(char board[SIZE], int index, char h)
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

void	solve(char board[SIZE], int *solutions)
{
	int	i;
	int	h;

	i = 0;
	while (i < SIZE)
	{
		if (board[i] == EMPTY)
		{
			h = 0;
			while (h < SIZE)
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
	char	board[SIZE];
	int		i;

	i = 0;
	while (i < SIZE)
		board[i++] = EMPTY;
	i = 0;
	solve(board, &i);
	return (i);
}
