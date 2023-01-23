/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:29:57 by abaioumy          #+#    #+#             */
/*   Updated: 2023/01/23 11:50:28 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "libft.h"

void	ft_load_texture(t_game *game)
{
	game->texture_north->width = TILE;
	game->texture_north->height = TILE;
	game->texture_north->image = mlx_xpm_file_to_image(game->mlx->init,
			game->data->no, &game->texture_north->width,
			&game->texture_north->height);
	if (!game->texture_north->image)
		ft_putstr_fd("failed to load north texture\n", STDERR_FILENO);
	game->texture_south->image = mlx_xpm_file_to_image(game->mlx->init,
			game->data->so, &game->texture_north->width,
			&game->texture_north->height);
	if (!game->texture_south->image)
		ft_putstr_fd("failed to load south texture\n", STDERR_FILENO);
	game->texture_east->image = mlx_xpm_file_to_image(game->mlx->init,
			game->data->ea, &game->texture_north->width,
			&game->texture_north->height);
	if (!game->texture_east->image)
		ft_putstr_fd("failed to load east texture\n", STDERR_FILENO);
	game->texture_west->image = mlx_xpm_file_to_image(game->mlx->init,
			game->data->we, &game->texture_north->width,
			&game->texture_north->height);
	if (!game->texture_west->image)
		ft_putstr_fd("failed to load west texture\n", STDERR_FILENO);
}

void	ft_assign_texture(t_game *game, int ray, char direction)
{
	if (direction == 'h')
	{
		if (game->ray->angle > 0 && game->ray->angle < PI)
			game->wall[ray].texture->image = game->texture_south->image;
		else if (game->ray->angle > PI && game->ray->angle < 2 * PI)
			game->wall[ray].texture->image = game->texture_north->image;
	}
	else
	{
		if (game->ray->angle > PI / 2 && game->ray->angle < 3 * PI / 2)
			game->wall[ray].texture->image = game->texture_west->image;
		else if (game->ray->angle < PI / 2 || game->ray->angle > 3 * PI / 2)
			game->wall[ray].texture->image = game->texture_east->image;
	}
}
