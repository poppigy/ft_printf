#include "libft.h"

static int	itoa_count(unsigned int n)
{
	int i;

	i = 0;
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i + 1);
}

static char	*itoa_string(unsigned int n, int b)
{
	char	*itoa;
	int		i;

	i = 0;
	itoa = ft_calloc(1, sizeof(char) * (b + 1));
	if (itoa == NULL)
		return (NULL);
	while (n > 9 && --b > 0)
	{
		itoa[b] = n % 10 + '0';
		n = n / 10;
	}
	if (n >= 0)
		itoa[i] = n + '0';
	return (itoa);
}

char		*ft_itoa_ui(unsigned int n)
{
	char	*itoa;
	int		b;

	b = itoa_count(n);
	itoa = itoa_string(n, b);
	return (itoa);
}
