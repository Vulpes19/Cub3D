/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 14:04:30 by abaioumy          #+#    #+#             */
/*   Updated: 2023/01/22 19:05:34 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "input.h"

void	ft_check_w_collision(t_game *game, int mx, int my)
{
	if (game->data->map[my][mx] == '0' || game->data->map[my][mx] == 'N'
		|| game->data->map[my][mx] == 'S' || game->data->map[my][mx] == 'E'
		|| game->data->map[my][mx] == 'W')
	{
		game->player->pos_x += cos(game->player->angle) * 5;
		game->player->pos_y += sin(game->player->angle) * 5;
	}
}

void	ft_check_s_collision(t_game *game, int mx, int my)
{
	if (game->data->map[my][mx] == '0' || game->data->map[my][mx] == 'N'
		|| game->data->map[my][mx] == 'S' || game->data->map[my][mx] == 'E'
		|| game->data->map[my][mx] == 'W')
	{
		game->player->pos_x -= cos(game->player->angle) * 5;
		game->player->pos_y -= sin(game->player->angle) * 5;
	}
}

void	ft_check_a_collision(t_game *game, int mx, int my)
{
	if (game->data->map[my][mx] == '0' || game->data->map[my][mx] == 'N'
		|| game->data->map[my][mx] == 'S' || game->data->map[my][mx] == 'E'
		|| game->data->map[my][mx] == 'W')
	{
		game->player->pos_x -= cos(game->player->angle + PI / 2) * 5;
		game->player->pos_y -= sin(game->player->angle + PI / 2) * 5;
	}
}

void	ft_check_d_collision(t_game *game, int mx, int my)
{
	if (game->data->map[my][mx] == '0' || game->data->map[my][mx] == 'N'
		|| game->data->map[my][mx] == 'S' || game->data->map[my][mx] == 'E'
		|| game->data->map[my][mx] == 'W')
	{
		game->player->pos_x += cos(game->player->angle + PI / 2) * 5;
		game->player->pos_y += sin(game->player->angle + PI / 2) * 5;
	}
}
