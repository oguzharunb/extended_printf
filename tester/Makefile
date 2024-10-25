NAME = tester
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = tester.c main.c unit_tests/length_tests.c unit_tests/total_length_test.c unit_tests/flag_check_tests.c
OBJECTS = $(SRCS:.c=.o)
LIB = ../og_printf.a
HEADER = tester.h
LIBFT = ../libft/libft.a

all: $(NAME)

$(NAME): $(OBJECTS) $(HEADER) $(LIB) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(LIBFT) $(LIB) $(OBJECTS)

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
