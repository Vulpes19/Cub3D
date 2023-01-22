/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:31:07 by abaioumy          #+#    #+#             */
/*   Updated: 2023/01/22 20:11:00 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
#define DRAW_H

#define WIDTH 1080
#define HEIGHT 720
#include <mlx.h>
#include <stdint.h>
#include "game.h"

typedef struct s_rectangle
{
    int x;
    int y;
    int width;
    int height;
    int color;
}        t_rectangle;

typedef struct s_mini_map
{
    int x;
    int y;
    int mini_map_x;
    int mini_map_y;
    int map_x;
    int map_y;
    int size;
}        t_mini_map;

void	ft_draw_pixel(t_game *game, int x, int y, int color);
void	ft_draw_pixel_mini_map(t_game *game, int x, int y, int color);
int		ft_convert_rgb(uint8_t red, uint8_t green, uint8_t blue);
void	ft_vertical_intersections(t_game *game);
void	ft_horizontal_intersections(t_game *game);
void	ft_calculate_distance(t_game *game, char direction);
int		ft_raycasting(t_game *game);
// void	ft_draw_line( int x, int draw_start, int draw_end, int color, t_game *game);
// void	ft_draw_line(int x, int y, int end_x, int end_y, int color, t_game *game);
void	ft_draw_point(t_game *game, int mini_map_x, int mini_map_y);
void	ft_draw_square(int x, int y, t_game *game, int color);
char	*ft_itoa(int n);
void	ft_draw_rectangle(t_rectangle rect, t_game *game);
double ft_distance(double x1, double y1, double x2, double y2);
void	ft_draw_grid(t_game *game);
void    ft_load_texture(t_game *game);
void	ft_draw_walls(t_game *game, int i);
int     ft_get_color(int x, int y, int height, t_game *game);
void    ft_get_floor_color(t_game *game);
void    ft_get_ceiling_color(t_game *game);

#endif