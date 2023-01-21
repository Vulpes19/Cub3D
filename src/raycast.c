/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:39:33 by abaioumy          #+#    #+#             */
/*   Updated: 2023/01/21 18:43:13 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "draw.h"
#include "input.h"
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

void	ft_load_images(t_game *game)
{
	game->mlx->pixel->image = mlx_new_image(game->mlx->init, WIDTH, HEIGHT);
	game->mlx->mini_map->image = mlx_new_image(game->mlx->init, 250, 250);
	game->mlx->pixel->address = mlx_get_data_addr(game->mlx->pixel->image, &game->mlx->pixel->bits_per_pixel, &game->mlx->pixel->line_len, &game->mlx->pixel->endian);
	game->mlx->mini_map->address = mlx_get_data_addr(game->mlx->mini_map->image, &game->mlx->mini_map->bits_per_pixel, &game->mlx->mini_map->line_len, &game->mlx->mini_map->endian);
}

void	ft_render(t_game *game)
{
	ft_draw_walls(game);
	mlx_put_image_to_window(game->mlx->init, game->mlx->window, game->mlx->pixel->image, 0, 0);
	mlx_put_image_to_window(game->mlx->init, game->mlx->window, game->mlx->mini_map->image, 10, 10);
	mlx_destroy_image(game->mlx->init, game->mlx->pixel->image);
	mlx_destroy_image(game->mlx->init, game->mlx->mini_map->image);
}

int    ft_raycasting(t_game *game)
{
	int ray;
	int	color_north = 0xE072A4;
	int color_south = 0xDE689D;
	int color_east = 0x9C4D8C;
	int color_west = 0x6C3B7B;
	
	ray = 0;
	ft_load_images(game);
	ft_load_texture(game);
	ft_draw_grid(game);
	while (ray < WIDTH)
	{
		game->ray->distance_h = 100000;
		game->ray->distance_v = 100000;
		game->ray->angle = game->player->angle - (game->player->half_fov) + (game->player->fov) * ray / WIDTH;
		if (game->ray->angle < 0)
			game->ray->angle += 2 * PI;
		if (game->ray->angle > 2 * PI)
			game->ray->angle -= 2 * PI;
		// ft_PI_angle(game);
		game->ray->h_pos_x = game->player->pos_x;
		game->ray->h_pos_y = game->player->pos_y;
		ft_horizontal_intersections(game);
		game->ray->v_pos_x = game->player->pos_x;
		game->ray->v_pos_y = game->player->pos_y;
		ft_vertical_intersections(game);
		game->wall[ray].color = color_north;
		game->wall[ray].tex_x = game->ray->x;
		game->wall[ray].tex_y = game->ray->y;
		if (game->ray->distance_h < game->ray->distance_v)
		{
			// printf("I'm horizontal\n");
			game->ray->x = (int)game->ray->h_pos_x;
			game->ray->y = (int)game->ray->h_pos_y;
			game->wall[ray].tex_x = game->ray->x;
			game->wall[ray].tex_y = game->ray->y;
			game->wall[ray].is_horizontal = TRUE;
			game->wall[ray].is_vertical = FALSE;
			game->ray->distance = game->ray->distance_h * cos(game->player->angle - game->ray->angle);
			if (game->ray->angle > 0 && game->ray->angle < PI)
				game->wall[ray].color = color_south;
			else if (game->player->angle > PI && game->player->angle < 2 * PI)
				game->wall[ray].color = color_north;
		}
		if (game->ray->distance_h > game->ray->distance_v)
		{
			// printf("I'm vertical\n");
			game->ray->x = (int)game->ray->v_pos_x;
			game->ray->y = (int)game->ray->v_pos_y;
			game->wall[ray].tex_x = game->ray->x;
			game->wall[ray].tex_y = game->ray->y;
			game->wall[ray].is_horizontal = FALSE;
			game->wall[ray].is_vertical = TRUE;
			game->ray->distance = game->ray->distance_v * cos(game->player->angle - game->ray->angle);
			if (game->ray->angle > PI / 2 && game->ray->angle < 3 * PI / 2)
				game->wall[ray].color = color_east;
			else if (game->player->angle < PI / 2 || game->player->angle > 3 * PI / 2)
				game->wall[ray].color = color_west;
		}
		// ft_draw_line_ddb(game->player->pos_x - (250 / 2), game->player->pos_y - (250 / 2), game->ray->x - (250 / 2), game->ray->y - (250 / 2), ft_convert_rgb(255, 0, 0), game);
		game->wall[ray].height = (TILE / game->ray->distance) * 300;
		game->wall[ray].begin_draw = -game->wall[ray].height / 2 + HEIGHT / 2;
		ray++;
		game->ray->angle += game->player->fov / WIDTH;
		if (game->ray->angle < 0)
			game->ray->angle += 2 * PI;
		if (game->ray->angle > 2 * PI)
			game->ray->angle -= 2 * PI;
	}
	// ft_draw_line_ddb(game->player->pos_x, game->player->pos_y,game->player->pos_x +  cos(game->player->angle) * 50,game->player->pos_y +  sin(game->player->angle) * 50 , ft_convert_rgb(00, 0xff, 00), game);
	ft_render(game);
	return (0);
}


