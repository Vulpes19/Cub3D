/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:39:33 by abaioumy          #+#    #+#             */
/*   Updated: 2023/01/12 18:42:15 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "draw.h"
#include "input.h"
#include <stdio.h>
#include <stdlib.h>

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
				ft_draw_square(x * TILE, y * TILE, game, ft_convert_rgb(228, 208, 10));
			}
			else
				ft_draw_square(x * TILE, y * TILE, game, ft_convert_rgb(255, 255, 255));
			x++;
		}
		y++;
	}
	ft_draw_point(game);
	int i = 0;
	while (i < 1)
	{
		int	tmp = 0;
		if (game->ray->angle > PI)
		{
			game->ray->y = (int)(game->player->pos_y / 64) * 64 - 0.0001;
			game->ray->x = game->player->pos_x + (game->player->pos_y - game->ray->y) / tan(game->ray->angle);
			game->ray->y_a = -64;
			game->ray->x_a = 64 / tan(game->ray->angle);
		}
		if (game->ray->angle < PI)
		{
			game->ray->y = (int)(game->player->pos_y / 64) * 64 + 64;
			game->ray->x = game->player->pos_x + (game->player->pos_y - game->ray->y) / tan(game->ray->angle);
			game->ray->y_a = 64;
			game->ray->x_a = 64 / tan(game->ray->angle);
		}
		if (game->ray->angle == 0 || game->ray->angle == PI)
		{
			game->ray->x = game->player->pos_x;
			game->ray->y = game->player->pos_y;
			tmp = 8;
		}
		while (tmp < 8)
		{
			int mx = (int)(game->ray->x / 64);
			int my = (int)(game->ray->y / 64);
			if (my < 8 && mx < 8 && map[my][mx] == 1)
				tmp = 8;
			else
			{
				game->ray->x += game->ray->x_a;
				game->ray->y += game->ray->y_a;
			}
		}
		i++;
		ft_draw_line_ddb(game->player->pos_x, game->player->pos_y, game->ray->x, game->ray->y, ft_convert_rgb(255, 0, 0), game);
	}
	mlx_put_image_to_window(game->mlx->init, game->mlx->window, game->mlx->pixel->image, 0, 0);
	mlx_destroy_image(game->mlx->init, game->mlx->pixel->image);
	return (0);
}