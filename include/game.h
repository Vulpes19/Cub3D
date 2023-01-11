/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:25:47 by abaioumy          #+#    #+#             */
/*   Updated: 2023/01/11 15:54:02 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include <mlx.h>
# include <math.h>

# define TILE 64
# define PLANEWIDTH 320
# define PLANEHEIGHT 200

enum	t_bool
{
	TRUE = 1,
	FALSE = 0
};

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
    t_pixel *pixel;
}   t_mlx;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	int		map_x;
	int		map_y;
	double	fov;
	int		height;
	int		speed;
	double	distance_to_plane;
}	t_player;

typedef struct s_plane
{
	double	width;
	double	height;
	double	center;
}	t_plane;

typedef struct s_ray
{
	double	angle;
	double x;
	double y;
}	t_ray;

typedef struct s_game
{
	t_player	*player;
	t_plane		*plane;
	t_ray		*ray;
	double		move_speed;
	double		rot_speed;
	t_mlx		*mlx;
}	t_game;

#endif