NAME = push_swap

MANDATORY	=	push_swap.c

OBJ = $(MANDATORY:.c=.o)

CC = gcc

FLAGS	= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
		#$(MAKE) -C ./ft_printf
		#cp ft_printf/libftprintf.a .
		#cp ft_printf/libft.a .
		$(CC) $(FLAGS) $(MANDATORY) libftprintf.a libft.a -fsanitize=address -g3 -o $(NAME)

clean:
	#$(MAKE) clean -C ./ft_printf
	rm -rf *.o
	rm -rf a.out

fclean: clean
	#$(MAKE) fclean -C ./ft_printf
	rm -rf $(NAME)

re: fclean all

.PHONY:	all clean fclean bonus re
