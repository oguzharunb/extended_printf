COMPILER = cc
INCLUDES = ./includes/
FLAG = -Wall -Werror -Wextra
NAME = libftprintf.a
LIBFT_DIR = ./libft
MANDATORY_DIR = mandatory
MANDATORY_SRCS =	og_unit_length1.c \
		og_unit_length2.c \
		og_fill_flag_bag.c \
		utils.c \
		utils2.c \
		utils3.c \
		og_length.c \
		flag_check.c \
		dynwidth_replacer.c \
		ft_printf.c \
		write_unsigned_number.c \
		write_signed_number.c \
		write_string.c \
		write_char.c \
		write_pointer.c \
		fill_string.c
LIBFT_SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isin.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putptr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strncpy.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_upper.c ft_strnstr.c ft_striteri.c
LIBFT_OBJS = $(addprefix $(LIBFT_DIR)/, $(LIBFT_SRCS:.c=.o))
MANDATORY_OBJS = $(addprefix $(MANDATORY_DIR)/, $(MANDATORY_SRCS:.c=.o))

all: $(NAME)

$(NAME): $(MANDATORY_OBJS) $(LIBFT_OBJS)
	ar -rcs $(NAME) $(MANDATORY_OBJS) $(LIBFT_OBJS)

%.o: %.c
	$(COMPILER) $(FLAG) -I $(INCLUDES) -c $< -o $@

clean:
	rm -f $(MANDATORY_OBJS) $(BONUS_OBJS) $(LIBFT_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
