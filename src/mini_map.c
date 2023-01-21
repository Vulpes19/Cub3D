/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 14:26:59 by abaioumy          #+#    #+#             */
/*   Updated: 2023/01/21 14:42:04 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void	ft_draw_point(t_game *game, int mini_map_x, int mini_map_y)
{
	int	i;
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
	int	i;
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

void	ft_init_mini_map(int *mini_map_x, int *mini_map_y, t_game *game)
{
	*mini_map_x = (game->player->pos_x - (250 / 2)) / TILE;
	*mini_map_y = (game->player->pos_y - (250 / 2)) / TILE;
}

void	ft_draw_grid(t_game *game)
{
	int	mini_map_x;
	int	mini_map_y;
	int	map_x;
	int	map_y;

	ft_init_mini_map(&mini_map_x, &mini_map_y, game);
	map_x = game->player->pos_x - (250 / 2);
	map_y = game->player->pos_y - (250 / 2);
	while (game->data->map[mini_map_y])
	{
		mini_map_x = (game->player->pos_x - (250 / 2)) / TILE;
		while (game->data->map[mini_map_y][mini_map_x])
		{
			if (game->data->map[mini_map_y][mini_map_x] == '1')
				ft_draw_square((mini_map_x * TILE) - map_x, (mini_map_y * TILE)
					- map_y, game, ft_convert_rgb(228, 208, 10));
			else
				ft_draw_square((mini_map_x * TILE) - map_x, (mini_map_y * TILE)
					- map_y, game, ft_convert_rgb(255, 255, 255));
			mini_map_x++;
		}
		mini_map_y++;
	}
	ft_draw_point(game, game->player->pos_x - (250 / 2),
		game->player->pos_y - (250 / 2));
}
