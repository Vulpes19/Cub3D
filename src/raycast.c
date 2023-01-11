/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:39:33 by abaioumy          #+#    #+#             */
/*   Updated: 2023/01/11 16:39:03 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "draw.h"
#include "input.h"
#include <stdio.h>

int    ft_raycasting(t_game *game)
{
	int	x;
	int	y;
	int	map[8][8] =
	{
		{1,1,1,1,1,1,1,1},
		{1,0,0,0,1,0,0,1},
		{1,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,1},
		{1,0,0,0,1,1,1,1},
		{1,0,0,0,1,0,0,1},
		{1,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1}
	};

	x = 0;
	y = 0;
	game->mlx->pixel->image = mlx_new_image(game->mlx->init, WIDTH, HEIGHT);
	game->mlx->pixel->address = mlx_get_data_addr(game->mlx->pixel->image, &game->mlx->pixel->bits_per_pixel, &game->mlx->pixel->line_len, &game->mlx->pixel->endian);
	while (y < 8)
	{
		x = 0;
		while (x < 8)
		{
			if(map[y][x] == 1)
			{
				ft_draw_square(x * 64, y * 64, game, ft_convert_rgb(228, 208, 10));
			}
			else
				ft_draw_square(x * 64, y * 64, game, ft_convert_rgb(255, 255, 255));
			x++;
		}
		y++;
	}
	ft_draw_point(game);
	mlx_put_image_to_window(game->mlx->init, game->mlx->window, game->mlx->pixel->image, 0, 0);
	mlx_destroy_image(game->mlx->init, game->mlx->pixel->image);
	return (0);
}