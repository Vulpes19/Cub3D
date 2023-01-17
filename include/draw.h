/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:31:07 by abaioumy          #+#    #+#             */
/*   Updated: 2023/01/17 11:42:16 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
#define DRAW_H

#define WIDTH 1080
#define HEIGHT 720
#include <mlx.h>
#include <stdint.h>
#include "game.h"

void	ft_draw_pixel(t_game *game, int x, int y, int color);
int		ft_convert_rgb(uint8_t red, uint8_t green, uint8_t blue);
int		ft_raycasting(t_game *game);
void	ft_draw_line( int x, int draw_start, int draw_end, int color, t_game *game);
void	ft_draw_line_ddb(int x, int y, int end_x, int end_y, int color, t_game *game);
void	ft_draw_point(t_game *game);
void	ft_draw_square(int x, int y, t_game *game, int color);
char	*ft_itoa(int n);
void    ft_draw_rectangle(int x, int y, int width, int height, int color, t_game *game);
double ft_distance(double x1, double y1, double x2, double y2);
double ft_distance_abs(t_game *game);
void	ft_draw_grid(t_game *game);
void    ft_load_texture(t_game *game);
void	ft_draw_walls(t_game *game);

#endif