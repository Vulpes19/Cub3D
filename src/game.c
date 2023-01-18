/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:43:13 by abaioumy          #+#    #+#             */
/*   Updated: 2023/01/18 18:27:54 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "draw.h"

void    ft_allocate_game(t_game *game)
{
	game->mlx = (t_mlx *)malloc(sizeof(t_mlx));
	game->mlx->pixel = (t_pixel *)malloc(sizeof(t_pixel));
	game->mlx->mini_map = (t_pixel *)malloc(sizeof(t_pixel));
	game->player = (t_player *)malloc(sizeof(t_player));
	game->ray = (t_ray *)malloc(sizeof(t_ray));
	game->wall = (t_wall *)malloc(sizeof(t_wall) * WIDTH);
	game->texture = (t_texture *)malloc(sizeof(t_texture));
}

void    ft_init_game(t_game *game)
{
    game->mlx->init = mlx_init();
	game->player->pos_x = 100;
	game->player->pos_y = 160;
	game->player->angle = 0;
	game->player->rot_x = cos(game->player->angle) * 5;
	game->player->rot_y = sin(game->player->angle) * 5;
	game->player->fov = 60 * (PI / 180);
	game->player->half_fov = game->player->fov / 2;
	game->player->height = 32;
	game->player->speed = 16;
	game->ray->angle = game->player->angle;
    // game->ray->distance_h = 1000000;
	// game->ray->distance_v = 1000000;
}
