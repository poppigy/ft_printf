#include "ft_printf.h"

static int	zero_int(int c, int al, char *d)
{
	if (c != 0)
		c = write(1, d, ft_strlen(d));
	if (al == 2)
		c = write(1, d, ft_strlen(d)) + 1;
	if (c == 0 && al == 1)
	{
		write(1, "\0", 1);
		c += write(1, d, ft_strlen(d));
		return (c + 1);
	}
	if (c == 0 && al == 0)
	{
		c += write(1, d, ft_strlen(d));
		write(1, "\0", 1);
		return (c + 1);
	}
	return (c);
}

int			ft_ifc(t_list *str, va_list ap)
{
	char	*d;
	int		al;
	char	fl;
	int		i;
	int		c;

	c = (str->type != '%') ? va_arg(ap, int) : (int)'%';
	i = (c == 0) ? 0 : 1;
	if (!(d = (char *)malloc(sizeof(char) * (i + 1))))
		return (0);
	d[i] = '\x00';
	if (i == 1)
		d[0] = (char)c;
	al = align(str);
	fl = filler(str, al);
	if (*str->flags != 'e')
		free(str->flags);
	if (c == 0 && str->width < 2)
		c = zero_int(c, 2, d);
	d = fill_the_string(str, fl, al, d);
	c = zero_int(c, al, d);
	if (d)
		free(d);
	return (c);
}
