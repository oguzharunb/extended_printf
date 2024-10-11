COMPILER = cc
INCLUDES = ./includes/
SOURCE_DIR = ./srcs/
FLAG = -Wall -Werror -Wextra
NAME = og_printf
SRC_DIR = ./srcs
SRC = main.c \
		ft_bzero.c \
		og_fill_flag_bag.c \
		utils.c \
		og_length.c

OBJS = $(addprefix $(SRC_DIR)/, $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(COMPILER) $(FLAG) -I $(INCLUDES) $(OBJS) -o $(NAME)

%.o: %.c
	$(COMPILER) $(FLAG) -I $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re