CC		:= cc

CFLAGS	:= -Wall -Wextra -Werror

NAME	:= push_swap

LIB_DIR	:= libft

LIBFT	:= $(LIB_DIR)/libft.a

PF_DIR	:= ft_printf

PRINTF	:= $(PF_DIR)/libftprintf.a

LIBS	:= -L$(LIB_DIR) -lft -L$(PF_DIR) -lftprintf -lm

SRC		:=	main.c \
			parser.c \
			parser_utils.c \
			bench.c \
			steck_imp.c \
			rotate_operation.c \
			revers_operation.c \
			swap_operation.c \
			push_operation.c \
			disorder.c \
			strategy.c \
			adaptive.c \
			simple_sort.c \
			medium_sort.c \
			complex_sort.c

OBJ		:= $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIB_DIR) all

$(PRINTF):
	$(MAKE) -C $(PF_DIR) all

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIB_DIR) clean
	$(MAKE) -C $(PF_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIB_DIR) fclean
	$(MAKE) -C $(PF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
