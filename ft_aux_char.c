#include "ft_printf.h"

char	filler(t_list *str, int al)
{
	char	filler;

	filler = ' ';
	if (ft_strchr(str->flags, '0') && al == 0)
		filler = '0';
	if (ft_strchr(str->flags, '0') && ft_strchr("duixX", str->type) && al == 0)
		filler = ' ';
	if (str->width < 0 && str->width_ap == '*' && ft_strchr("di", str->type))
		filler *= ' ';
	return (filler);
}

int		align(t_list *specifier)
{
	int	align;

	align = 0;
	if (ft_strchr(specifier->flags, '-'))
		align = 1;
	if (specifier->type == 's' && specifier->width < 0)
		align = 1;
	if (specifier->width < 0 && specifier->width_ap == '*')
		align = 1;
	return (align);
}

char	*precision(t_list *specifier, char *s)
{
	int		i;
	char	*string;

	i = ft_strlen(s);
	if (specifier->precision < 0 || specifier->precision >= i)
		string = ft_substr(s, 0, i);
	else
		string = ft_substr(s, 0, specifier->precision);
	return (string);
}

char	*width(t_list *specifier, char fl, char *d)
{
	int		fill_len;
	char	*fill;

	if (specifier->type == 'c' && *d == '\0')
		fill_len = specifier->width - 1;
	else if (specifier->type == 'c' && *d == '\0')
		fill_len = specifier->width;
	else
		fill_len = specifier->width - (int)ft_strlen(d);
	if (fill_len < 1)
	{
		fill = (char *)malloc(sizeof(char));
		fill[0] = '\0';
	}
	if (fill_len > 0)
	{
		fill = (char *)malloc(sizeof(char) * (fill_len + 1));
		fill[fill_len--] = '\0';
		while (fill_len >= 0)
			fill[fill_len--] = fl;
	}
	return (fill);
}

char	*fill_the_string(t_list *specifier, char fl, int al, char *d)
{
	char	*fill;
	char	*string;

	if (!(fill = width(specifier, fl, d)))
		return (NULL);
	if (al == 0)
		string = ft_strjoin(fill, d);
	else
		string = ft_strjoin(d, fill);
	free(d);
	free(fill);
	return (string);
}
