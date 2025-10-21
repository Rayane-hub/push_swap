NAME	= push_swap

CC 			= cc

CFLAGS		= -g3 -Wall -Wextra -Werror

SRC			= main.c check_tab.c fill_lst.c swap_push.c rotate.c reverse_rotate.c sort_stack.c push_min_max.c choice_cmd.c cost.c cost_reverse.c fill_find_i.c rank_exit.c

OBJ 		= $(SRC:.c=.o)

all : $(NAME)

%.o : %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	make -sC ft_printf
	$(CC) $(OBJ) -L ft_printf -l ftprintf -o $(NAME)

clean :
	rm -rf  $(OBJ) 
	make -sC ft_printf clean

fclean : clean
		rm -f $(NAME)
		make -sC ft_printf fclean

re : fclean all

.PHONY : all clean fclean re