/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:21:15 by abaioumy          #+#    #+#             */
/*   Updated: 2023/01/23 10:16:18 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"

int	ft_get_color(int x, int y, int height, t_texture *texture)
{
	int	color;

	color = (int)((y * TILE) / height);
	texture->address = mlx_get_data_addr(texture->image,
			&texture->bits_per_pixel, &texture->line_len,
			&texture->endian);
	if (color >= TILE)
		color = TILE - 1;
	if (color < 0)
		color = 0;
	return (*(int *)(texture->address + color % TILE
		* texture->line_len
		+ x % TILE * (texture->bits_per_pixel / 8)));
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
