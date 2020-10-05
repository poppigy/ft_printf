#include "ft_printf.h"

char	*ft_ifs(t_list *specifier, char *s)
{
	char	*string;
	int		al;
	char	fl;

	if (specifier->prec_len > 0)
		string = precision(specifier, s);
	else
		string = ft_substr(s, 0, ft_strlen(s));
	if (!string)
	{
		if (*specifier->flags != 'e')
			free(specifier->flags);
		return (NULL);
	}
	al = align(specifier);
	fl = filler(specifier, al);
	if (*specifier->flags != 'e')
		free(specifier->flags);
	if (specifier->width < 0 && specifier->width_ap == '*')
		specifier->width *= (-1);
	string = fill_the_string(specifier, fl, al, string);
	return (string);
}
