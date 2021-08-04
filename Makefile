NAME = push_swap

NAME_BONUS = checker

MANDATORY	=	main.c\
				src/operations_1.c\
				src/operations_2.c\
				src/operations_3.c\
				src/sort.c

BONUS	=		bonus/main_checker.c\
				bonus/src/operations_2.c\
				bonus/src/operations_1.c\
				bonus/src/do_operations.c\
				bonus/src/bonus_utils.c\
				bonus/src/write_welcome.c\
				bonus/src/printf_stack.c\
				get_next_line/get_next_line.c

OBJ = $(MANDATORY:.c=.o)

OBJ_1 = $(BONUS:.c=.o)

CC = gcc

INC_1 = -I./includes

INC_2 = -I./bonus/includes

FLAGS	= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
		$(MAKE) -C ./ft_printf
		cp ft_printf/libftprintf.a .
		cp ft_printf/libft/libft.a .
		$(CC) $(FLAGS) $(INC_1) $(MANDATORY) -fsanitize=address -g3 libftprintf.a libft.a -o $(NAME)

bonus: 	$(OBJ_1)
		$(MAKE) -C ./ft_printf
		cp ft_printf/libftprintf.a .
		cp ft_printf/libft/libft.a .
		$(CC) $(FLAGS) $(INC_2) $(BONUS) -fsanitize=address -g3 libftprintf.a libft.a -o $(NAME_BONUS)

clean:
	$(MAKE) clean -C ./ft_printf
	rm -rf *.o
	#rm -rf a.out
	#rm -rf a.out*

fclean: clean
	$(MAKE) fclean -C ./ft_printf
	#rm -rf $(NAME)
	#rm -rf $(NAME_BONUS)
	#rm -rf *.a

re: fclean all

.PHONY:	all clean fclean bonus re
