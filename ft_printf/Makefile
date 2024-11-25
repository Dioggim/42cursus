# Nome do arquivo de saída
NAME = libftprintf.a

# Compilador e flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -I /home/diogo/Documentos/GitHub/42cursus/libft  # Caminho absoluto para a libft

# Arquivos
SRCS = ft_printf.c
OBJS = $(SRCS:.c=.o)

# Caminho para a libft
LIBFT_DIR = /home/diogo/Documentos/GitHub/42cursus/libft
LIBFT = $(LIBFT_DIR)/libft.a

# Regras
all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all
