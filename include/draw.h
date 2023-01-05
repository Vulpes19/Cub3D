/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:31:07 by abaioumy          #+#    #+#             */
/*   Updated: 2023/01/05 17:12:40 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
#define DRAW_H

#define WIDTH 1080
#define HEIGHT 720
#include <mlx.h>
#include <stdint.h>
#include "game.h"

typedef struct s_pixel
{
	void	*image;
	char	*address;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
}	t_pixel;

typedef struct s_mlx
{
    void	*init;
	void	*window;
    t_pixel *pixel;
}   t_mlx;

void	ft_draw_pixel(t_pixel *pixel, int x, int y, int color);
int		ft_convert_rgb(uint8_t red, uint8_t green, uint8_t blue);
int		ft_raycasting(t_game *game, t_mlx *mlx);
void	ft_draw_line( int x, int draw_start, int draw_end, int color, t_mlx *mlx);

#endif