#include "ft_printf.h"

t_list	*ft_processed_spec(t_list *str, char *format)
{
	char	*sc;

	sc = format;
	if (!(str = isflag(str, sc)))
		return (str);
	sc += str->flags_len;
	str = iswidth(str, sc);
	sc += str->width_len;
	str = isprecision(str, sc);
	sc += str->prec_len;
	str = istype(str, sc);
	str->splen = (str->flags_len + str->width_len);
	str->splen += (str->prec_len + str->type_len);
	return (str);
}

t_list	*print_argument(t_list *str, va_list ap)
{
	char	*argument;
	int		len;

	if (str->type == 'c' || str->type == '%')
	{
		str->arglen = ft_ifc(str, ap);
		return (str);
	}
	else
		argument = ft_format_arg(str, ap);
	len = ft_strlen(argument);
	str->arglen = write(1, argument, len);
	free(argument);
	return (str);
}

t_list	*print_string(char *s, t_list *str, va_list ap)
{
	char	*chaser;

	chaser = s;
	while (*chaser && *chaser != '%')
	{
		write(1, chaser, 1);
		str->string++;
		chaser++;
	}
	if (*chaser == '%')
		chaser++;
	if (*chaser)
	{
		str = ft_processed_spec(str, chaser);
		if (str->valid == 0)
		{
			write(1, "", 1);
			return (str);
		}
		str = print_argument(str, ap);
		str->splen += 1;
	}
	str->total = str->string + str->arglen;
	return (str);
}
