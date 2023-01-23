/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:47:14 by abaioumy          #+#    #+#             */
/*   Updated: 2023/01/23 12:05:42 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "close.h"

void	ft_free_textures(t_game *game)
{
	int		i;

	i = 0;
	while (i < WIDTH)
	{
		free(game->wall[i].texture);
		i++;
	}
}

void	ft_free_game(t_game *game)
{
	free(game->mlx->window);
	free(game->mlx->init);
	free(game->mlx);
	free(game->player);
	free(game->ray);
	ft_free_textures(game);
	free(game->wall);
	free(game->texture_north);
	free(game->texture_south);
	free(game->texture_east);
	free(game->texture_west);
	free(game);
}

void	ft_close_esc(t_game *game)
{
	ft_free_game(game);
	system("leaks cub3D");
	exit(0);
}

int	ft_close_x(t_game *game)
{
	ft_free_game(game);
	system("leaks cub3D");
	exit(0);
	return (0);
}
