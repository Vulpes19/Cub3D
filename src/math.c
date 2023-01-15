/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:09:28 by abaioumy          #+#    #+#             */
/*   Updated: 2023/01/15 16:10:07 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

double ft_distance(double x1, double y1, double x2, double y2)
{
	// return (sqrt( (x2 - x1) * (y2 - y1) + (y2 - y1) * (y2 - y1) ));
	return (sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)));
}