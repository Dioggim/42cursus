# Nome da biblioteca
NAME = libft.a

# Arquivos de origem (todos os arquivos ft_*.c que você criou)
SRC = ft_strlen.c ft_atoi.c # Adicione todos os arquivos .c aqui

# Arquivos objetos gerados a partir dos arquivos .c
OBJ = $(SRC:.c=.o)

# Compilador e flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Regra padrão: compilar tudo e gerar libft.a
all: $(NAME)

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
