/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_tools_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:05:20 by mbaioumy          #+#    #+#             */
/*   Updated: 2023/01/30 15:05:42 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"
#include "parser_bonus.h"

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] == s2[i])
			i++;
		else
			break ;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

t_status	ft_examine_line(char	*map, size_t index)
{
	t_status	flag;

	flag = GOOD;
	if (index == 0 || index == (ft_strlen(map) - 1))
		flag = ft_sn_border(map);
	else
		flag = ft_ew_border(map);
	return (flag);
}

void	ft_free_map_error(t_parse *data)
{
	freethis1(data->map);
	free(data->tmp);
	freethis1(data->textures_colors);
	free(data->no);
	free(data->so);
	free(data->we);
	free(data->ea);
	freethis1(data->ceiling);
	freethis1(data->floor);
	free(data);
}

void	ft_free_parse_error(t_parse *data)
{
	free(data->tmp);
	freethis1(data->textures_colors);
	free(data->ea);
	free(data->so);
	free(data->we);
	free(data->no);
	if (data->floor)
		freethis1(data->floor);
	if (data->ceiling)
		freethis1(data->ceiling);
}

void	freethis_int(int **str)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		free(str[i]);
		i++;
	}
	free(str);
}
