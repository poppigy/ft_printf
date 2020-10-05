#include "ft_printf.h"

static char	*va_int(t_list *str, va_list ap)
{
	int		i;
	char	*s;

	s = NULL;
	if (str->type != '%')
		i = va_arg(ap, int);
	if (str->type == 'd' || str->type == 'i')
		s = ft_ifd(str, i);
	return (s);
}

static char	*va_char(t_list *str, va_list ap)
{
	char	*i;
	char	*s;

	s = NULL;
	i = va_arg(ap, char *);
	if (i == NULL)
		i = "(null)";
	if (str->type == 's')
		s = ft_ifs(str, i);
	return (s);
}

static char	*va_uint(t_list *str, va_list ap)
{
	unsigned int	i;
	char			*s;

	s = NULL;
	i = va_arg(ap, unsigned int);
	if (str->type == 'u')
		s = ft_ifu(str, i);
	if (str->type == 'x' || str->type == 'X')
		s = ft_ifx(str, i);
	return (s);
}

static char	*va_ulint(t_list *str, va_list ap)
{
	unsigned long int	i;
	char				*s;

	s = NULL;
	i = va_arg(ap, unsigned long int);
	if (str->type == 'p')
		s = ft_ifp(str, i);
	return (s);
}

char		*ft_format_arg(t_list *str, va_list ap)
{
	char	*s;

	s = NULL;
	if (str->valid == 0)
		return (s);
	if (str->width_ap == '*')
		str->width = va_arg(ap, int);
	if (str->precision_ap == '*')
		str->precision = va_arg(ap, int);
	if (str->type == 'd' || str->type == 'i')
		s = va_int(str, ap);
	if (str->type == 's')
		s = va_char(str, ap);
	if (str->type == 'p')
		s = va_ulint(str, ap);
	if (str->type == 'u' || str->type == 'x' || str->type == 'X')
		s = va_uint(str, ap);
	if (!s)
		str->valid = 0;
	return (s);
}
