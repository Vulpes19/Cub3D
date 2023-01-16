/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:39:33 by abaioumy          #+#    #+#             */
/*   Updated: 2023/01/16 18:22:06 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "draw.h"
#include "input.h"
#include <stdio.h>
#include <stdlib.h>

void	ft_horizontal_intersections(t_game *game)
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

void	ft_vertical_intersections(t_game *game)
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
	int	color_north = 0xE072A4;
	int color_south = 0xDE689D;
	int color_east = 0x9C4D8C;
	int color_west = 0x6C3B7B;
	game->mlx->pixel->image = mlx_new_image(game->mlx->init, WIDTH, HEIGHT);
	game->mlx->pixel->address = mlx_get_data_addr(game->mlx->pixel->image, &game->mlx->pixel->bits_per_pixel, &game->mlx->pixel->line_len, &game->mlx->pixel->endian);
	// game->mlx->mini_map->image = mlx_new_image(game->mlx->init, 100, 100);
	// game->mlx->mini_map->address = mlx_get_data_addr(game->mlx->mini_map->image, &game->mlx->mini_map->bits_per_pixel, &game->mlx->mini_map->line_len, &game->mlx->mini_map->endian);
	// ft_load_textures(game);
	//grid drawing
	// ft_draw_grid(game);

	//player
	// ft_draw_point(game);
	int ray = 0;

	//intersection loop
	while (ray < WIDTH)
	{
		game->ray->distance_h = 1000000;
		game->ray->distance_v = 1000000;
		game->ray->angle = game->player->angle - (game->player->half_fov) + (game->player->half_fov * 2) * ray / WIDTH;
		if (game->ray->angle < 0)
			game->ray->angle += 2 * PI;
		if (game->ray->angle > 2 * PI)
			game->ray->angle -= 2 * PI;
		game->ray->h_pos_x = game->player->pos_x;
		game->ray->h_pos_y = game->player->pos_y;
		ft_horizontal_intersections(game);
		game->ray->v_pos_x = game->player->pos_x;
		game->ray->v_pos_y = game->player->pos_y;
		ft_vertical_intersections(game);
		game->wall[ray].color = color_north;
		if (game->ray->distance_h < game->ray->distance_v)
		{
			printf("I'm horizontal\n");
			game->ray->x = (int)game->ray->h_pos_x;
			game->ray->y = (int)game->ray->h_pos_y;
			game->ray->distance = game->ray->distance_h * cos(game->player->angle - game->ray->angle);
			if (game->ray->angle > 0 && game->ray->angle < PI)
				game->wall[ray].color = color_south;
			else if (game->player->angle > PI && game->player->angle < 2 * PI)
				game->wall[ray].color = color_north;
			// else if (game->player->angle < PI / 2 || game->player->angle > 3 * PI / 2)
			// game->wall[ray].color = color1;
		}
		if (game->ray->distance_h > game->ray->distance_v)
		{
			printf("I'm vertical\n");
			game->ray->x = (int)game->ray->v_pos_x;
			game->ray->y = (int)game->ray->v_pos_y;
			game->ray->distance = game->ray->distance_v * cos(game->player->angle - game->ray->angle);
			if (game->ray->angle > PI / 2 && game->ray->angle < 3 * PI / 2)
				game->wall[ray].color = color_east;
			else if (game->player->angle < PI / 2 || game->player->angle > 3 * PI / 2)
				game->wall[ray].color = color_west;
			// else if (game->player->angle > PI && game->player->angle < 2 * PI)
			// game->wall[ray].color = color2;
		}
		// ft_draw_line_ddb(game->player->pos_x, game->player->pos_y, game->ray->x, game->ray->y, ft_convert_rgb(0, 0, 0), game);
		game->wall[ray].height = (TILE / game->ray->distance) * 277;;
		game->wall[ray].offset = (game->wall[ray].height * TILE) / (2 * game->ray->distance);
		game->wall[ray].begin_draw = -game->wall[ray].height / 2 + HEIGHT / 2;;
		ray++;
		game->ray->angle += game->player->fov / WIDTH;
		if (game->ray->angle < 0)
			game->ray->angle += 2 * PI;
		if (game->ray->angle > 2 * PI)
			game->ray->angle -= 2 * PI;
	}
	ft_draw_walls(game);
	//direction line
	// ft_draw_line_ddb(game->player->pos_x, game->player->pos_y,game->player->pos_x +  cos(game->player->angle) * 50,game->player->pos_y +  sin(game->player->angle) * 50 , ft_convert_rgb(00, 0xff, 00), game);
	
	mlx_put_image_to_window(game->mlx->init, game->mlx->window, game->mlx->pixel->image, 0, 0);
	// mlx_put_image_to_window(game->mlx->init, game->mlx->window, game->mlx->mini_map->image, 0, 0);
	mlx_destroy_image(game->mlx->init, game->mlx->pixel->image);
	// mlx_destroy_image(game->mlx->init, game->mlx->mini_map->image);
	return (0);
}