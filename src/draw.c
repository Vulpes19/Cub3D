/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:31:22 by abaioumy          #+#    #+#             */
/*   Updated: 2023/01/05 16:52:55 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include <stdio.h>

void	ft_draw_pixel(t_pixel *pixel, int x, int y, int color)
{
	char	*dest;

	dest = pixel->address + (y * pixel->line_len + x * (pixel->bits_per_pixel / 8));
	*(unsigned int*)dest = color;
}

int	ft_convert_rgb(uint8_t red, uint8_t green, uint8_t blue)
{
	return (red << 16 | green << 8 | blue);
}

void	ft_draw_line(int x, int draw_start, int draw_end, int color, t_mlx *mlx)
{
	while (draw_start < draw_end)
	{
		ft_draw_pixel(&mlx->pixel, x, draw_start, color);
		draw_start++;
	}
	// mlx_put_image_to_window(mlx->init, mlx->window, mlx->pixel.image, 0, 0);
}