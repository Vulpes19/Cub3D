/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:25:47 by abaioumy          #+#    #+#             */
/*   Updated: 2023/01/23 12:13:03 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>

# define TILE 64
# define PI 3.14159265359
# define RADIAN 0.01745329251

enum	e_bool
{
	TRUE = 1,
	FALSE = 0
};

typedef enum s_status
{
	GOOD,
	ERROR
}	t_status;

typedef struct s_parse
{
	int			file;
	char		*buff;
	char		*tmp;
	char		**d_tmp;
	char		**floor;
	char		**ceiling;
	size_t		map_length;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*f;
	char		*c;
	char		**map;
	char		**textures_colors;
	int			player_x;
	int			player_y;
	char		player_direction;
	char		*leaks;
	int			longest_line;
	t_status	flag;
}	t_parse;

typedef struct s_texture
{
	void	*image;
	int		color;
	char	*address;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
}	t_texture;

typedef struct s_pixel
{
	void	*image;
	char	*address;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
}	t_pixel;

typedef struct s_mlx
{
	void	*init;
	void	*window;
	t_pixel	*pixel;
	t_pixel	*mini_map;
}	t_mlx;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	angle;
	double	rot_x;
	double	rot_y;
	double	fov;
	double	half_fov;
	int		height;
	int		speed;
}	t_player;

typedef struct s_ray
{
	double	angle;
	double	x;
	double	y;
	double	x_a;
	double	y_a;
	double	h_pos_x;
	double	h_pos_y;
	double	v_pos_x;
	double	v_pos_y;
	double	distance;
	double	distance_v;
	double	distance_h;
}	t_ray;

typedef struct s_wall
{
	double	height;
	double	begin_draw;
	double	bottom;
	int		tex_x;
	int		tex_y;
	int		is_horizontal;
	int		is_vertical;
	int		color;
	t_texture	*texture;
}	t_wall;
typedef struct s_game
{
	t_parse		*data;
	t_player	*player;
	t_ray		*ray;
	t_wall		*wall;
	t_texture	*texture_north;
	t_texture	*texture_south;
	t_texture	*texture_east;
	t_texture	*texture_west;
	double		move_speed;
	double		rot_speed;
	int			*floor;
	int			*ceiling;
	int			color_floor;
	int			color_ceiling;
	t_mlx		*mlx;
}	t_game;

enum e_bool	ft_allocate_game(int ac, char **av, t_game *game);
void		ft_init_game(t_game *game);
void	ft_compare_distances(t_game *game, int ray);

#endif