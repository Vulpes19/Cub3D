TARGET = test

SRCS = srcs/dummyMain.c srcs/errorMessages.c srcs/parser_tools.c srcs/ft_split.c srcs/get_next_line_utils.c srcs/get_next_line.c srcs/organizers.c srcs/libft.c srcs/parser.c srcs/protection.c

OBJS = $(SRCS:%.c=%.o)

FLAGS = -Wall -Werror -Wextra

CC = gcc $(FLAGS)

DEL = rm -rf

all: $(TARGET)

%.o: %.c
	gcc $(FLAGS) -c  $< -o $@

$(TARGET): $(OBJS)
		gcc $(FLAGS) $(OBJS) -o $(TARGET)

re: fclean all

clean:
	$(DEL) $(OBJS)

fclean: clean
	$(DEL) $(TARGET)

.PHONY: clean fclean re all
