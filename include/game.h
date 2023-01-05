/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:25:47 by abaioumy          #+#    #+#             */
/*   Updated: 2023/01/05 17:49:34 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include <mlx.h>
# include <math.h>


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
	double	x;
	double	y;
	double		pos_x;
	double		pos_y;
}	t_player;

typedef struct s_camera
{
	double	plane_x;
	double	plane_y;
	double	camera_x;
}	t_camera;

typedef struct s_ray
{
	double x;
	double y;
}	t_ray;

typedef struct s_game
{
	int			map[24][24];
	t_player	*player;
	t_camera	*camera;
	t_ray		*ray;
	double		move_speed;
	double		rot_speed;
	t_mlx		*mlx;
}	t_game;

#endif