#include "ft_printf.h"

static char	*check_di_string(t_list *str, int c)
{
	char	*d;

	if (str->precision == 0 && c == 0 && str->prec_len >= 1)
		d = ft_strdup("");
	else
		d = ft_itoa(c);
	if (!d)
	{
		if (*str->flags != 'e')
			free(str->flags);
		return (NULL);
	}
	return (d);
}

char		*ft_ifd(t_list *str, int c)
{
	int		al;
	int		l;
	char	*d;

	if (!(d = check_di_string(str, c)))
		return (NULL);
	l = (int)ft_strlen(d);
	al = align(str);
	if (str->prec_len == 0 && str->width > l && ft_strchr(str->flags, '0'))
		str->precision = (*d == '-') ? str->width - 1 : str->width;
	if (str->precision > l || (str->precision >= l && *d == '-'))
		d = precision_int(str, d);
	if (str->width < 0 && str->width_ap == '*')
		str->width *= (-1);
	if (d && str->width > (int)ft_strlen(d))
		d = fill_string_int(str, al, d);
	if (*str->flags != 'e')
		free(str->flags);
	return (d);
}
