
#* TARGET *#
TARGET = cub3D

#* FILES *#
FILES = main.c error_printing.c

#* SOURCE FILES *#
SRC = $(addprefix src/, $(FILES))

#* OBJECT FILES *#
OBJS = $(SRC:%.c=%.o)

#* FLAGS *#
FLAGS = -Wall -Wextra -Werror
MLX = -lmlx -framework OpenGL -framework AppKit

#*  INCLUDE PATHS *#
INCLUDE = include/
MLXINCLUDE = /usr/local/include

#* LIBRARY PATH *#
LIB = /usr/local/lib

#* DELETE *#
DEL = rm -rf

all: $(TARGET)
	

%.o: %.c
	cc $(FLAGS) -c -I $(INCLUDE) $< -o $@

$(TARGET): $(OBJS) $(INCLUDE)
	cc $(FLAGS) $(MLX) -I $(INCLUDE) -I $(MLXINCLUDE) -L $(LIB) $(OBJS) -o $(TARGET)

re: fclean all

clean:
	$(DEL) $(OBJS)

fclean:	clean
	$(DEL) $(TARGET)

.PHONY: clean fclean re all