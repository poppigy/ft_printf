#include "ft_printf.h"

t_list			*isflag(t_list *str, char *s)
{
	int		i;
	char	*flags;

	i = 0;
	if (ft_strchr("-0", *s) && s)
	{
		while (ft_strchr("-0", s[i]))
			i++;
		str->flags_len = i;
		if (!(flags = ft_substr(s, 0, i)))
			return (NULL);
		str->flags = flags;
	}
	if (s[i] == '\0')
		str->valid = 0;
	return (str);
}

t_list			*iswidth(t_list *str, char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (ft_isdigit(*s))
	{
		while (*s >= '0' && *s <= '9')
		{
			i = i * 10 + *s - 48;
			j++;
			s++;
		}
		str->width_len = j;
		str->width = i;
	}
	if (*s == '*' && str->width_len == 0)
	{
		str->width_ap = '*';
		str->width_len = 1;
	}
	if (*s == '*' && str->width_len != 0)
		str->valid = 0;
	str->valid = (*(s + 1) == '\0' && !ft_strchr("cspdiuxX%", *s)) ? 0 : 1;
	return (str);
}

static t_list	*prec_check(t_list *str, char *s, int j, int znak)
{
	int i;

	i = 0;
	if (ft_isdigit(*s))
	{
		while (*s >= '0' && *s <= '9')
		{
			i = i * 10 + *s - 48;
			j++;
			s++;
		}
		str->prec_len = j;
		str->precision = (i * znak);
	}
	if (*s == '*')
	{
		if (j == 1 || (j == 2 && znak < 0))
		{
			str->precision_ap = '*';
			str->prec_len = (j + 1);
		}
		else
			str->valid = 0;
	}
	return (str);
}

t_list			*isprecision(t_list *str, char *s)
{
	int	j;
	int	znak;

	j = 1;
	znak = 1;
	if (*s == '.')
	{
		s++;
		if (ft_strchr("cspdiuxX%", *s))
		{
			str->prec_len = 1;
			str->precision = 0;
		}
		while (*s == '-')
		{
			znak = -1;
			j = 2;
			s++;
		}
		str = prec_check(str, s, j, znak);
	}
	if (*s == '\0')
		str->valid = 0;
	return (str);
}

t_list			*istype(t_list *str, char *s)
{
	char *c;

	c = "cspdiuxX%";
	while (*c)
	{
		if (ft_strchr(c, *s))
		{
			str->type = *s;
			str->type_len = 1;
			break ;
		}
		c++;
	}
	if (*c == '\0' && str->type == '0')
		str->valid = 0;
	return (str);
}
