/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:14:17 by abaioumy          #+#    #+#             */
/*   Updated: 2023/01/05 17:14:38 by abaioumy         ###   ########.fr       */
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
	t_mlx		*mlx;
	t_game		*game;

	mlx = (t_mlx*)malloc(sizeof(t_mlx));
	mlx->pixel = (t_pixel *)malloc(sizeof(t_pixel));
	game = (t_game *)malloc(sizeof(t_game));
	game->player = (t_player *)malloc(sizeof(t_player));
	game->camera = (t_player *)malloc(sizeof(t_player));
	game->ray = (t_player *)malloc(sizeof(t_player));
	game->player->pos_x = 22;
	game->player->pos_y = 12;
	game->player->x = -1;
	game->player->y = 0;
	game->camera->plane_x = 0;
	game->camera->plane_y = 0.66;
	mlx->init = mlx_init();
	if (!mlx->init)
	{
		ft_putstr_fd("failed to init mlx", STDERR_FILENO);
		exit(1);
	}
	mlx->window = mlx_new_window(mlx->init, WIDTH, HEIGHT, "still thinking of a name");
	if (!mlx->window)
	{
		ft_putstr_fd("failed to create window", STDERR_FILENO);
		exit(1);
	}
	// pixel.address = mlx_get_data_addr(pixel.image, &pixel.bits_per_pixel, &pixel.line_len, &pixel.endian);
	// ft_draw_pixel(&pixel, 5, 5, 0x00FF0000);
	// mlx_put_image_to_window(mlx.init, mlx.window, pixel.image, 0, 0);
	mlx_hook(mlx->window, 17, 1L << 0, ft_close_x, &mlx);
	mlx_hook(mlx->window, 2, 1L << 0, ft_close_esc, &mlx);
	mlx_loop_hook(mlx->init, ft_raycasting, &game);
	mlx_loop(mlx->init);
}