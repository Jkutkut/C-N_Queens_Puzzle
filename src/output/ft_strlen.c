int	ft_strlen(char *str)
{
	int l;

	l = 0;
	while (str[l])
		l++;
	return (l);
}
