/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:09:28 by abaioumy          #+#    #+#             */
/*   Updated: 2023/01/22 20:10:41 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

double	ft_distance(double x1, double y1, double x2, double y2)
{
	return (sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)));
}

void	ft_calculate_distance(t_game *game, char direction)
{
	if (direction == 'h')
	{
		game->ray->h_pos_x = game->ray->x;
		game->ray->h_pos_y = game->ray->y;
		game->ray->distance_h
			= ft_distance(game->player->pos_x, game->player->pos_y,
				game->ray->x, game->ray->y);
	}
	else
	{
		game->ray->v_pos_x = game->ray->x;
		game->ray->v_pos_y = game->ray->y;
		game->ray->distance_v
			= ft_distance(game->player->pos_x, game->player->pos_y,
				game->ray->x, game->ray->y);
	}
}
