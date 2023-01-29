/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:31:22 by abaioumy          #+#    #+#             */
/*   Updated: 2023/01/23 10:15:28 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include <stdio.h>

void	ft_draw_rectangle(t_rectangle rect, t_game *game)
{
	int	i;
	int	j;

	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
		{
			ft_draw_pixel(game, j++, i, rect.color);
		}
		++i;
	}
}

void	ft_draw_floor_and_ceiling(t_game *game, int i)
{
	t_rectangle	rect;

	rect.x = i;
	rect.y = game->wall[i].begin_draw + game->wall[i].height - 1;
	rect.width = 1;
	rect.height = HEIGHT - (game->wall[i].begin_draw + game->wall[i].height);
	rect.color = game->color_floor;
	ft_draw_rectangle(rect, game);
	rect.x = i;
	rect.y = 0;
	rect.width = 1;
	rect.height = game->wall[i].begin_draw;
	rect.color = game->color_ceiling;
	ft_draw_rectangle(rect, game);
}

void	ft_draw_walls(t_game *game, int i)
{
	int	color;
	int	start;
	int	end;

	start = 0;
	if (game->wall[i].height > HEIGHT)
	{
		start = game->wall[i].height / 2 - HEIGHT / 2;
		end = game->wall[i].height / 2 + HEIGHT / 2;
	}
	else
		end = game->wall[i].height;
	while (start < end)
	{
		if (game->wall[i].is_horizontal)
			color = ft_get_color(game->wall[i].tex_x,
					start, game->wall[i].height, game->wall[i].texture);
		else
			color = ft_get_color(game->wall[i].tex_y,
					start, game->wall[i].height, game->wall[i].texture);
		ft_draw_pixel(game, i, start + game->wall[i].begin_draw, color);
		start++;
	}
	ft_draw_floor_and_ceiling(game, i);
}
