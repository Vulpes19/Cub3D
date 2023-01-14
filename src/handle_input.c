/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:25:50 by abaioumy          #+#    #+#             */
/*   Updated: 2023/01/14 12:19:28 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"
#include <stdio.h>
#include "close.h"

void	ft_movement(int keycode, t_game *game)
{
	if (keycode == W_KEY)
	{
		// game->player->pos_x -= game->player->rot_x;
		// game->player->pos_y -= game->player->rot_y;
		game->player->pos_x += cos(game->player->angle) * 5;
		game->player->pos_y += sin(game->player->angle) * 5;
	}
	if (keycode == S_KEY)
	{
		game->player->pos_x -= cos(game->player->angle) * 5;
		game->player->pos_y -= sin(game->player->angle) * 5;
	}
	if (keycode == D_KEY)
	{
		game->player->angle += 0.1;
		if (game->player->angle > 2 * PI)
		{
			game->player->angle -= 2 * PI;
		}
		game->ray->angle = game->player->angle /*- (game->player->fov / 2)*/;
		// game->player->rot_x = cos(game->player->angle) * 5;
		// game->player->rot_y = sin(game->player->angle) * 5;
	}
	if (keycode == A_KEY)
	{
		game->player->angle -= 0.1;
		if (game->player->angle < 0)
		{
			game->player->angle += 2 * PI;
		}
		game->ray->angle = game->player->angle /*- (game->player->fov / 2)*/;
		// game->player->rot_x = cos(game->player->angle) * 5;
		// game->player->rot_y = sin(game->player->angle) * 5;
	}
}

// void	ft_rotation(int keycode, t_game *game)
// {
// 	if (keycode == RIGHT_ARROW)
// 	{
// 		game->player->angle -= 0.1;
// 		if (game->player->angle < 0)
// 		{
// 			game->player->angle += 2 * PI;
// 			game->player->rot_x = cos(game->player->angle) * 5;
// 			game->player->rot_y = sin(game->player->angle) * 5;
// 		}
// 	}
// 	if (keycode == LEFT_ARROW)
// 	{
// 		game->player->angle += 0.1;
// 		if (game->player->angle > 2 * PI)
// 		{
// 			game->player->angle -= 2 * PI;
// 		}
// 		game->player->rot_x = cos(game->player->angle) * 5;
// 		game->player->rot_y = sin(game->player->angle) * 5;
// 	}
// }

int	ft_input_handler(int keycode, t_game *game)
{
	// ft_rotation(keycode, game);
	ft_movement(keycode, game);
	ft_raycasting(game);
	// mlx_hook(game->mlx->window, 2, 1L << 0, ft_close_esc, game);
	return (0);
}