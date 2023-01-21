/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:43:13 by abaioumy          #+#    #+#             */
/*   Updated: 2023/01/21 14:15:25 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "draw.h"

enum t_bool	ft_allocate_game(int ac, char **av, t_game *game)
{
	if (ft_init_parsing(ac, av, game) == FALSE)
	{
		free(game);
		return(FALSE);
	}
	game->mlx = (t_mlx *)malloc(sizeof(t_mlx));
	game->mlx->pixel = (t_pixel *)malloc(sizeof(t_pixel));
	game->mlx->mini_map = (t_pixel *)malloc(sizeof(t_pixel));
	game->player = (t_player *)malloc(sizeof(t_player));
	game->ray = (t_ray *)malloc(sizeof(t_ray));
	game->wall = (t_wall *)malloc(sizeof(t_wall) * WIDTH);
	game->texture = (t_texture *)malloc(sizeof(t_texture));
	return (TRUE);
}

void    ft_init_game(t_game *game)
{
    game->mlx->init = mlx_init();
	game->player->pos_x = game->data->player_x * TILE;
	game->player->pos_y = game->data->player_y * TILE;
	if (game->data->player_direction == 'N')
		game->player->angle = PI / 2;
	else if (game->data->player_direction == 'S')
		game->player->angle = 3 * PI / 2;
	else if (game->data->player_direction == 'W')
		game->player->angle = PI;
	else if (game->data->player_direction == 'E')
		game->player->angle = 0;
	game->player->rot_x = cos(game->player->angle) * 5;
	game->player->rot_y = sin(game->player->angle) * 5;
	game->player->fov = 60 * (PI / 180);
	game->player->half_fov = game->player->fov / 2;
	game->player->height = 32;
	game->player->speed = 16;
	game->ray->angle = game->player->angle;
	ft_get_ceiling_color(game);
	ft_get_floor_color(game);
}
