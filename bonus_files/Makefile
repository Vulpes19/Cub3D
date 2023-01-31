
#* TARGET *#
TARGET = cub3D_bonus

#* FILES *#
FILES = main_bonus.c draw_bonus.c close_bonus.c raycast_bonus.c handle_input_bonus.c math_bonus.c texture_manager_bonus.c game_bonus.c libft_bonus.c init_parsing_bonus.c \
	errorMessages_bonus.c parser_bonus.c parser_tools_bonus.c protection_bonus.c organizers_bonus.c get_next_line_bonus.c get_next_line_utils_bonus.c \
	ft_split_bonus.c colors_bonus.c check_intersections_bonus.c collision_bonus.c pixel_bonus.c organizers_tools_bonus.c mini_map_bonus.c norme_bonus.c

#* SOURCE FILES *#
SRC = $(addprefix src/, $(FILES))

#* OBJECT DIRECTORY *#
OBJ_DIR = obj

#* OBJECT FILES *#
OBJS = $(SRC:src/%.c=$(OBJ_DIR)/%.o)

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