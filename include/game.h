/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:25:47 by abaioumy          #+#    #+#             */
/*   Updated: 2023/01/03 12:38:58 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

#include <mlx.h>

typedef struct	s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
}	t_player;

typedef struct	s_camera
{
	double	plane_x;
	double	plane_y;
	double	camera_x;
}	t_camera;

typedef	struct s_ray
{
	double	ray_x;
	double	ray_y;
}	t_ray;

typedef	struct s_game
{
	t_player	player;
	t_camera	camera;
	t_ray		ray;
}	t_game;


#endif