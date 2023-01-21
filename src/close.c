/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:47:14 by abaioumy          #+#    #+#             */
/*   Updated: 2023/01/21 14:21:46 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "close.h"

void	ft_close_esc(t_game *game)
{
	free(game->mlx->window);
	free(game->mlx->init);
	system("leaks cub3D");
	exit(0);
}

int	ft_close_x(t_mlx *mlx)
{
	free(mlx->window);
	free(mlx->init);
	system("leaks cub3D");
	exit(0);
	return (0);
}
