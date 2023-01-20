/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:31:22 by abaioumy          #+#    #+#             */
/*   Updated: 2023/01/20 15:43:42 by abaioumy         ###   ########.fr       */
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

void	ft_draw_point(t_game *game, int mini_map_x, int mini_map_y)
{
	int i;
	int	j;

	i = (int)game->player->pos_y - mini_map_y;
	while (i < (int)((game->player->pos_y - mini_map_y) + 4))
	{
		j = game->player->pos_x - mini_map_x;
		while (j < (int)((game->player->pos_x - mini_map_x) + 4))
		{
			ft_draw_pixel_mini_map(game, j++, i, ft_convert_rgb(228, 208, 10));
		}
		++i;
	}
}

void	ft_draw_square(int x, int y, t_game *game, int color)
{
	int i;
	int	j;

	i = y;
	while (i < y + TILE)
	{
		j = x;
		while (j < x + TILE)
			ft_draw_pixel_mini_map(game, j++, i, color);
		++i;
	}
}

void	ft_draw_grid(t_game *game)
{
	int	x;
	int	y;
	int	x_end;
	int	y_end;
	// int	map[8][8] =
	// {
	// 	{1,1,1,1,1,1,1,1},
	// 	{1,0,0,0,1,0,0,1},
	// 	{1,0,0,0,0,0,0,1},
	// 	{1,0,0,0,0,0,0,1},
	// 	{1,0,0,0,1,1,1,1},
	// 	{1,0,0,0,1,0,0,1},
	// 	{1,0,0,0,0,0,0,1},
	// 	{1,1,1,1,1,1,1,1}
	// };

	int mx;
	int my;
	int test_x = game->player->pos_x - (250 / 2);
	int test_y = game->player->pos_y - (250 / 2);
	mx = (game->player->pos_x - (250 / 2)) / TILE;
	my = (game->player->pos_y - (250 / 2)) / TILE;

	while (game->data->map[my])
	{
		mx = (game->player->pos_x - (250 / 2)) / TILE;
		while (game->data->map[my][mx])
		{
			if (game->data->map[my][mx] == 1)
				ft_draw_square((mx * TILE) - test_x, (my * TILE) - test_y, game, ft_convert_rgb(228, 208, 10));
			else
				ft_draw_square((mx * TILE) - test_x, (my * TILE) - test_y, game, ft_convert_rgb(255, 255, 255));
			mx++;
		}
		my++;
	}
	ft_draw_point(game, game->player->pos_x - (250 / 2), game->player->pos_y - (250 / 2));
}

int	ft_get_color(int x, int y, int height, t_game *game)
{
	game->texture->address = mlx_get_data_addr(game->texture->image, &game->texture->bits_per_pixel, &game->texture->line_len, &game->texture->endian);
	return (*(int *)(game->texture->address + (int)((y * TILE) / height) % TILE * game->texture->line_len + x % TILE * (game->texture->bits_per_pixel / 8)));
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
		while (start < end)
		{
			if (game->wall[i].is_horizontal)
				color = ft_get_color(game->wall[i].tex_x, start, game->wall[i].height, game);
			else
				color = ft_get_color(game->wall[i].tex_y, start, game->wall[i].height, game);	
			ft_draw_pixel(game, i, start + game->wall[i].begin_draw, color);
			start++;
		}
		//floors
		ft_draw_rectangle(i, game->wall[i].begin_draw + game->wall[i].height - 1, 1, HEIGHT - (game->wall[i].begin_draw + game->wall[i].height), game->color_floor, game);
		//ceiling
		ft_draw_rectangle(i, 0, 1, game->wall[i].begin_draw, game->color_ceiling, game);
		i++;
	}
}