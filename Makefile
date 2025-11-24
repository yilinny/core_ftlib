NAME = libft.a
FLAGS = -Wall -Werror -Wextra
SRC = ft_atoi.c    ft_isalnum.c  ft_isdigit.c  ft_memcpy.c   ft_putchar_fd.c  ft_putstr_fd.c  ft_strdup.c    ft_strlcat.c  ft_strmap.c   ft_strrchr.c  ft_tolower.c ft_bzero.c   ft_isalpha.c  ft_isprint.c  ft_memchr.c  ft_memmove.c  ft_putendl_fd.c  ft_split.c      ft_striteri.c  ft_strlcpy.c  ft_strncmp.c  ft_strtrim.c  ft_toupper.c ft_calloc.c  ft_isascii.c  ft_itoa.c     ft_memcmp.c  ft_memset.c   ft_putnbr_fd.c   ft_strchr.c     ft_strjoin.c   ft_strlen.c   ft_strnstr.c  ft_substr.c
OBJS = $(SRC:c=o)
all: $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)
	@echo "library is built"

%.o : %.c
	cc $(FLAGS) -c $< -o $@

fclean: clean 
	rm -f $(NAME)

clean:
	rm -f $(OBJS)

re: fclean all