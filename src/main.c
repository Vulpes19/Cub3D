/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:14:17 by abaioumy          #+#    #+#             */
/*   Updated: 2023/01/17 18:42:44 by abaioumy         ###   ########.fr       */
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
	ft_allocate_game(game);
	ft_init_game(game);
	if (!game->mlx->init)
	{
		ft_putstr_fd("failed to init mlx\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	game->mlx->window = mlx_new_window(game->mlx->init, WIDTH, HEIGHT, "still thinking of a name");
	if (!game->mlx->window)
	{
		ft_putstr_fd("failed to create window\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	mlx_hook(game->mlx->window, 17, 1L << 0, ft_close_x, game);
	mlx_hook(game->mlx->window, 2, 1L << 0, ft_input_handler, game);
	ft_raycasting(game);
	mlx_loop(game->mlx->init);
}