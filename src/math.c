/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:09:28 by abaioumy          #+#    #+#             */
/*   Updated: 2023/01/16 15:40:35 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

double	ft_better_sqrt(double nbr)
{
	long	i;
	double	x2;
	double	y;
	const double threehalfs = 1.5;

	x2 = nbr * 0.5;
	y = nbr;
	i = *(long *)&y;
	i = 0x5f3759df - (i >> 1);
	y = *(double *)&i;
	y = y * (threehalfs - (x2 * y * y));
	return (1 / y);
}

double ft_distance(double x1, double y1, double x2, double y2)
{
	// return (sqrt( (x2 - x1) * (y2 - y1) + (y2 - y1) * (y2 - y1) ));
	return (sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)));
}

// double ft_distance_abs(t_game *game)
// {
// 	return (fabs(game->player->pos_x - game->ray->x) / cos(game->ray->angle));
// }
