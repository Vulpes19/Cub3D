/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaioumy <mbaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:25:06 by mbaioumy          #+#    #+#             */
/*   Updated: 2023/01/11 20:10:25 by mbaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser.h"
#include "../include/libft.h"

int		ft_is_space(char c)
{
	if (c <= 32)
		return (1);
	return (0);
}

status	ft_SN_border(char *map)
{
	size_t	i;
	size_t	end;

	i = 0;
	end = ft_strlen(map);
	while (map[i])
	{
		if (!ft_is_space(map[i]) && map[i] != '1')
			break ;
		i++;
	}
	if (i == end)
		return (GOOD);
	return (ERROR);
}