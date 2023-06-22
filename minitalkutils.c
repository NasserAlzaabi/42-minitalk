#include "minitalk.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int	space(char c)
{
	if (c == '\t' || c == '\n' || c == '\v')
		return (1);
	if (c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	x;
	int	s;

	s = 1;
	i = 0;
	x = 0;
	while (space(str[i]))
		i++;
	if (str[i] == '-' && ++i)
		s = -1;
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		x = x * 10 + (str[i] - 48);
		i++;
	}
	return (x * s);
}
