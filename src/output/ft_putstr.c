#ifndef _UNISTD_H
#include <unistd.h>
#endif

void	ft_putstr(char *str)
{
	int	l;

	l = 0;
	while (str[l])
		l++;
	write(1, str, l);
}
