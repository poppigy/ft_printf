#include "ft_printf.h"

char	*ft_ifp(t_list *specifier, unsigned long int c)
{
	char	*d;
	char	*p;
	int		al;

	if (specifier->precision == 0 && c == 0 && specifier->prec_len >= 1)
		d = ft_strdup("");
	else
		d = ft_itoa_p(c);
	if (!d)
	{
		if (*specifier->flags != 'e')
			free(specifier->flags);
		return (NULL);
	}
	al = align(specifier);
	if (specifier->precision > (int)ft_strlen(d))
		d = precision_int(specifier, d);
	p = ft_strjoin("0x", d);
	free(d);
	if (p && specifier->width > (int)ft_strlen(p))
		p = fill_string_int(specifier, al, p);
	if (*specifier->flags != 'e')
		free(specifier->flags);
	return (p);
}
