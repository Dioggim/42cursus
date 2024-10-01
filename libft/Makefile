# Nome do arquivo de saída
NAME = libft.a

# Compilador e flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Lista de arquivos-fonte e objetos
SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
       ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
       ft_memmove.c ft_memset.c ft_split.c ft_strchr.c ft_strdup.c ft_strjoin.c \
       ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c \
       ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_strtrim.c ft_split.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

OBJ = $(SRCS:.c=.o)

# Regra padrão: compilar tudo e gerar libft.a
all: $(NAME)
	@echo "Compilando libft..."
	@ar rcs $(NAME) $(OBJ)
	@echo "Biblioteca estática criada: $(NAME)"

# Regra para criar a biblioteca estática
$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@echo "Biblioteca estática criada: $(NAME)"

# Regra para compilar arquivos .o a partir dos arquivos .c
%.o: %.c libft.h
	@$(CC) $(CFLAGS) -c $< -o $@

# Limpar os arquivos objeto (.o)
clean:
	@rm -f $(OBJ)
	@echo "Arquivos objetos removidos."

# Limpar os arquivos objetos e a biblioteca
fclean: clean
	@rm -f $(NAME)
	@echo "Biblioteca removida."

# Recompilar tudo
re: fclean all
