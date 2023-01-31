
#* TARGET *#
TARGET = cub3D

#* FILES *#
FILES = main.c draw.c close.c raycast.c handle_input.c math.c texture_manager.c game.c libft.c init_parsing.c \
	errorMessages.c parser.c parser_tools.c protection.c organizers.c get_next_line.c get_next_line_utils.c \
	ft_split.c colors.c check_intersections.c collision.c pixel.c norme.c organizers_tools.c

#* SOURCE FILES *#
SRC = $(addprefix src/, $(FILES))

#* OBJECT DIRECTORY *#
OBJ_DIR = obj

#* OBJECT FILES *#
OBJS = $(SRC:src/%.c=$(OBJ_DIR)/%.o)

#* BONUS FILES *#
BONUS = bonus_files

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
	
bonus:
	$(MAKE) -C $(BONUS)

$(OBJ_DIR)/%.o: src/%.c
	cc $(FLAGS) -c -I $(INCLUDE) $< -o $@

$(TARGET): $(OBJS) $(INCLUDE)
	cc $(FLAGS) $(MLX) -I $(INCLUDE) -I $(MLXINCLUDE) -L $(LIB) $(OBJS) -o $(TARGET)

re: fclean all

clean:
	$(DEL) $(OBJS)
	$(MAKE) -C $(BONUS) clean

fclean:	clean
	$(DEL) $(TARGET)
	$(MAKE) -C $(BONUS) fclean

.PHONY: clean fclean re all