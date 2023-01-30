/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:25:50 by abaioumy          #+#    #+#             */
/*   Updated: 2023/01/30 15:07:39 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_bonus.h"
#include <stdio.h>
#include "close_bonus.h"

void	ft_init_pos(int *arr, t_game *game)
{
	arr[0] = floor(game->player->pos_x + cos(game->player->angle) * 5) / TILE;
	arr[1] = floor(game->player->pos_y + sin(game->player->angle) * 5) / TILE;
	arr[2] = floor(game->player->pos_x - cos(game->player->angle) * 5) / TILE;
	arr[3] = floor(game->player->pos_y - sin(game->player->angle) * 5) / TILE;
	arr[4] = floor(game->player->pos_x + cos(game->player->angle
				+ PI / 2) * 5) / TILE;
	arr[5] = floor(game->player->pos_y + sin(game->player->angle
				+ PI / 2) * 5) / TILE;
	arr[6] = floor(game->player->pos_x - cos(game->player->angle
				+ PI / 2) * 5) / TILE;
	arr[7] = floor(game->player->pos_y - sin(game->player->angle
				+ PI / 2) * 5) / TILE;
}

void	ft_movement(int keycode, t_game *game)
{
	int	*arr;

	arr = (int *)malloc(sizeof(int) * 8);
	ft_init_pos(arr, game);
	if (keycode == W_KEY)
		ft_check_w_collision(game, arr[0], arr[1]);
	if (keycode == S_KEY)
		ft_check_s_collision(game, arr[2], arr[3]);
	if (keycode == D_KEY)
		ft_check_d_collision(game, arr[4], arr[5]);
	if (keycode == A_KEY)
		ft_check_a_collision(game, arr[6], arr[7]);
	free(arr);
}

void	ft_rotation(int keycode, t_game *game)
{
	if (keycode == RIGHT_ARROW)
	{
		game->player->angle += 0.08;
		if (game->player->angle > 2 * PI)
		{
			game->player->angle -= 2 * PI;
		}
		game->ray->angle = game->player->angle;
	}
	if (keycode == LEFT_ARROW)
	{
		game->player->angle -= 0.08;
		if (game->player->angle < 0)
		{
			game->player->angle += 2 * PI;
		}
		game->ray->angle = game->player->angle;
	}
}

int	ft_input_handler(int keycode, t_game *game)
{
	if (keycode == ESC)
		ft_close_esc(game);
	if (keycode == W_KEY || keycode == S_KEY
		|| keycode == A_KEY || keycode == D_KEY)
		ft_movement(keycode, game);
	if (keycode == LEFT_ARROW || keycode == RIGHT_ARROW)
		ft_rotation(keycode, game);
	ft_raycasting(game);
	return (0);
}
