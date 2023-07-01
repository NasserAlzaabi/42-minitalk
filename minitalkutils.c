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
	int n;

	s = 1;
	i = 0;
	x = 0;
	while (space(str[i]))
		i++; 
	while (str[i] == '-' && ++i)
		s *= -1;
	while (str[i] == '+')
		i++;
	n = i;
	while (str[i]){
		if(!(str[i] >= '0' && str[i] <= '9'))
			return(-1);
		i++;
	}
	while (str[n] >= '0' && str[n] <= '9')
	{
		x = x * 10 + (str[n] - 48);
		n++;
	}
	return (x * s);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr(int nb)
{
	int	count;

	count = 0;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	else if (nb < 0)
	{
		count += ft_putchar('-');
		nb = -nb;
		count += ft_putnbr(nb);
	}
	else if (nb <= 9)
	{
		count += ft_putchar(nb + '0');
	}
	else
	{
		count += ft_putnbr(nb / 10);
		count += ft_putchar((nb % 10) + 48);
	}
	return (count);
}