#include "minitalk.h"

//atoi

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int	count(long n)
{
	int	count;

	count = 0;
	if (n == 0)
		count = 1;
	else if (n < 0)
	{
		count++;
		n *= -1;
	}
	while (n > 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

// char	ft_itoa(int n)
// {
// 	char	*str;
// 	int		len;
// 	long	num;

// 	num = n;
// 	len = count(n);
// 	str = malloc(sizeof(char) * (len + 1));
// 	if (!str)
// 		return (NULL);
// 	str[len--] = '\0';
// 	if (num < 0)
// 	{
// 		str[0] = '-';
// 		num *= -1;
// 	}
// 	if (num == 0)
// 		str[0] = '0';
// 	while (num > 0)
// 	{
// 		str[len--] = 48 + (num % 10);
// 		num /= 10;
// 	}
// 	return (str);
// }