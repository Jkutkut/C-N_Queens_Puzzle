#ifndef PROJECT_H

#define PROJECT_H

#include <unistd.h>
#include <stdio.h>

#define CORNER "┼"
#define V_BORDER "│"
#define H_BORDER    "──────"

#define WHITE_QUEEN "  ♛   "
#define BLACK_QUEEN "··♛ ··"
#define WHITE_FILL  "      "
#define BLACK_FILL  "······"


#define N 8

typedef struct s_chess_style
{
	char *corner;
	char *v_border;
	char *h_border;
	char *white_queen;
	char *black_queen;
	char *white_fill;
	char *black_fill;
} t_chess_style;


int		ft_strlen(char *str);
void	ft_putstrlen(char *str, int l);
void	ft_putstr(char *str);

#endif
