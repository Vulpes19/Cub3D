/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:39:33 by abaioumy          #+#    #+#             */
/*   Updated: 2023/01/15 15:49:47 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "draw.h"
#include "input.h"
#include <stdio.h>
#include <stdlib.h>

double ft_distance(double x1, double y1, double x2, double y2)
{
	// return (sqrt( (x2 - x1) * (y2 - y1) + (y2 - y1) * (y2 - y1) ));
	return (sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)));
}
void	ft_check_horizontal( t_game *game, double *h_pos_x, double *h_pos_y, double *dist )
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
	int	dof = 0;
	if (game->ray->angle > PI)
	{
		game->ray->y = floor(game->player->pos_y / TILE) * TILE - 1;
		game->ray->x = (int)(game->player->pos_x - (game->player->pos_y - game->ray->y) / tan(game->ray->angle));
		game->ray->y_a = -TILE;
		game->ray->x_a = game->ray->y_a / tan(game->ray->angle);
		// printf("x_a = %f, pl_a = %f ray_a = %f\n", game->ray->x_a, game->player->angle, game->ray->angle);
	}
	if (game->ray->angle < PI)
	{
		game->ray->y = floor(game->player->pos_y / TILE) * TILE + TILE;
		game->ray->x = (int)(game->player->pos_x - (game->player->pos_y - game->ray->y) / tan(game->ray->angle));
		game->ray->y_a = TILE;
		game->ray->x_a = game->ray->y_a / tan(game->ray->angle);
		// printf("x_a = %f, pl_a = %f ray_a = %f\n", game->ray->x_a, game->player->angle, game->ray->angle);
	}
	if (game->ray->angle == 0 || game->ray->angle == PI)
	{
		game->ray->x = game->player->pos_x;
		game->ray->y = game->player->pos_y;
		dof = 8;
	}
	while (dof < 8)
	{
		// ft_draw_pixel(game, game->ray->x, game->ray->y, 0xff);
		// ft_draw_pixel(game, game->ray->x + 1, game->ray->y, 0xff);
		// ft_draw_pixel(game, game->ray->x, game->ray->y + 1, 0xff);
		// ft_draw_pixel(game, game->ray->x + 1, game->ray->y + 1, 0xff);
		// ft_draw_pixel(game, game->ray->x - 1, game->ray->y, 0xff);
		// ft_draw_pixel(game, game->ray->x, game->ray->y - 1, 0xff);
		// ft_draw_pixel(game, game->ray->x - 1, game->ray->y - 1, 0xff);

		int mx = (int)(game->ray->x / TILE);
		int my = (int)(game->ray->y / TILE);
		if (my < 0 || mx < 0)
			break ;
		if (my < 8 && mx < 8 && map[my][mx] == 1)
		{
			*h_pos_x = game->ray->x;
			*h_pos_y = game->ray->y;
			*dist = ft_distance(game->player->pos_x, game->player->pos_y, game->ray->x, game->ray->y);
			dof = 8;
		}
		else
		{
			game->ray->x += game->ray->x_a;
			game->ray->y += game->ray->y_a;
			dof += 1;
		}
	}
	if (game->ray->angle > PI)
		game->ray->y += 1;
}

void	ft_check_vertical( t_game *game, double *v_pos_x, double *v_pos_y, double *dist )
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
	int	dof = 0;
	if (game->ray->angle > PI / 2 && game->ray->angle < 3 * PI / 2)
	{
		game->ray->x = (int)(game->player->pos_x / TILE) * TILE - 1;
		game->ray->y = (int)(game->player->pos_y + (game->ray->x - game->player->pos_x) * tan(game->ray->angle));
		game->ray->x_a = -64;
		game->ray->y_a = game->ray->x_a * tan(game->ray->angle);
	}
	if (game->ray->angle < PI / 2 || game->ray->angle > 3 * PI / 2)
	{
		game->ray->x = (int)(game->player->pos_x / TILE) * TILE + TILE;
		game->ray->y = (int)(game->player->pos_y - (game->player->pos_x - game->ray->x) * tan(game->ray->angle));
		game->ray->x_a = TILE;
		game->ray->y_a = game->ray->x_a * tan(game->ray->angle);
	}
	if (game->ray->angle == 0 || game->ray->angle == PI)
	{
		game->ray->x = game->player->pos_x;
		game->ray->y = game->player->pos_y;
		dof = 8;
	}
	while (dof < 8)
	{
		// ft_draw_pixel(game, game->ray->x, game->ray->y, 0xff);
		// ft_draw_pixel(game, game->ray->x + 1, game->ray->y, 0xff);
		// ft_draw_pixel(game, game->ray->x, game->ray->y + 1, 0xff);
		// ft_draw_pixel(game, game->ray->x + 1, game->ray->y + 1, 0xff);
		// ft_draw_pixel(game, game->ray->x - 1, game->ray->y, 0xff);
		// ft_draw_pixel(game, game->ray->x, game->ray->y - 1, 0xff);
		// ft_draw_pixel(game, game->ray->x - 1, game->ray->y - 1, 0xff);
		int mx = (int)(game->ray->x / TILE);
		int my = (int)(game->ray->y / TILE);
		if (my < 0 || mx < 0)
			break ;
		if (mx < 8 && my < 8 && map[my][mx] == 1)
		{
			*v_pos_x = game->ray->x;
			*v_pos_y = game->ray->y;
			*dist = ft_distance(game->player->pos_x, game->player->pos_y, game->ray->x, game->ray->y);
			dof = 8;
		}
		else
		{
			game->ray->x += game->ray->x_a;
			game->ray->y += game->ray->y_a;
			dof += 1;
		}
	}
}

int    ft_raycasting(t_game *game)
{
	int	x;
	int	y;
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

	x = 0;
	y = 0;
	game->mlx->pixel->image = mlx_new_image(game->mlx->init, WIDTH, HEIGHT);
	game->mlx->pixel->address = mlx_get_data_addr(game->mlx->pixel->image, &game->mlx->pixel->bits_per_pixel, &game->mlx->pixel->line_len, &game->mlx->pixel->endian);
	
	//grid drawing
	while (y < 8)
	{
		x = 0;
		while (x < 8)
		{
			if(map[y][x] == 1)
				ft_draw_square(x * TILE, y * TILE, game, ft_convert_rgb(228, 208, 10));
			else
				ft_draw_square(x * TILE, y * TILE, game, ft_convert_rgb(255, 255, 255));
			x++;
		}
		y++;
	}

	//player
	ft_draw_point(game);
	int i = 0;

	//intersection loop
	while (i < WIDTH)
	{
		double dist_h = 1000000;
		double dist_v = 1000000;
		double dist;
		double height;
		double begin_draw;
		double end_draw;
		double wall_y;
		double inc;
		// game->ray->angle = game->player->angle - RADIAN * 6 + RADIAN * 6 * i;
		game->ray->angle = game->player->angle - (game->player->half_fov) + (game->player->half_fov * 2) * i / WIDTH;
		// game->ray->angle = game->player->angle - game->player->half_fov;
		// inc = game->ray->÷÷
		if (game->ray->angle < 0)
			game->ray->angle += 2 * PI;
		if (game->ray->angle > 2 * PI)
			game->ray->angle -= 2 * PI;
		double h_pos_x = game->player->pos_x;
		double h_pos_y = game->player->pos_y;
		ft_check_horizontal(game, &h_pos_x, &h_pos_y, &dist_h);
		double v_pos_x = game->player->pos_x;
		double v_pos_y = game->player->pos_y;
		ft_check_vertical(game, &v_pos_x, &v_pos_y, &dist_v);
		if (dist_h < dist_v)
		{
			// printf("I'm horizontal\n");
			game->ray->x = (int)h_pos_x;
			game->ray->y = (int)h_pos_y;
			dist = dist_h;
		}
		if (dist_h > dist_v)
		{
			// printf("I'm vertical\n");
			game->ray->x = (int)v_pos_x;
			game->ray->y = (int)v_pos_y;
			dist = dist_v;
		}
		// printf("pos_x = %f, pos_y = %f, ray_x = %d, ray_y = %d\n", game->player->pos_x, game->player->pos_y, game->ray->x, game->ray->y);
		ft_draw_line_ddb(game->player->pos_x, game->player->pos_y, game->ray->x, game->ray->y, ft_convert_rgb(0, 0, 0), game);
		height = (TILE * 320 / dist) * 277;
		begin_draw = -height / 2 + HEIGHT / 2;
		end_draw = height / 2 + HEIGHT / 2;
		game->wall[i].height = height;
		game->wall[i].top = begin_draw;
		game->wall[i].bottom = end_draw;
		game->wall[i].distance = dist;
		game->wall[i].x = game->ray->x;
		game->wall[i].y = game->ray->y;
		i++;
		// game->ray->angle += RADIAN * 6;
		game->ray->angle += game->player->fov / WIDTH;
		if (game->ray->angle < 0)
			game->ray->angle += 2 * PI;
		if (game->ray->angle > 2 * PI)
			game->ray->angle -= 2 * PI;
	}
	i = 0;
	// int wall_width;
	// while (i < 15)
	// {
	// 	game->wall[i].distance = game->wall[i].distance * cos(game->player->angle - game->ray->angle);
	// 	wall_width = (game->wall[i].distance / 200) * 64;
	// 	ft_draw_rectangle(game->wall[i].x, game->wall[i].y, wall_width, game->wall[i].height, ft_convert_rgb(255,160,122), game);
	// 	i++;
	// }
	//direction line
	ft_draw_line_ddb(game->player->pos_x, game->player->pos_y,game->player->pos_x +  cos(game->player->angle) * 50,game->player->pos_y +  sin(game->player->angle) * 50 , ft_convert_rgb(00, 0xff, 00), game);
	
	mlx_put_image_to_window(game->mlx->init, game->mlx->window, game->mlx->pixel->image, 0, 0);
	mlx_destroy_image(game->mlx->init, game->mlx->pixel->image);
	return (0);
}