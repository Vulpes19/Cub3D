
#* TARGET *#
TARGET = cub3D

#* FILES *#
FILES = main.c draw.c close.c raycast.c handle_input.c math.c texture_manager.c game.c libft.c init_parsing.c \
	errorMessages.c parser.c parser_tools.c protection.c organizers.c get_next_line.c get_next_line_utils.c \
	ft_split.c colors.c check_intersections.c

#* SOURCE FILES *#
SRC = $(addprefix src/, $(FILES))

#* OBJECT DIRECTORY *#
OBJ_DIR = obj

#* OBJECT FILES *#
OBJS = $(SRC:src/%.c=$(OBJ_DIR)/%.o)

#* FLAGS *#
FLAGS = -fsanitize=address -g3
MLX = -lmlx -framework OpenGL -framework AppKit

#*  INCLUDE PATHS *#
INCLUDE = include/
MLXINCLUDE = /usr/local/include

#* LIBRARY PATH *#
LIB = /usr/local/lib

#* DELETE *#
DEL = rm -rf

all: $(TARGET)
	

$(OBJ_DIR)/%.o: src/%.c
	cc $(FLAGS) -c -I $(INCLUDE) $< -o $@

$(TARGET): $(OBJS) $(INCLUDE)
	cc $(FLAGS) $(MLX) -I $(INCLUDE) -I $(MLXINCLUDE) -L $(LIB) $(OBJS) -o $(TARGET)

re: fclean all

clean:
	$(DEL) $(OBJS)

fclean:	clean
	$(DEL) $(TARGET)

.PHONY: clean fclean re all