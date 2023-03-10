/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 14:26:59 by abaioumy          #+#    #+#             */
/*   Updated: 2023/01/30 15:23:20 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw_bonus.h"
#include "libft_bonus.h"

void	ft_draw_point(t_game *game, int mini_map_x, int mini_map_y)
{
	int	i;
	int	j;

	i = (int)game->player->pos_y - mini_map_y;
	while (i < (int)((game->player->pos_y - mini_map_y) + 4))
	{
		j = game->player->pos_x - mini_map_x;
		while (j < (int)((game->player->pos_x - mini_map_x) + 4))
			ft_draw_pixel_mini_map(game, j++, i, 0xAEC5EB);
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

void	ft_init_mini_map(t_mini_map *mini_map, t_game *game)
{
	mini_map->mini_map_x = (game->player->pos_x - (250 / 2)) / TILE;
	mini_map->mini_map_y = (game->player->pos_y - (250 / 2)) / TILE;
	mini_map->map_x = game->player->pos_x - (250 / 2);
	mini_map->map_y = game->player->pos_y - (250 / 2);
}

void	ft_draw_grid_loop(t_game *game, t_mini_map mini_map)
{
	while (game->data->map[mini_map.mini_map_y][mini_map.mini_map_x])
	{
		if (game->data->map
			[mini_map.mini_map_y][mini_map.mini_map_x] == '1')
			ft_draw_square((mini_map.mini_map_x * TILE)
				- mini_map.map_x, (mini_map.mini_map_y * TILE)
				- mini_map.map_y, game, 0xAEC5EB);
		else
			ft_draw_square((mini_map.mini_map_x * TILE)
				- mini_map.map_x, (mini_map.mini_map_y * TILE)
				- mini_map.map_y, game, 0xF9DEC9);
		mini_map.mini_map_x++;
	}
}

void	ft_draw_grid(t_game *game)
{
	t_mini_map	mini_map;
	size_t		len;

	ft_init_mini_map(&mini_map, game);
	while (mini_map.mini_map_y < game->data->map_length)
	{
		len = ft_strlen(game->data->map[mini_map.mini_map_y]);
		mini_map.mini_map_x = (game->player->pos_x - (250 / 2)) / TILE;
		if (mini_map.mini_map_x > len)
			mini_map.mini_map_x = len;
		ft_draw_grid_loop(game, mini_map);
		mini_map.mini_map_y++;
	}
	ft_draw_point(game, game->player->pos_x - (250 / 2),
		game->player->pos_y - (250 / 2));
}
