/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:31:07 by abaioumy          #+#    #+#             */
/*   Updated: 2023/01/11 17:29:57 by abaioumy         ###   ########.fr       */
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
void	ft_draw_point(t_game *game);
void	ft_draw_square(int x, int y, t_game *game, int color);
char	*ft_itoa(int n);

#endif