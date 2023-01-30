/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   organizers_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 15:20:27 by mbaioumy          #+#    #+#             */
/*   Updated: 2023/01/30 15:05:29 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_bonus.h"
#include "libft_bonus.h"

void	ft_paths(t_parse *data, char **path)
{
	if (ft_strcmp(path[0], "NO") == 0 && data->no == NULL)
		data->no = ft_strdup(path[1]);
	else if (ft_strcmp(path[0], "WE") == 0 && data->we == NULL)
		data->we = ft_strdup(path[1]);
	else if (ft_strcmp(path[0], "SO") == 0 && data->so == NULL)
		data->so = ft_strdup(path[1]);
	else if (ft_strcmp(path[0], "EA") == 0 && data->ea == NULL)
		data->ea = ft_strdup(path[1]);
	else
	{
		ft_putstr_fd("error: textures parameters are wrong!\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}

void	ft_colors(t_parse *data, char **color)
{
	if (ft_strcmp(color[0], "F") == 0 && data->floor == NULL)
	{
		if (ft_check_colors(color) == GOOD)
			data->floor = ft_split(color[1], ',');
		else
		{
			data->floor = NULL;
			ft_putstr_fd("error: color parameters are wrong!\n", STDERR_FILENO);
		}
	}
	else if (ft_strcmp(color[0], "C") == 0 && data->ceiling == NULL)
	{
		if (ft_check_colors(color) == GOOD)
			data->ceiling = ft_split(color[1], ',');
		else
		{
			data->ceiling = NULL;
			ft_putstr_fd("error: color parameters are wrong\n", STDERR_FILENO);
		}
	}
	else
	{
		ft_putstr_fd("error: color parameters are wrong\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}

void	ft_init_data(t_parse *data)
{
	data->no = NULL;
	data->so = NULL;
	data->we = NULL;
	data->ea = NULL;
	data->floor = NULL;
	data->ceiling = NULL;
	data->d_tmp = NULL;
}

t_status	ft_organize(t_parse *data)
{
	int	i;

	ft_init_data(data);
	i = 0;
	while (data->textures_colors[i])
	{
		data->d_tmp = ft_split(data->textures_colors[i], ' ');
		if (data->d_tmp[2])
			return (ERROR);
		if ((ft_strcmp(data->d_tmp[0], "F") == 0)
			|| ft_strcmp(data->d_tmp[0], "C") == 0)
			ft_colors(data, data->d_tmp);
		else
			ft_paths(data, data->d_tmp);
		freethis1(data->d_tmp);
		i++;
	}
	if (!data->ceiling || !data->floor)
		return (ERROR);
	if (!data->ea || !data->no || !data->so || !data->we)
		return (ERROR);
	return (GOOD);
}
