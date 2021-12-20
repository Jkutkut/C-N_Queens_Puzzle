#include <unistd.h>
#include <stdio.h>

#define QUEEN "♛"
#define N 8

void	print_board(void)
{
	//write(1, QUEEN, 4);
	printf("+------+\n");
	printf("|      |\n");
	printf("|  ♛   |\n");
	printf("|      |\n");
	printf("+------+\n");
	printf("|······|\n");
	printf("|··♛ ··|\n");
	printf("|······|\n");
	printf("+------+\n");

}

int	main(void)
{
	print_board();
	printf("\n");
}
