/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:47:14 by abaioumy          #+#    #+#             */
/*   Updated: 2023/01/25 18:58:12 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "close.h"
#include "parser.h"

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
	free(game->mlx->pixel);
	free(game->mlx->mini_map);
	free(game->mlx);
	free(game->player);
	free(game->ray);
	ft_free_textures(game);
	free(game->wall);
	free(game->texture_north);
	free(game->texture_south);
	free(game->texture_east);
	free(game->texture_west);
	ft_free_map_error(game->data);
	free(game);
	system("leaks cub3D");
	exit(EXIT_SUCCESS);
}

void	ft_close_esc(t_game *game)
{
	ft_free_game(game);
	system("leaks cub3D");
	exit(EXIT_SUCCESS);
}

int	ft_close_x(t_game *game)
{
	ft_free_game(game);
	system("leaks cub3D");
	exit(EXIT_SUCCESS);
	return (0);
}

void	ft_close(t_game *game)
{
	ft_free_game(game);
	system("leaks cub3D");
	exit(EXIT_SUCCESS);
}
