/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:21:15 by abaioumy          #+#    #+#             */
/*   Updated: 2023/01/21 14:49:00 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"

int	ft_get_color(int x, int y, int height, t_game *game)
{
	game->texture->address = mlx_get_data_addr(game->texture->image, &game->texture->bits_per_pixel, &game->texture->line_len, &game->texture->endian);
	if (y * TILE / height >= TILE)
		y = TILE - 1;
	return (*(int *)(game->texture->address + (int)((y * TILE) / height) % TILE * game->texture->line_len + x % TILE * (game->texture->bits_per_pixel / 8)));
}

int	ft_convert_rgb(uint8_t red, uint8_t green, uint8_t blue)
{
	return (red << 16 | green << 8 | blue);
}

void	ft_get_floor_color(t_game *game)
{
	int	i;

	i = 0;
	game->floor = malloc(sizeof(int) * 3);
	while (game->data->floor[i])
	{
		game->floor[i] = ft_atoi(game->data->floor[i]);
		i++;
	}
	game->color_floor = ft_convert_rgb(game->floor[0],
			game->floor[1], game->floor[2]);
	free(game->floor);
}

void	ft_get_ceiling_color(t_game *game)
{
	int	i;

	i = 0;
	game->ceiling = malloc(sizeof(int) * 3);
	while (game->data->ceiling[i])
	{
		game->ceiling[i] = ft_atoi(game->data->ceiling[i]);
		i++;
	}
	game->color_ceiling = ft_convert_rgb(game->ceiling[0],
			game->ceiling[1], game->ceiling[2]);
	free(game->ceiling);
}
