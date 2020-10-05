#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		j;
	int		i;

	i = 0;
	j = ft_strlen(s1);
	s2 = (char*)malloc(sizeof(char) * (j + 1));
	if (s2 == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
