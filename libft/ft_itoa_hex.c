#include "libft.h"

static char	*hex_con(unsigned int n, char type)
{
	char			*hex;
	char			*a;
	int				len;
	unsigned int	left;

	a = (type == 'x') ? "0123456789abcdef" : "0123456789ABCDEF";
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

char		*ft_itoa_hex(unsigned int n, char type)
{
	char	*itoa;

	itoa = hex_con(n, type);
	return (itoa);
}
