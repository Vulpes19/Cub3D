/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:31:22 by abaioumy          #+#    #+#             */
/*   Updated: 2023/01/12 18:45:35 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include <stdio.h>

void	ft_draw_pixel(t_game *game, int x, int y, int color)
{
	char	*dest;

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

void	ft_draw_line_ddb(int x, int y, int end_x, int end_y, int color, t_game *game)
{
	int	delta_x;
	int	delta_y;
	int	inc_x;
	int	inc_y;
	int	steps;
	int	i;

	delta_x = end_x - x;
	delta_y = end_y - y;
	if (delta_x > delta_y)
		steps = delta_x;
	else
		steps = delta_y;
	inc_x = delta_x / steps;
	inc_y = delta_y / steps;
	i = 0;
	while (i < steps)
	{
		ft_draw_pixel(game, x, y, color);
		x += inc_x;
		y += inc_y;
		i++;
	}
}

void	ft_draw_point(t_game *game)
{
	int i;
	int	j;

	i = game->player->pos_y;
	ft_draw_line_ddb(game->player->pos_x, game->player->pos_y, game->player->pos_x + game->player->rot_x * 5, game->player->pos_y + game->player->rot_y * 5, ft_convert_rgb(228, 208, 10), game);
	while (i < game->player->pos_y + 4)
	{
		j = game->player->pos_x;
		while (j < game->player->pos_x + 4)
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