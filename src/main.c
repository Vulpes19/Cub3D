/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:14:17 by abaioumy          #+#    #+#             */
/*   Updated: 2023/01/03 12:39:24 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <limits.h>
#include "window.h"
#include "error.h"
#include "draw.h"
#include "close.h"
#include "game.h"

int	main(void)
{
	t_mlx		mlx;
	t_game		game;
	t_pixel		pixel;

	mlx.init = mlx_init();
	if (!mlx.init)
	{
		ft_putstr_fd("failed to init mlx", 2);
		exit(1);
	}
	mlx.window = mlx_new_window(mlx.init, 1920, 1080, "still thinking of a name");
	if (!mlx.window)
	{
		ft_putstr_fd("failed to create window", 2);
		exit(1);
	}
	pixel.image = mlx_new_image(mlx.init, 1920, 1080);
	pixel.address = mlx_get_data_addr(pixel.image, &pixel.bits_per_pixel, &pixel.line_len, &pixel.endian);
	ft_draw_pixel(&pixel, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx.init, mlx.window, pixel.image, 0, 0);
	while (1)
	{
		ft_raycasting(&game, &mlx, &pixel);
		mlx_hook(mlx.window, 17, 1L << 0, ft_close_x, &mlx);
		mlx_hook(mlx.window, 2, 1L << 0, ft_close_esc, &mlx);
		mlx_loop(mlx.init);
	}
}