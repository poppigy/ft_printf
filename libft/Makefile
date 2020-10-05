NAME = libft.a
HEAD = libft.h

SRCS =	ft_bzero.c		\
		ft_calloc.c		\
		ft_isdigit.c	\
		ft_itoa.c		\
		ft_itoa_ui.c	\
		ft_itoa_hex.c	\
		ft_itoa_p.c		\
		ft_putchar_fd.c	\
		ft_putnbr_fd.c	\
		ft_putstr_fd.c	\
		ft_strchr.c		\
		ft_strdup.c		\
		ft_strjoin.c	\
		ft_strlen.c		\
		ft_strncmp.c	\
		ft_substr.c
       


SRCO =	ft_bzero.o		\
       	ft_calloc.o		\
       	ft_isdigit.o	\
      	ft_itoa.o		\
      	ft_itoa_ui.o	\
      	ft_itoa_hex.o	\
      	ft_itoa_p.o		\
      	ft_putchar_fd.o	\
       	ft_putnbr_fd.o	\
       	ft_putstr_fd.o	\
       	ft_strchr.o		\
       	ft_strdup.o		\
       	ft_strjoin.o	\
       	ft_strlen.o		\
       	ft_strncmp.o	\
       	ft_substr.o


BONUSS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
		ft_lstdelone.c

BONUSO = ft_lstnew.o ft_lstadd_front.o ft_lstsize.o ft_lstlast.o ft_lstadd_back.o \
		ft_lstdelone.o

all: $(NAME)

$(NAME): $(SRCO) $(HEAD)
	ar rc $(NAME) $(SRCO)

clean:
	/bin/rm -rf *.o

SRCO: $(HEAD)
	gcc -Wall -Wextra -Werror $(SRCS)-c $< -o $@

fclean: clean
	/bin/rm -rf $(NAME)

re: fclean all

bonus: 
	gcc -Wall -Wextra -Werror -c $(SRCS) $(BONUSS) $(HEAD)
	ar rc $(NAME) $(SRCO) $(BONUSO)

.PHONY: clean fclean re
