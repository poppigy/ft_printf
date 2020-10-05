#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*a;
	size_t			fullsize;

	if (size != 0)
	{
		if (((count * size) / size) != count)
			return (NULL);
	}
	fullsize = count * size;
	a = (unsigned char*)malloc(sizeof(unsigned char) * fullsize);
	if (a == NULL)
		return (NULL);
	ft_bzero(a, fullsize);
	return (a);
}
