#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char *p1;
	unsigned char *p2;

	p1 = (unsigned char*)s1;
	p2 = (unsigned char*)s2;
	if (n == 0)
		return (0);
	while (--n > 0 && (*p1 && *p1 == *p2))
	{
		p1++;
		p2++;
	}
	return (*p1 - *p2);
}
