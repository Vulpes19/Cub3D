/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:47:14 by abaioumy          #+#    #+#             */
/*   Updated: 2023/01/11 17:38:04 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "close.h"

int	ft_close_esc(int keycode, t_mlx *mlx)
{
	if (keycode == ESC)
	{
		free(mlx->window);
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
	// mlx_clear_window(mlx->init, mlx->window);
	system("leaks cub3D");
	exit(0);
	return (0);
}