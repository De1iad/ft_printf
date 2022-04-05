NAME	= libftprintf.a
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
SRCS	= $(wildcard *.c)
OBJS	= $(SRCS:.c=.o)
LIBFT	= ./libft

all:	$(NAME)


$(NAME): $(OBJS)
		make re -C $(LIBFT)
		ar -cr $(NAME) $(OBJS)

clean:
		rm -f *.o
		make clean -C $(LIBFT)

fclean: clean
		rm -f $(NAME)
		make fclean -C $(LIBFT)

re: fclean all