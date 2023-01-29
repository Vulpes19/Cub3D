/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:39:33 by abaioumy          #+#    #+#             */
/*   Updated: 2023/01/29 20:43:07 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "draw.h"
#include "input.h"
#include "close.h"
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

void	ft_load_images(t_game *game)
{
	game->mlx->pixel->image = mlx_new_image(game->mlx->init, WIDTH, HEIGHT);
	if (!game->mlx->pixel->image)
	{
		ft_putstr_fd("failed to load image\n", STDERR_FILENO);
		ft_close(game);
	}
	game->mlx->pixel->address = mlx_get_data_addr(game->mlx->pixel->image,
			&game->mlx->pixel->bits_per_pixel,
			&game->mlx->pixel->line_len, &game->mlx->pixel->endian);
}

void	ft_render(t_game *game)
{
	mlx_put_image_to_window(game->mlx->init, game->mlx->window,
		game->mlx->pixel->image, 0, 0);
	mlx_put_image_to_window(game->mlx->init, game->mlx->window,
		game->gun, WIDTH / 2 + 59, 210);
	mlx_destroy_image(game->mlx->init, game->mlx->pixel->image);
}

void	ft_raycasting_loop(t_game *game, int ray)
{
	ft_horizontal_intersections(game);
	ft_vertical_intersections(game);
	game->wall[ray].texture->image = game->texture_north->image;
	game->wall[ray].tex_x = game->ray->x;
	game->wall[ray].tex_y = game->ray->y;
	ft_compare_distances(game, ray);
	game->wall[ray].height = (TILE / game->ray->distance) * 500;
	game->wall[ray].begin_draw = HEIGHT / 2 - game->wall[ray].height / 2;
	ft_draw_walls(game, ray);
	game->ray->angle += game->player->fov / WIDTH;
}

int	ft_raycasting(t_game *game)
{
	int	ray;

	ray = 0;
	ft_load_images(game);
	while (ray < WIDTH)
	{
		game->ray->distance_h = 100000;
		game->ray->distance_v = 100000;
		game->ray->angle = game->player->angle - (game->player->half_fov)
			+ (game->player->fov) * ray / WIDTH;
		if (game->ray->angle < 0)
			game->ray->angle += 2 * PI;
		if (game->ray->angle > 2 * PI)
			game->ray->angle -= 2 * PI;
		ft_raycasting_loop(game, ray);
		ray++;
		if (game->ray->angle < 0)
			game->ray->angle += 2 * PI;
		if (game->ray->angle > 2 * PI)
			game->ray->angle -= 2 * PI;
	}
	ft_render(game);
	return (0);
}
