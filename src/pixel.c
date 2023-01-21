/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 14:23:52 by abaioumy          #+#    #+#             */
/*   Updated: 2023/01/21 14:24:38 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include <stdio.h>

void	ft_draw_pixel(t_game *game, int x, int y, int color)
{
	char	*dest;

	if (x < 0 || y < 0 || x >= WIDTH || y >= HEIGHT)
		return ;	
	dest = game->mlx->pixel->address + (y * game->mlx->pixel->line_len + x * (game->mlx->pixel->bits_per_pixel / 8));
	*(unsigned int*)dest = color;
}

void	ft_draw_pixel_mini_map(t_game *game, int x, int y, int color)
{
	char	*dest;

	if (x < 0 || y < 0 || x >= 250 || y >= 250)
		return ;	
	dest = game->mlx->mini_map->address + (y * game->mlx->mini_map->line_len + x * (game->mlx->mini_map->bits_per_pixel / 8));
	*(unsigned int*)dest = color;
}
