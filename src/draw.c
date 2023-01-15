/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:31:22 by abaioumy          #+#    #+#             */
/*   Updated: 2023/01/14 17:24:34 by abaioumy         ###   ########.fr       */
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

int	ft_convert_rgb(uint8_t red, uint8_t green, uint8_t blue)
{
	return (red << 16 | green << 8 | blue);
}

void	ft_draw_line(int x, int draw_start, int draw_end, int color, t_game *game)
{
	while (draw_start < draw_end)
	{
		ft_draw_pixel(game, x, draw_start, color);
		draw_start++;
	}
}

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
        ft_draw_pixel(game, x + middle_x, y + middle_y, color);
        middle_x += d_middle_x;
        middle_y += d_middle_y;
    }
}

void	ft_draw_point(t_game *game)
{
	int i;
	int	j;

	i = (int)game->player->pos_y;
	// ft_draw_line_ddb(game->player->pos_x, game->player->pos_y,game->player->pos_x +  cos(game->player->angle) * 50,game->player->pos_y +  sin(game->player->angle) * 50 , ft_convert_rgb(00, 0xff, 00), game);
	while (i < (int)(game->player->pos_y + 4))
	{
		j = game->player->pos_x;
		while (j < (int)(game->player->pos_x + 4))
		{
			ft_draw_pixel(game, j++, i, ft_convert_rgb(228, 208, 10));
		}
		++i;
	}
}

void	ft_draw_square(int x, int y, t_game *game, int color)
{
	int i;
	int	j;

	i = y;
	while (i < y + TILE - 1)
	{
		j = x;
		while (j < x + TILE - 1)
		{
			ft_draw_pixel(game, j++, i, color);
		}
		++i;
	}
}