/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:39:33 by abaioumy          #+#    #+#             */
/*   Updated: 2023/01/14 13:13:05 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "draw.h"
#include "input.h"
#include <stdio.h>
#include <stdlib.h>

void	ft_check_horizontal( t_game *game )
{
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
	int	dof = 0;
	if (game->ray->angle > PI)
	{
		game->ray->y = floor(game->player->pos_y / TILE) * TILE - 1/*- 1*/;
		game->ray->x = (int)(game->player->pos_x - (game->player->pos_y - game->ray->y) / tan(game->ray->angle));
		game->ray->y_a = -TILE;
		game->ray->x_a = game->ray->y_a / tan(game->ray->angle);
		printf("x_a = %f, pl_a = %f ray_a = %f\n", game->ray->x_a, game->player->angle, game->ray->angle);
	}
	if (game->ray->angle < PI)
	{
		game->ray->y = floor(game->player->pos_y / TILE) * TILE + TILE /*+ TILE*/;
		game->ray->x = (int)(game->player->pos_x - (game->player->pos_y - game->ray->y) / tan(game->ray->angle));
		game->ray->y_a = TILE;
		game->ray->x_a = game->ray->y_a / tan(game->ray->angle);
		printf("x_a = %f, pl_a = %f ray_a = %f\n", game->ray->x_a, game->player->angle, game->ray->angle);
	}
	if (game->ray->angle == 0 || game->ray->angle == PI)
	{
		game->ray->x = game->player->pos_x;
		game->ray->y = game->player->pos_y;
		dof = 8;
	}
	while (dof < 8)
	{
		ft_draw_pixel(game, game->ray->x, game->ray->y, 0xff);
		ft_draw_pixel(game, game->ray->x + 1, game->ray->y, 0xff);
		ft_draw_pixel(game, game->ray->x, game->ray->y + 1, 0xff);
		ft_draw_pixel(game, game->ray->x + 1, game->ray->y + 1, 0xff);
		ft_draw_pixel(game, game->ray->x - 1, game->ray->y, 0xff);
		ft_draw_pixel(game, game->ray->x, game->ray->y - 1, 0xff);
		ft_draw_pixel(game, game->ray->x - 1, game->ray->y - 1, 0xff);

		int mx = (int)(game->ray->x / TILE);
		int my = (int)(game->ray->y / TILE);
		if (my < 0 || mx < 0)
			break ;
		if (my < 8 && mx < 8 && map[my][mx] == 1)
			dof = 8;
		else
		{
			game->ray->x += game->ray->x_a;
			game->ray->y += game->ray->y_a;
			dof += 1;
		}
		// draw a dot on the ray position 5px * 5px
	}
	if (game->ray->angle > PI)
		game->ray->y += 1;
	if (game->ray->x < 0 || game->ray->y < 0 || game->ray->x >= WIDTH || game->ray->y >= HEIGHT)
	{
		game->ray->x = game->player->pos_x;
		game->ray->y = game->player->pos_y;
	}
}

void	ft_check_vertical( t_game *game )
{
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
	int	dof = 0;
	if (game->ray->angle > PI / 2 && game->ray->angle < 3 * PI / 2)
	{
		game->ray->x = (int)(game->player->pos_x / TILE) * TILE - 0.0001;
		game->ray->y = (int)(game->player->pos_y + (game->player->pos_x - game->ray->x) * tan(game->ray->angle));
		game->ray->x_a = -64;
		game->ray->y_a = TILE * tan(game->ray->angle);
	}
	if (game->ray->angle < PI / 2 || game->ray->angle > 3 * PI / 2)
	{
		game->ray->x = (int)(game->player->pos_x / TILE) * TILE + TILE;
		game->ray->y = (int)(game->player->pos_y + (game->player->pos_x - game->ray->x) * tan(game->ray->angle));
		game->ray->x_a = TILE;
		game->ray->y_a = TILE * tan(game->ray->angle);
	}
	if (game->ray->angle == 0 || game->ray->angle == PI)
	{
		game->ray->x = game->player->pos_x;
		game->ray->y = game->player->pos_y;
		dof = 8;
	}
	while (dof < 8)
	{
		int mx = (int)(game->ray->x / TILE);
		int my = (int)(game->ray->y / TILE);
		if (mx < 8 && my < 8 && map[my][mx] == 1)
			dof = 8;
		else
		{
			game->ray->x += game->ray->x_a;
			game->ray->y += game->ray->y_a;
			dof += 1;
		}
	}
}

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
				ft_draw_square(x * TILE, y * TILE, game, ft_convert_rgb(228, 208, 10));
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
		game->ray->angle = game->player->angle;
		ft_check_horizontal(game);
		ft_draw_line_ddb(game->player->pos_x, game->player->pos_y, game->ray->x, game->ray->y, ft_convert_rgb(255, 0, 0), game);
		// ft_check_vertical(game);
		// ft_draw_line_ddb(game->player->pos_x, game->player->pos_y, game->ray->x, game->ray->y, ft_convert_rgb(255, 0, 0), game);
		i++;
	}
	mlx_put_image_to_window(game->mlx->init, game->mlx->window, game->mlx->pixel->image, 0, 0);
	mlx_destroy_image(game->mlx->init, game->mlx->pixel->image);
	return (0);
}