/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:14:17 by abaioumy          #+#    #+#             */
/*   Updated: 2023/01/03 10:28:02 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <limits.h>
#include <stdlib.h>
#include "error.h"

int	main(void)
{
	void	*init;
	void	*window;

	init = mlx_init();
	if (!init)
	{
		ft_putstr_fd("failed to init mlx", 2);
		exit(1);
	}
	window = mlx_new_window(init, 1920, 1080, "still thinking of a name");
	if (!window)
	{
		ft_putstr_fd("failed to create window", 2);
		exit(1);
	}
	mlx_loop(init);
}