/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:39:33 by abaioumy          #+#    #+#             */
/*   Updated: 2023/01/15 17:13:07 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "draw.h"
#include "input.h"
#include <stdio.h>
#include <stdlib.h>

void	ft_check_horizontal(t_game *game)
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
		game->ray->y = floor(game->player->pos_y / TILE) * TILE - 0.0001;
		game->ray->x = game->player->pos_x - (game->player->pos_y - game->ray->y) / tan(game->ray->angle);
		game->ray->y_a = -TILE;
		game->ray->x_a = game->ray->y_a / tan(game->ray->angle);
	}
	if (game->ray->angle < PI)
	{
		game->ray->y = floor(game->player->pos_y / TILE) * TILE + TILE;
		game->ray->x = game->player->pos_x - (game->player->pos_y - game->ray->y) / tan(game->ray->angle);
		game->ray->y_a = TILE;
		game->ray->x_a = game->ray->y_a / tan(game->ray->angle);
	}
	if (game->ray->angle == 0 || game->ray->angle == PI)
	{
		game->ray->x = game->player->pos_x;
		game->ray->y = game->player->pos_y;
		dof = 8;
	}
	while (dof < 8)
	{
		// ft_draw_pixel(game, game->ray->x, game->ray->y, 0xff);
		// ft_draw_pixel(game, game->ray->x + 1, game->ray->y, 0xff);
		// ft_draw_pixel(game, game->ray->x, game->ray->y + 1, 0xff);
		// ft_draw_pixel(game, game->ray->x + 1, game->ray->y + 1, 0xff);
		// ft_draw_pixel(game, game->ray->x - 1, game->ray->y, 0xff);
		// ft_draw_pixel(game, game->ray->x, game->ray->y - 1, 0xff);
		// ft_draw_pixel(game, game->ray->x - 1, game->ray->y - 1, 0xff);

		int mx = (int)(game->ray->x / TILE);
		int my = (int)(game->ray->y / TILE);
		if (my < 0 || mx < 0)
			break ;
		if (my < 8 && mx < 8 && map[my][mx] == 1)
		{
			game->ray->h_pos_x = game->ray->x;
			game->ray->h_pos_y = game->ray->y;
			game->ray->distance_h = ft_distance(game->player->pos_x, game->player->pos_y, game->ray->x, game->ray->y);
			dof = 8;
		}
		else
		{
			game->ray->x += game->ray->x_a;
			game->ray->y += game->ray->y_a;
			dof += 1;
		}
	}
}

void	ft_check_vertical(t_game *game)
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
		game->ray->x = floor(game->player->pos_x / TILE) * TILE - 0.0001;
		game->ray->y = game->player->pos_y + (game->ray->x - game->player->pos_x) * tan(game->ray->angle);
		game->ray->x_a = -64;
		game->ray->y_a = game->ray->x_a * tan(game->ray->angle);
	}
	if (game->ray->angle < PI / 2 || game->ray->angle > 3 * PI / 2)
	{
		game->ray->x = floor(game->player->pos_x / TILE) * TILE + TILE;
		game->ray->y = game->player->pos_y - (game->player->pos_x - game->ray->x) * tan(game->ray->angle);
		game->ray->x_a = TILE;
		game->ray->y_a = game->ray->x_a * tan(game->ray->angle);
	}
	if (game->ray->angle == 0 || game->ray->angle == PI)
	{
		game->ray->x = game->player->pos_x;
		game->ray->y = game->player->pos_y;
		dof = 8;
	}
	while (dof < 8)
	{
		// ft_draw_pixel(game, game->ray->x, game->ray->y, 0xff);
		// ft_draw_pixel(game, game->ray->x + 1, game->ray->y, 0xff);
		// ft_draw_pixel(game, game->ray->x, game->ray->y + 1, 0xff);
		// ft_draw_pixel(game, game->ray->x + 1, game->ray->y + 1, 0xff);
		// ft_draw_pixel(game, game->ray->x - 1, game->ray->y, 0xff);
		// ft_draw_pixel(game, game->ray->x, game->ray->y - 1, 0xff);
		// ft_draw_pixel(game, game->ray->x - 1, game->ray->y - 1, 0xff);
		int mx = (int)(game->ray->x / TILE);
		int my = (int)(game->ray->y / TILE);
		if (my < 0 || mx < 0)
			break ;
		if (mx < 8 && my < 8 && map[my][mx] == 1)
		{
			game->ray->v_pos_x = game->ray->x;
			game->ray->v_pos_y = game->ray->y;
			game->ray->distance_v = ft_distance(game->player->pos_x, game->player->pos_y, game->ray->x, game->ray->y);
			dof = 8;
		}
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
	game->mlx->pixel->image = mlx_new_image(game->mlx->init, WIDTH, HEIGHT);
	game->mlx->pixel->address = mlx_get_data_addr(game->mlx->pixel->image, &game->mlx->pixel->bits_per_pixel, &game->mlx->pixel->line_len, &game->mlx->pixel->endian);
	
	//grid drawing
	// ft_draw_grid(game);

	//player
	// ft_draw_point(game);
	int i = 0;

	//intersection loop
	while (i < WIDTH)
	{
		game->ray->distance_h = 1000000;
		game->ray->distance_v = 1000000;
		game->ray->angle = game->player->angle - (game->player->half_fov) + (game->player->half_fov * 2) * i / WIDTH;
		if (game->ray->angle < 0)
			game->ray->angle += 2 * PI;
		if (game->ray->angle > 2 * PI)
			game->ray->angle -= 2 * PI;
		game->ray->h_pos_x = game->player->pos_x;
		game->ray->h_pos_y = game->player->pos_y;
		ft_check_horizontal(game);
		game->ray->v_pos_x = game->player->pos_x;
		game->ray->v_pos_y = game->player->pos_y;
		ft_check_vertical(game);
		if (game->ray->distance_h < game->ray->distance_v)
		{
			// printf("I'm horizontal\n");
			game->ray->x = (int)game->ray->h_pos_x;
			game->ray->y = (int)game->ray->h_pos_y;
			game->ray->distance = game->ray->distance_h * cos(game->player->angle - game->ray->angle);
		}
		if (game->ray->distance_h > game->ray->distance_v)
		{
			// printf("I'm vertical\n");
			game->ray->x = (int)game->ray->v_pos_x;
			game->ray->y = (int)game->ray->v_pos_y;
			game->ray->distance = game->ray->distance_v * cos(game->player->angle - game->ray->angle);
		}
		// ft_draw_line_ddb(game->player->pos_x, game->player->pos_y, game->ray->x, game->ray->y, ft_convert_rgb(0, 0, 0), game);
		game->wall[i].height = (TILE / game->ray->distance) * 277;;
		game->wall[i].begin_draw = -game->wall[i].height / 2 + HEIGHT / 2;;
		i++;
		// game->ray->angle += RADIAN * 6;
		game->ray->angle += game->player->fov / WIDTH;
		if (game->ray->angle < 0)
			game->ray->angle += 2 * PI;
		if (game->ray->angle > 2 * PI)
			game->ray->angle -= 2 * PI;
	}
	i = 0;
	int wall_width;
	while (i < WIDTH)
	{
		wall_width = 2;
		ft_draw_rectangle(i, game->wall[i].begin_draw, wall_width, game->wall[i].height, ft_convert_rgb(255,160,122), game);
		i++;
	}
	//direction line
	// ft_draw_line_ddb(game->player->pos_x, game->player->pos_y,game->player->pos_x +  cos(game->player->angle) * 50,game->player->pos_y +  sin(game->player->angle) * 50 , ft_convert_rgb(00, 0xff, 00), game);
	
	mlx_put_image_to_window(game->mlx->init, game->mlx->window, game->mlx->pixel->image, 0, 0);
	mlx_destroy_image(game->mlx->init, game->mlx->pixel->image);
	return (0);
}