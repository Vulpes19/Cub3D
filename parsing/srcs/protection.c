/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaioumy <mbaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:25:06 by mbaioumy          #+#    #+#             */
/*   Updated: 2023/01/11 21:21:05 by mbaioumy         ###   ########.fr       */
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

status	ft_EW_border(char *map)
{
	int		i;
	size_t	end;

	i = 0;
	end = ft_strlen(map) - 1;
	while (map[i] <= 32)
		i++;
	if (map[i] == '1' && map[end] == '1')
		return (GOOD);
	return (ERROR);
}

status	ft_examineBox_SN(char N, char S)
{
	if ((N == 1 && S == 1) || (N == 0 && S == 0))
		return (GOOD);
	return (ERROR);
}

status	ft_examineBox_EW(char E, char W)
{
	if ((W == 1 && E == 1) || (W == 0 && E == 0))
		return (GOOD);
	return (ERROR);
}