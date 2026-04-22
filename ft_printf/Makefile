CC = cc

CFLAGS = -Wall -Wextra -Werror -g3

SRCS = ft_helper.c ft_hex.c ft_printf.c\

NAME = libftprintf.a

OBJS = $(SRCS:.c=.o)

OBJSB = $(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(OBJSB)

fclean: clean 
	rm -f $(NAME)

re: fclean all

.PHONY: all fclean clean re
