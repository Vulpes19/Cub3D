/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:25:50 by abaioumy          #+#    #+#             */
/*   Updated: 2023/01/16 11:48:34 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"
#include <stdio.h>
#include "close.h"

void	ft_movement(int keycode, t_game *game)
{
	int	map[8][8] =
	{
		{1,1,1,1,1,1,1,1},
		{1,0,0,0,1,0,0,1},
		{1,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,1},
		{1,0,0,0,1,1,1,1},
		{1,0,0,0,1,0,0,1},
		{1,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1}
	};
	int mx_w = floor(game->player->pos_x + cos(game->player->angle) * 5) / TILE;
	int my_w = floor(game->player->pos_y + sin(game->player->angle) * 5) / TILE;
	int mx_s = floor(game->player->pos_x - cos(game->player->angle) * 5) / TILE;
	int my_s = floor(game->player->pos_y - sin(game->player->angle) * 5) / TILE;
	int mx_d = floor(game->player->pos_x + cos(game->player->angle + PI / 2) * 5) / TILE;
	int my_d = floor(game->player->pos_y + sin(game->player->angle + PI / 2) * 5) / TILE;
	int mx_a = floor(game->player->pos_x - cos(game->player->angle + PI / 2) * 5) / TILE;
	int my_a = floor(game->player->pos_y - sin(game->player->angle + PI / 2) * 5) / TILE;
	if (keycode == W_KEY && map[my_w][mx_w] == 0)
	{
		game->player->pos_x += cos(game->player->angle) * 5;
		game->player->pos_y += sin(game->player->angle) * 5;
	}
	if (keycode == S_KEY && map[my_s][mx_s] == 0)
	{
		game->player->pos_x -= cos(game->player->angle) * 5;
		game->player->pos_y -= sin(game->player->angle) * 5;
	}
	if (keycode == A_KEY && map[my_a][mx_a] == 0)
	{
		game->player->pos_x -= cos(game->player->angle + PI / 2) * 5;
		game->player->pos_y -= sin(game->player->angle + PI / 2) * 5;
	}
	if (keycode == D_KEY && map[my_d][mx_d] == 0)
	{
		game->player->pos_x += cos(game->player->angle + PI / 2) * 5;
		game->player->pos_y += sin(game->player->angle + PI / 2) * 5;
	}
}

void	ft_rotation(int keycode, t_game *game)
{
	if (keycode == RIGHT_ARROW)
	{
		game->player->angle += 0.1;
		if (game->player->angle > 2 * PI)
		{
			game->player->angle -= 2 * PI;
		}
		game->ray->angle = game->player->angle;
	}
	if (keycode == LEFT_ARROW)
	{
		game->player->angle -= 0.1;
		if (game->player->angle < 0)
		{
			game->player->angle += 2 * PI;
		}
		game->ray->angle = game->player->angle;
	}
}

int	ft_input_handler(int keycode, t_game *game)
{
	ft_rotation(keycode, game);
	ft_movement(keycode, game);
	ft_raycasting(game);
	ft_close_esc(keycode, game);
	// mlx_hook(game->mlx->window, 2, 1L << 0, ft_close_esc, game);
	return (0);
}