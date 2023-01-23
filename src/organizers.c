/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   organizers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 15:20:27 by mbaioumy          #+#    #+#             */
/*   Updated: 2023/01/23 15:19:33 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"

void	ft_paths(t_parse *data, char *path)
{
	if (ft_strncmp(path, "NO", 2) == 0)
	{	
		data->d_tmp = ft_split(path, ' ');
		data->no = ft_strdup(data->d_tmp[1]);
		freethis1(data->d_tmp);
	}
	else if (ft_strncmp(path, "WE", 2) == 0)
	{
		data->d_tmp = ft_split(path, ' ');
		data->we = ft_strdup(data->d_tmp[1]);
		freethis1(data->d_tmp);
	}
	else if (ft_strncmp(path, "SO", 2) == 0)
	{
		data->d_tmp = ft_split(path, ' ');
		data->so = ft_strdup(data->d_tmp[1]);
		freethis1(data->d_tmp);
	}
	else if (ft_strncmp(path, "EA", 2) == 0)
	{
		data->d_tmp = ft_split(path, ' ');
		data->ea = ft_strdup(data->d_tmp[1]);
		freethis1(data->d_tmp);
	}
}

void	ft_colors(t_parse *data, char *color)
{
	if (ft_strncmp(color, "F", 1) == 0)
	{
		data->d_tmp = ft_split(color, ' ');
		if (ft_check_colors(data->d_tmp) == GOOD)
			data->floor = ft_split(data->d_tmp[1], ',');
		else
		{
			data->floor = NULL;
			ft_putstr_fd("error: color parameters are wrong!\n", STDERR_FILENO);
		}
		freethis1(data->d_tmp);
	}
	else if (ft_strncmp(color, "C", 1) == 0)
	{
		data->d_tmp = ft_split(color, ' ');
		if (ft_check_colors(data->d_tmp) == GOOD)
			data->ceiling = ft_split(data->d_tmp[1], ',');
		else
		{
			data->ceiling = NULL;
			ft_putstr_fd("error: color parameters are wrong\n", STDERR_FILENO);
		}
		freethis1(data->d_tmp);
	}
}

t_status	ft_organize(t_parse *data)
{
	int	i;
	data->floor = NULL;
	data->ceiling = NULL;
	data->no = NULL;
	data->so = NULL;
	data->we = NULL;
	data->ea = NULL;

	i = 0;
	while (data->textures_colors[i])
	{
		ft_paths(data, data->textures_colors[i]);
		if ((ft_strncmp(data->textures_colors[i], "F", 1) == 0)
			|| ft_strncmp(data->textures_colors[i], "C", 1) == 0)
			ft_colors(data, data->textures_colors[i]);
		i++;
	}
	if (!data->ceiling || !data->floor)
		return (ERROR);
	if (!data->ea || !data->no || !data->so || !data->we)
		return (ERROR);
	return (GOOD);
}
