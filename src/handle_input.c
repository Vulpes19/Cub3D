/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:25:50 by abaioumy          #+#    #+#             */
/*   Updated: 2023/01/09 16:05:15 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

int	ft_input_handler(int keycode, t_game *game)
{
	int	map[24][24] =
	{
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
		{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
		{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	};

	if (keycode == W_KEY)
	{
		if (map[(int)(game->player->pos_x + game->player->x * game->move_speed)][(int)(game->player->pos_y)] == 0)
			game->player->pos_x += game->player->x * game->move_speed;
		if (map[(int)(game->player->pos_x)][(int)(game->player->pos_y + game->player->y * game->move_speed)] == 0)
			game->player->pos_y += game->player->y * game->move_speed;
	}
	if (keycode == S_KEY)
	{
		if (map[(int)(game->player->pos_x - game->player->x * game->move_speed)][(int)(game->player->pos_y)] == 0)
			game->player->pos_x -= game->player->x * game->move_speed;
		if (map[(int)(game->player->pos_x)][(int)(game->player->pos_y - game->player->y * game->move_speed)] == 0)
			game->player->pos_y -= game->player->y * game->move_speed;
	}
	if (keycode == D_KEY)
	{
		double old_dir_x = game->player->x;
		game->player->x = game->player->x * cosf(-(game->rot_speed)) - game->player->y * sinf(-(game->rot_speed));
		game->player->y = old_dir_x * sinf(-(game->rot_speed)) + game->player->y * cosf(-(game->rot_speed));
		double old_plane_x = game->camera->plane_x;
		game->camera->plane_x = game->camera->plane_x  * cos(-(game->rot_speed)) - game->camera->plane_y  * sin(-(game->rot_speed));
		game->camera->plane_y = old_plane_x * sin(-(game->rot_speed)) + game->camera->plane_y* cos(-(game->rot_speed));
	}
	if (keycode == A_KEY)
	{
		double old_dir_x = game->player->x;
		game->player->x = game->player->x * cosf(game->rot_speed) - game->player->y * sinf(game->rot_speed);
		game->player->y = old_dir_x * sinf(game->rot_speed) + game->player->y * cosf(game->rot_speed);
		double old_plane_x = game->camera->plane_x;
		game->camera->plane_x = game->camera->plane_x  * cosf(game->rot_speed) - game->camera->plane_y  * sinf(game->rot_speed);
		game->camera->plane_y = old_plane_x * sinf(game->rot_speed) + game->camera->plane_y* cosf(game->rot_speed);
	}
	return (0);
}