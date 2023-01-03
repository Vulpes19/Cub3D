/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:39:33 by abaioumy          #+#    #+#             */
/*   Updated: 2023/01/03 12:48:17 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "window.h"
#include "draw.h"

void    ft_raycasting(t_game *game, t_mlx *mlx, t_pixel *pixel)
{
	int	x;

	x = 0;
	while (x < WIDTH)
	{
		game->camera.camera_x = 2 * x / (double)WIDTH - 1;
		game->ray.ray_x = game->player.dir_x + game->camera.plane_x * game->camera.camera_x;
		game->ray.ray_y = game->player.dir_y + game->camera.plane_y * game->camera.camera_x;
	}
}