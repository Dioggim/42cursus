# Nome do arquivo da biblioteca
NAME = libft.a

# Compilador e flags de compilação
CC = cc
CFLAGS = -Wall -Werror -Wextra

# Arquivos fonte obrigatórios e de bônus
SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_memset.c ft_isascii.c ft_bzero.c ft_isprint.c ft_memcpy.c ft_memmove.c ft_strlen.c \
       ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
       ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
       ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
       ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
       ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

BONUS_SRCS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c \
             ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c \
             ft_lstmap_bonus.c

# Arquivos objetos correspondentes
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

# Regras padrão
all: $(NAME) $(BONUS_OBJS)

# Criação da biblioteca
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

# Regras para os bônus
bonus: $(BONUS_OBJS)
	ar rcs $(NAME) $(BONUS_OBJS)

# Limpeza dos arquivos objetos
clean:
	rm -f $(OBJS) $(BONUS_OBJS)

# Limpeza total, incluindo o arquivo da biblioteca
fclean: clean
	rm -f $(NAME)

# Recompilação total
re: fclean all

# Indicação de que não há arquivos a gerar explicitamente
.PHONY: all clean fclean re bonus
