/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:29:57 by abaioumy          #+#    #+#             */
/*   Updated: 2023/01/22 20:13:49 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	ft_load_texture(t_game *game)
{
	game->texture->width = TILE;
	game->texture->height = TILE;
	game->texture->image = mlx_xpm_file_to_image(game->mlx->init,
			"assets/spongebob-64x64.xpm", &game->texture->width,
			&game->texture->height);
}
