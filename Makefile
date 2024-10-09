COMPILER = cc
INCLUDES = ./includes/
SOURCE_DIR = ./srcs/
FLAG = -Wall -Werror -Wextra
NAME = og_printf.a
SRCS = 
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)

