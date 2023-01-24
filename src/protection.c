/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:25:06 by mbaioumy          #+#    #+#             */
/*   Updated: 2023/01/24 09:59:53 by abaioumy         ###   ########.fr       */
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
	while (map[i] <= 32)
		i++;
	if (map[i] == '1' && map[end] == '1')
		return (GOOD);
	return (ERROR);
}

t_status	ft_examine_box_sn(char N, char S)
{
	if ((N <= 32 || N == '\0') || (S <= 32 || S == '\0'))
		return (ERROR);
	return (GOOD);
}

int	ft_mapname_protection(char *name)
{
	if (ft_strncmp(name + (ft_strlen(name) - 4), ".cub", 4) == 0)
		return (1);
	return (0);
}

// t_status	ft_check_colors(char **rgb)
// {
// 	int	i;
// 	int	color;

// 	i = 1;
// 	while (rgb[i])
// 	{
// 		color = ft_atoi(rgb[i]);
// 		if (color < 0 || color > 255)
// 			return (ERROR);
// 		i++;
// 	}
// 	if (i > 3)
// 		return (ERROR);
// 	return (GOOD);
// }

t_status    ft_check_colors(char **rgb)
{
    int     i;
    int     color;
    char    **tmp;
    int     j;

    i = 1;
    color = -1;
    while (rgb[i])
    {
        tmp = ft_split(rgb[i], ',');
        j = 0;
        while (tmp[j])
        {
            color = ft_atoi(tmp[j]);
            if (color < 0 || color > 255)
            {
                freethis1(tmp);
                return (ERROR);
            }
            j++;
        }
        i++;
    }
    if (i > 3 || j <= 2)
    {
        return (ERROR);
    }
    return (GOOD);
}