/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:14:17 by abaioumy          #+#    #+#             */
/*   Updated: 2023/01/05 17:51:10 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <limits.h>
#include <stdio.h>
#include "game.h"
#include "draw.h"
#include "close.h"
#include "error.h"

int	main(void)
{
	t_game		*game;

	game = (t_game *)malloc(sizeof(t_game));
	game->mlx = (t_mlx*)malloc(sizeof(t_mlx));
	game->mlx->pixel = (t_pixel *)malloc(sizeof(t_pixel));
	game->player = (t_player *)malloc(sizeof(t_player));
	game->camera = (t_camera *)malloc(sizeof(t_camera));
	game->ray = (t_ray *)malloc(sizeof(t_ray));
	game->player->pos_x = 22;
	game->player->pos_y = 12;
	game->player->x = -1;
	game->player->y = 0;
	game->camera->plane_x = 0;
	game->camera->plane_y = 0.66;
	game->move_speed = 5.0;
	game->rot_speed = 3.0;
	game->mlx->init = mlx_init();
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
	mlx_hook(game->mlx->window, 2, 1L << 0, ft_close_esc, game);
	mlx_loop_hook(game->mlx->init, ft_raycasting, game);
    // mlx_destroy_image(mlx->init, mlx->pixel->image);
	mlx_loop(game->mlx->init);
}