#include "libft.h"

static char	*hex_con(unsigned long int n)
{
	char				*hex;
	char				*a;
	int					len;
	unsigned long int	left;

	a = "0123456789abcdef";
	len = 0;
	left = n;
	if (n > 15)
		while (left > 0)
		{
			left = left / 16;
			len++;
		}
	else
		len = 1;
	if (!(hex = (char *)ft_calloc(1, (len + 1))))
		return (NULL);
	while (--len >= 0)
	{
		left = n % 16;
		n = n / 16;
		hex[len] = a[left];
	}
	return (hex);
}

char		*ft_itoa_p(unsigned long int n)
{
	char	*itoa;

	itoa = hex_con(n);
	return (itoa);
}
