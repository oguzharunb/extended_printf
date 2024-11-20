COMPILER = cc
INCLUDES = ./includes/
SOURCE_DIR = ./srcs/
FLAG = -Wall -Werror -Wextra
NAME = og_printf.a
LIBFT = ./libft/libft.a
SRC_DIR = ./srcs
SRC =	og_unit_length1.c \
		og_fill_flag_bag.c \
		utils.c \
		og_length.c \
		flag_check.c \
		dynwidth_replacer.c \
		og_printf.c \
		write_unsigned_number.c \
		write_signed_number.c \
		write_float_number.c \
		write_string.c \
		write_char.c

OBJS = $(addprefix $(SRC_DIR)/, $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	ar -rcs $(NAME) $(OBJS) $(LIBFT)

$(LIBFT):
	make -C libft

%.o: %.c
	$(COMPILER) $(FLAG) -I $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re
