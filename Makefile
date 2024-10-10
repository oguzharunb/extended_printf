COMPILER = cc
INCLUDES = ./includes/
SOURCE_DIR = ./srcs/
FLAG = -Wall -Werror -Wextra
NAME = og_printf
SRCS = ./srcs/main.c \
		./srcs/og_reset_flags.c \
		./srcs/og_fill_flag_bag.c \
		./srcs/utils.c

OBJS = $(SRCS:.c=.o)

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