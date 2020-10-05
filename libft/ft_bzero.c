#include "libft.h"

void	ft_bzero(void *p, size_t len)
{
	unsigned char *a;

	a = p;
	while (len-- > 0)
		*a++ = '\0';
}
