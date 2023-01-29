/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:29:57 by abaioumy          #+#    #+#             */
/*   Updated: 2023/01/29 18:08:16 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "libft.h"
#include "close.h"

void	ft_protect_texture(t_game *game)
{
	if (!game->texture_north->image)
	{
		ft_putstr_fd("failed to load north texture\n", STDERR_FILENO);
		exit(EXIT_SUCCESS);
	}
	if (!game->texture_south->image)
	{
		ft_putstr_fd("failed to load south texture\n", STDERR_FILENO);
		exit(EXIT_SUCCESS);
	}
	if (!game->texture_east->image)
	{
		ft_putstr_fd("failed to load east texture\n", STDERR_FILENO);
		exit(EXIT_SUCCESS);
	}
	if (!game->texture_west->image)
	{
		ft_putstr_fd("failed to load west texture\n", STDERR_FILENO);
		exit(EXIT_SUCCESS);
	}
	if (!game->gun)
	{
		ft_putstr_fd("failed to load mini-map texture\n", STDERR_FILENO);
		exit(EXIT_SUCCESS);
	}
}

void	ft_load_texture(t_game *game)
{
	game->texture_north->width = TILE;
	game->texture_north->height = TILE;
	game->texture_north->image = mlx_xpm_file_to_image(game->mlx->init,
			game->data->no, &game->texture_north->width,
			&game->texture_north->height);
	game->texture_south->image = mlx_xpm_file_to_image(game->mlx->init,
			game->data->so, &game->texture_north->width,
			&game->texture_north->height);
	game->texture_east->image = mlx_xpm_file_to_image(game->mlx->init,
			game->data->ea, &game->texture_north->width,
			&game->texture_north->height);
	game->texture_west->image = mlx_xpm_file_to_image(game->mlx->init,
			game->data->we, &game->texture_north->width,
			&game->texture_north->height);
	game->gun = mlx_xpm_file_to_image(game->mlx->init,
			"./assets/gun.xpm", &game->texture_north->width,
			&game->texture_north->height);
	ft_protect_texture(game);
}

void	ft_assign_texture(t_game *game, int ray, char direction)
{
	if (direction == 'h')
	{
		if (game->ray->angle > 0 && game->ray->angle < PI)
			game->wall[ray].texture->image = game->texture_north->image;
		else if (game->ray->angle > PI && game->ray->angle < 2 * PI)
			game->wall[ray].texture->image = game->texture_south->image;
	}
	else
	{
		if (game->ray->angle > PI / 2 && game->ray->angle < 3 * PI / 2)
			game->wall[ray].texture->image = game->texture_west->image;
		else if (game->ray->angle < PI / 2 || game->ray->angle > 3 * PI / 2)
			game->wall[ray].texture->image = game->texture_east->image;
	}
}
