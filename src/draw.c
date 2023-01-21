/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:31:22 by abaioumy          #+#    #+#             */
/*   Updated: 2023/01/21 14:57:35 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include <stdio.h>

void ft_draw_rectangle(int x, int y, int width, int height, int color, t_game *game)
{
	int i;
	int j;

	i = y;
	while (i < y + height)
	{
		j = x;
		while (j < x + width)
		{
			ft_draw_pixel(game, j++, i, color);
		}
		++i;
	}
}

void	ft_draw_line_ddb(int x, int y, int end_x, int end_y, int color, t_game *game)
{
	double    middle_x;
	double    middle_y;
    double    d_middle_x;
    double    d_middle_y;
    double    distance;

    middle_x = 0;
    middle_y = 0;
    distance = sqrt(pow(end_x - x, 2) + pow(end_y - y, 2));
    d_middle_x = (end_x - x) / distance;
    d_middle_y = (end_y - y) / distance;
    while (distance-- > 0)
    {
        ft_draw_pixel_mini_map(game, x + middle_x, y + middle_y, color);
        middle_x += d_middle_x;
        middle_y += d_middle_y;
    }
}

void	ft_draw_walls(t_game *game)
{
	int	i;
	int color;
	int begin;
	int start;
	int end;

	i = 0;
	begin = 0;
	while (i < WIDTH)
	{
		begin = 0;
		start = 0;
		if (game->wall[i].height > HEIGHT)
		{
			start = game->wall[i].height / 2 - HEIGHT / 2;
			end = game->wall[i].height / 2 + HEIGHT / 2;
		}
		else
			end = game->wall[i].height;
		// printf("game->wall[%d].height = %f\n", i, game->wall[i].height);
		while (start < end)
		{
			if (game->wall[i].is_horizontal)
				color = ft_get_color(game->wall[i].tex_x, start, game->wall[i].height, game);
			else
				color = ft_get_color(game->wall[i].tex_y, start, game->wall[i].height, game);	
			ft_draw_pixel(game, i, start + game->wall[i].begin_draw, color);
			start++;
		}
		ft_draw_rectangle(i, game->wall[i].begin_draw + game->wall[i].height - 1, 1, HEIGHT - (game->wall[i].begin_draw + game->wall[i].height), game->color_floor, game);
		ft_draw_rectangle(i, 0, 1, game->wall[i].begin_draw, game->color_ceiling, game);
		i++;
	}
}