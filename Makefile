NAME	=	libftprintf.a
LIBFT	=	./libft/libft.a

LIB_SRC	=	ft_bzero.c		\
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

SRC		=	ft_aux_char.c		\
			ft_aux_int.c		\
			ft_format_string.c	\
			ft_print_string.c	\
			ft_ifc.c			\
			ft_ifd.c			\
			ft_ifp.c			\
			ft_ifs.c			\
			ft_ifu.c			\
			ft_ifx.c			\
			ft_parser.c			\
			ft_printf.c

LIB_HED	=	./libft/libft.h

OBJ		=	$(SRC:c=o)
HEADER	=	ft_printf.h

CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra
RM		=	rm -f
AR		=	ar rcs

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@cp $(LIBFT) ./$(NAME)
	@$(AR) $(NAME) $(OBJ)

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -I . -c $< -o $@

$(LIBFT): $(addprefix ./libft/, $(LIB_SRC:c=o)) $(LIB_HED)
	@make -C ./libft

clean:
	@make -C ./libft clean
	@$(RM) $(OBJ) $(OBJBNS)

fclean:
	@make -C ./libft fclean
	@$(RM) $(OBJ) $(OBJBNS)
	@$(RM) $(NAME)

re: fclean all
