#ifndef _UNISTD_H
#include <unistd.h>
#endif

void	ft_putstrlen(char *str, int l)
{
	write(1, str, l);
}
