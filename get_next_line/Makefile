NAME = get_next_line.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = get_next_line_utils.c get_next_line.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all