#include "ft_printf.h"

t_list	*reset_str(t_list *str)
{
	str->arglen = 0;
	str->c_null_len = 0;
	str->splen = 0;
	str->string = 0;
	str->total = 0;
	str->flags_len = 0;
	str->width_len = 0;
	str->prec_len = 0;
	str->type_len = 0;
	str->flags = "empty";
	str->width = -1;
	str->width_ap = '0';
	str->precision = 0;
	str->precision_ap = '0';
	str->type = '0';
	return (str);
}

t_list	*alloc_struct(void)
{
	t_list *str;

	str = (t_list *)malloc(sizeof(t_list));
	if (!str)
		return (NULL);
	str->valid = 1;
	str->arglen = 0;
	str->c_null_len = 0;
	str->string = 0;
	str->total = 0;
	str->splen = 0;
	str->flags_len = 0;
	str->width_len = 0;
	str->prec_len = 0;
	str->type_len = 0;
	str->flags = "empty";
	str->width = -1;
	str->width_ap = '0';
	str->precision = 0;
	str->precision_ap = '0';
	str->type = '0';
	return (str);
}

int		splitandmerge(const char *s, va_list ap)
{
	int		i;
	t_list	*str;

	i = 0;
	if (!(str = alloc_struct()))
		return (0);
	while (*s)
	{
		str = reset_str(str);
		str = print_string((char *)s, str, ap);
		if (str->valid == 0)
			return (0);
		i += str->total;
		s = s + (str->string + str->splen + str->c_null_len);
	}
	free(str);
	return (i);
}

size_t	check_input(const char *format)
{
	if (ft_strlen(format) == 1 && ft_strncmp(format, "%", 1) == 0)
		return (0);
	return (1);
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;

	if (!check_input(format))
		return (0);
	va_start(ap, format);
	i = splitandmerge(format, ap);
	va_end(ap);
	return (i);
}
