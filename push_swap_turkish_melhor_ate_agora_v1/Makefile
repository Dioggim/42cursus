NAME = push_swap

CC = cc
CFLAGS = -Wall -Werror -Wextra

SRCS = \
    main.c \
    parse_args.c \
    stack_ops.c \
    stack_utils.c \
    move_instructions.c \
    push_instruction.c \
    rotate_instructions.c \
    rotate_instructions2.c \
    small_sorts.c \
    turkish_sort.c \
    error_handling.c

OBJS = $(SRCS:.c=.o)

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(LIBFT) $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	@rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
