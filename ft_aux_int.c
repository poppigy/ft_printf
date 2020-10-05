#include "ft_printf.h"

char	*precision_int(t_list *str, char *s)
{
	int		i;
	int		j;
	char	*string;
	char	*prec;

	i = (int)ft_strlen(s);
	j = (*s == '-') ? str->precision - i + 2 : str->precision - i;
	if (!(prec = (char *)malloc(sizeof(char) * (j + 1))))
	{
		free(s);
		return (NULL);
	}
	prec[j] = '\0';
	while (--j > 0)
		prec[j] = '0';
	prec[0] = (*s == '-') ? '-' : '0';
	string = (*s == '-') ? ft_strjoin(prec, s + 1) : ft_strjoin(prec, s);
	free(prec);
	free(s);
	return (string);
}

char	*fill_string_int(t_list *specifier, int al, char *d)
{
	char	*string;
	int		fill_len;
	char	*fill;
	char	fl;

	fill_len = specifier->width - (int)ft_strlen(d);
	if (!(fill = (char *)malloc(sizeof(char) * (fill_len + 1))))
	{
		free(d);
		return (NULL);
	}
	fill[fill_len] = '\0';
	fl = filler(specifier, al);
	while (--fill_len >= 0)
		fill[fill_len] = fl;
	if (al == 0)
		string = ft_strjoin(fill, d);
	else
		string = ft_strjoin(d, fill);
	free(d);
	free(fill);
	return (string);
}
