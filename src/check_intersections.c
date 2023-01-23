/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_intersections.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 13:45:00 by abaioumy          #+#    #+#             */
/*   Updated: 2023/01/23 12:14:02 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "libft.h"
#include "draw.h"

void	ft_norme(t_game *game)
{
	game->ray->x = game->player->pos_x;
	game->ray->y = game->player->pos_y;
}

void	ft_intersection_loop_h(t_game *game, size_t mx, size_t my)
{
	int	dof;

	dof = 0;
	while (dof < HEIGHT)
	{
		mx = (int)(game->ray->x / TILE);
		my = (int)(game->ray->y / TILE);
		if (my < 0 || mx < 0)
			break ;
		if (my < game->data->map_length && mx
			< ft_strlen(game->data->map[my]) && game->data->map[my][mx] == '1')
		{
			ft_calculate_distance(game, 'h');
			break ;
		}
		else
		{
			game->ray->x += game->ray->x_a;
			game->ray->y += game->ray->y_a;
			dof += 1;
		}
	}
}

void	ft_intersection_loop_v(t_game *game, size_t mx, size_t my)
{
	int	dof;

	dof = 0;
	while (dof < HEIGHT)
	{
		mx = (int)(game->ray->x / TILE);
		my = (int)(game->ray->y / TILE);
		if (my < 0 || mx < 0)
			break ;
		if (my < game->data->map_length && mx < ft_strlen(game->data->map[my])
			&& game->data->map[my][mx] == '1')
		{
			ft_calculate_distance(game, 'v');
			break ;
		}
		else
		{
			game->ray->x += game->ray->x_a;
			game->ray->y += game->ray->y_a;
			dof += 1;
		}
	}
}

void	ft_horizontal_intersections(t_game *game)
{
	size_t	mx;
	size_t	my;

	mx = 0;
	my = 0;
	if (game->ray->angle > PI)
	{
		game->ray->y = floor(game->player->pos_y / TILE) * TILE - 0.0001;
		game->ray->x = game->player->pos_x
			- (game->player->pos_y - game->ray->y) / tan(game->ray->angle);
		game->ray->y_a = -TILE;
		game->ray->x_a = game->ray->y_a / tan(game->ray->angle);
	}
	if (game->ray->angle < PI)
	{
		game->ray->y = floor(game->player->pos_y / TILE) * TILE + TILE;
		game->ray->x = game->player->pos_x
			- (game->player->pos_y - game->ray->y) / tan(game->ray->angle);
		game->ray->y_a = TILE;
		game->ray->x_a = game->ray->y_a / tan(game->ray->angle);
	}
	if (game->ray->angle == 0 || game->ray->angle == PI)
	{
		ft_norme(game);
		return ;
	}
	ft_intersection_loop_h(game, mx, my);
}

void	ft_vertical_intersections(t_game *game)
{
	size_t	mx;
	size_t	my;

	mx = 0;
	my = 0;
	if (game->ray->angle > PI / 2 && game->ray->angle < 3 * PI / 2)
	{
		game->ray->x = floor(game->player->pos_x / TILE) * TILE - 0.0001;
		game->ray->y = game->player->pos_y
			+ (game->ray->x - game->player->pos_x) * tan(game->ray->angle);
		game->ray->x_a = -TILE;
		game->ray->y_a = game->ray->x_a * tan(game->ray->angle);
	}
	if (game->ray->angle < PI / 2 || game->ray->angle > 3 * PI / 2)
	{
		game->ray->x = floor(game->player->pos_x / TILE) * TILE + TILE;
		game->ray->y = game->player->pos_y
			- (game->player->pos_x - game->ray->x) * tan(game->ray->angle);
		game->ray->x_a = TILE;
		game->ray->y_a = game->ray->x_a * tan(game->ray->angle);
	}
	if (game->ray->angle == 0 || game->ray->angle == PI)
	{
		ft_norme(game);
		return ;
	}
	ft_intersection_loop_v(game, mx, my);
}
