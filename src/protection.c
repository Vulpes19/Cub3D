/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaioumy <mbaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:25:06 by mbaioumy          #+#    #+#             */
/*   Updated: 2023/02/01 19:07:39 by mbaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"

t_status	ft_sn_border(char *map)
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

t_status	ft_ew_border(char *map)
{
	int		i;
	size_t	end;

	i = 0;
	end = ft_strlen(map) - 1;
	while (map[i] && map[i] <= 32)
		i++;
	while (map[end] && map[end] <= 32)
		end--;
	if ((map[i] == '1' && map[end] == '1') || map[i] == '\0')
		return (GOOD);
	else if (map[i] == '0')
		return (ERROR);
	return (ERROR);
}

t_status	ft_examine_box_sn(t_parse *data, int i, int j)
{
	if ((data->map[i + 1] && data->map[i + 1][j] <= 32) || !data->map[i + 1])
		return (ERROR);
	if ((data->map[i - 1] && data->map[i - 1][j] <= 32) || !data->map[i - 1])
		return (ERROR);
	return (GOOD);
}

int	ft_mapname_protection(char *name)
{
	if (ft_strncmp(name + (ft_strlen(name) - 4), ".cub", 4) == 0)
		return (1);
	return (0);
}

t_status	ft_check_colors(char **rgb)
{
	int		i;
	char	**tmp;

	i = 1;
	if (ft_check_commas(rgb[1]) == GOOD)
	{
		while (rgb[i])
		{
			tmp = ft_split(rgb[i++], ',');
			if (ft_check_colors_norm(tmp) == ERROR)
				return (ERROR);
		}
		if (i > 3)
			return (ERROR);
	}
	else
		return (ERROR);
	return (GOOD);
}
