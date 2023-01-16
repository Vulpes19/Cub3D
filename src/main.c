/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:14:17 by abaioumy          #+#    #+#             */
/*   Updated: 2023/01/16 18:12:06 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <limits.h>
#include <stdio.h>
#include "game.h"
#include "draw.h"
#include "close.h"
#include "error.h"
#include "input.h"

int	main(void)
{
	t_game		*game;

	game = (t_game *)malloc(sizeof(t_game));
	game->mlx = (t_mlx*)malloc(sizeof(t_mlx));
	game->mlx->pixel = (t_pixel *)malloc(sizeof(t_pixel));
	game->player = (t_player *)malloc(sizeof(t_player));
	game->ray = (t_ray *)malloc(sizeof(t_ray));
	game->wall = (t_wall *)malloc(sizeof(t_wall) * WIDTH);
	game->texture = (t_texture *)malloc(sizeof(t_texture));
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
	game->ray->angle = game->player->angle /*- (game->player->fov / 2)*/;
	
	if (!game->mlx->init)
	{
		ft_putstr_fd("failed to init mlx", STDERR_FILENO);
		exit(1);
	}
	game->mlx->window = mlx_new_window(game->mlx->init, WIDTH, HEIGHT, "still thinking of a name");
	if (!game->mlx->window)
	{
		ft_putstr_fd("failed to create window", STDERR_FILENO);
		exit(1);
	}
	mlx_hook(game->mlx->window, 17, 1L << 0, ft_close_x, game);
	// mlx_loop_hook(game->mlx->init, ft_raycasting, game);
	mlx_hook(game->mlx->window, 2, 1L << 0, ft_input_handler, game);
	// mlx_hook(game->mlx->window, 2, 1L << 0, ft_close_esc, game);
	// mlx_key_hook(game->mlx->window, ft_input_handler, game);
	ft_raycasting(game);
	mlx_loop(game->mlx->init);
}