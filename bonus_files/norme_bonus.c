/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norme.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:06:10 by abaioumy          #+#    #+#             */
/*   Updated: 2023/01/27 15:07:20 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"

void	ft_parse_norme(t_parse *data, int x, int y)
{
	data->player_x = x;
	data->player_y = y;
	data->player_direction = data->map[y][x];
	data->player_count++;
}

t_status	ft_examine_map(t_parse *data)
{
	size_t		i;
	t_status	flag;	
	size_t		j;

	i = 0;
	flag = GOOD;
	while (flag == GOOD && data->map[i])
	{
		flag = ft_examine_line(data->map[i], i);
		j = 0;
		while (flag == GOOD && data->map[i][j])
		{
			if (data->map[i][j] == '0')
				flag = ft_examine_box_sn(data, i, j);
			j++;
		}
		i++;
	}
	return (flag);
}
