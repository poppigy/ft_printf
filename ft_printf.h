#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef struct	s_list
{
	int			valid;
	int			string;
	int			arglen;
	int			splen;
	int			c_null_len;
	int			total;
	int			flags_len;
	int			width_len;
	int			prec_len;
	int			type_len;
	char		*flags;
	int			width;
	char		width_ap;
	int			precision;
	char		precision_ap;
	char		type;
}				t_list;

t_list			*alloc_struct(void);
t_list			*reset_str(t_list *str);
int				splitandmerge(const char *s, va_list ap);
size_t			check_input(const char *format);
int				ft_printf(const char *format, ...);
t_list			*print_string(char *s, t_list *str, va_list ap);
t_list			*print_argument(t_list *str, va_list ap);
t_list			*isflag(t_list *str, char *s);
t_list			*iswidth(t_list *str, char *s);
t_list			*isprecision(t_list *str, char *s);
t_list			*istype(t_list *str, char *s);
t_list			*ft_processed_spec(t_list *str, char *format);
t_list			*print_argument(t_list *str, va_list ap);
t_list			*print_string(char *s, t_list *str, va_list ap);
char			*ft_format_arg(t_list *str, va_list ap);
int				ft_ifc(t_list *specifier, va_list ap);
char			*ft_ifs(t_list *specifier, char *s);
char			*ft_ifp(t_list *str, unsigned long int c);
char			*ft_ifd(t_list *str, int c);
char			*ft_ifu(t_list *specifier, unsigned int c);
char			*ft_ifx(t_list *specifier, unsigned int c);
char			filler(t_list *str, int al);
int				align(t_list *specifier);
char			*precision(t_list *str, char *s);
char			*width(t_list *specifier, char fl, char *d);
char			*fill_the_string(t_list *specifier, char fl, int al, char *d);
char			*precision_int(t_list *str, char *s);
char			*fill_string_int(t_list *specifier, int al, char *d);

#endif
