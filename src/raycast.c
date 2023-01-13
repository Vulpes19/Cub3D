/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:39:33 by abaioumy          #+#    #+#             */
/*   Updated: 2023/01/13 19:29:05 by abaioumy         ###   ########.fr       */
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
	int	tmp = 0;
	if (game->ray->angle > PI)
	{
		game->ray->y = (int)(game->player->pos_y / TILE) * TILE - 0.0001;
		game->ray->x = (int)(game->player->pos_x + (game->player->pos_y - game->ray->y) / tan(game->ray->angle));
		game->ray->y_a = -64;
		game->ray->x_a = TILE / tan(game->ray->angle);
	}
	if (game->ray->angle < PI)
	{
		game->ray->y = (int)(game->player->pos_y / TILE) * TILE + TILE;
		game->ray->x = (int)(game->player->pos_x + (game->player->pos_y - game->ray->y) / tan(game->ray->angle));
		game->ray->y_a = TILE;
		game->ray->x_a = TILE / tan(game->ray->angle);
	}
	if (game->ray->angle == 0 || game->ray->angle == PI)
	{
		game->ray->x = game->player->pos_x;
		game->ray->y = game->player->pos_y;
		tmp = 8;
	}
	while (tmp < 8)
	{
		int mx = (int)(game->ray->x / TILE);
		int my = (int)(game->ray->y / TILE);
		printf("mx = %d, my = %d\n", mx, my);
		if (my < 8 && mx < 8 && map[my][mx] == 1)
			tmp = 8;
		else
		{
			game->ray->x += game->ray->x_a;
			game->ray->y += game->ray->y_a;
			tmp += 1;
		}
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
		game->ray->x_a = -TILE;
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
		printf("mx = %d, my = %d\n", mx, my);
		if (mx < 8 && my < 8 && map[my][mx] == 1)
			dof = 8;
		else
		{
			game->ray->x += game->ray->x_a;
			game->ray->y += game->ray->y_a;
			dof += 1;
		}
	}
	ft_draw_line_ddb(game->player->pos_x, game->player->pos_y, game->ray->x, game->ray->y, ft_convert_rgb(255, 0, 0), game);
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
	// printf("pos_x: %f\npos_y: %f\nrot_x: %f\nrot_y: %f\n", game->player->pos_x, game->player->pos_y, game->player->rot_x, game->player->rot_y);
	int i = 0;
	while (i < 1)
	{
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