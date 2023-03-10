/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:31:07 by abaioumy          #+#    #+#             */
/*   Updated: 2023/01/29 20:43:31 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# define WIDTH 1080
# define HEIGHT 720
# include <mlx.h>
# include <stdint.h>
# include "game.h"

typedef struct s_rectangle
{
	int	x;
	int	y;
	int	width;
	int	height;
	int	color;
}	t_rectangle;

void	ft_draw_pixel(t_game *game, int x, int y, int color);
int		ft_convert_rgb(uint8_t red, uint8_t green, uint8_t blue);
void	ft_vertical_intersections(t_game *game);
void	ft_horizontal_intersections(t_game *game);
void	ft_calculate_distance(t_game *game, char direction);
int		ft_raycasting(t_game *game);
void	ft_draw_rectangle(t_rectangle rect, t_game *game);
double	ft_distance(double x1, double y1, double x2, double y2);
void	ft_load_texture(t_game *game);
void	ft_draw_walls(t_game *game, int i);
int		ft_get_color(int x, int y, int height, t_texture *texture);
void	ft_get_floor_color(t_game *game);
void	ft_get_ceiling_color(t_game *game);
void	ft_assign_texture(t_game *game, int ray, char direction);
void	ft_load_images(t_game *game);

#endif