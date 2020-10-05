#include "ft_printf.h"

char	*ft_ifx(t_list *str, unsigned int c)
{
	int		al;
	int		l;
	char	*d;

	if (str->precision == 0 && c == 0 && str->prec_len >= 1)
		d = ft_strdup("");
	else
		d = ft_itoa_hex(c, str->type);
	if (!d)
	{
		if (*str->flags != 'e')
			free(str->flags);
		return (NULL);
	}
	l = ft_strlen(d);
	al = align(str);
	if (str->prec_len == 0 && str->width > l && ft_strchr(str->flags, '0'))
		str->precision = (*d == '-') ? str->width - 1 : str->width;
	if (str->precision > l || (str->precision >= l && *d == '-'))
		d = precision_int(str, d);
	if (d && str->width > (int)ft_strlen(d))
		d = fill_string_int(str, al, d);
	if (*str->flags != 'e')
		free(str->flags);
	return (d);
}
