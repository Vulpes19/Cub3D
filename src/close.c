/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:47:14 by abaioumy          #+#    #+#             */
/*   Updated: 2023/01/19 11:12:28 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "close.h"

int	ft_close_esc(int keycode, t_game *game)
{
	if (keycode == ESC)
	{
		free(game->mlx->window);
		free(game->mlx->init);
		// mlx_destroy_image(mlx->init, mlx->pixel->image);
		// mlx_clear_window(mlx->init, mlx->window);
		system("leaks cub3D");
		exit(0);
	}
	return (0);
}

int ft_close_x(t_mlx *mlx)
{
	free(mlx->window);
	free(mlx->init);
	// mlx_clear_window(mlx->init, mlx->window);
	system("leaks cub3D");
	exit(0);
	return (0);
}