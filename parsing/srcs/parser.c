/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaioumy <mbaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:07:04 by mbaioumy          #+#    #+#             */
/*   Updated: 2023/01/13 19:38:58 by mbaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser.h"
#include "../include/libft.h"

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
		data->floor = ft_strdup(data->d_tmp[1]);
		freethis1(data->d_tmp);
	}
	else if (ft_strncmp(color, "C", 1) == 0)
	{
		data->d_tmp = ft_split(color, ' ');
		data->cieling = ft_strdup(data->d_tmp[1]);
		freethis1(data->d_tmp);
	}
}

void	ft_organize(t_parse *data)
{
	int	i;

	i = 0;
	while (data->textures_colors[i])
	{
		ft_paths(data, data->textures_colors[i]);
		ft_colors(data, data->textures_colors[i]);
		i++;
	}
}

void	ft_parse(t_parse *data)
{
	int	i;

	i = 1;
	data->buff = get_next_line(data->file);
	data->tmp = ft_strdup("");
	while (i < 8)
	{
		data->leaks = data->tmp;
		data->tmp = ft_strjoin(data->tmp, data->buff);
		free(data->leaks);
		free(data->buff);
		data->buff = get_next_line(data->file);
		i++;
	}
	free(data->buff);
	data->textures_colors = ft_split(data->tmp, '\n');
	ft_organize(data);
	free(data->tmp);
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
				flag = ft_examine_box_sn(data->map[i - 1][j],
						data->map[i + 1][j]);
			j++;
		}
		i++;
	}
	return (flag);
}

void	ft_free(t_parse *data)
{
	freethis1(data->map);
	free(data->tmp);
	freethis1(data->textures_colors);
	free(data->no);
	free(data->so);
	free(data->we);
	free(data->ea);
	free(data->cieling);
	free(data->floor);
}

void	ft_read_map(t_parse *data)
{
	ft_parse(data);
	data->tmp = ft_strdup("");
	data->buff = get_next_line(data->file);
	while (data->buff)
	{
		data->leaks = data->tmp;
		data->tmp = ft_strjoin(data->tmp, data->buff);
		free(data->leaks);
		free(data->buff);
		data->buff = get_next_line(data->file);
	}
	data->map = ft_split(data->tmp, '\n');
	if (ft_examine_map(data) == GOOD)
		printf("all good\n");
	else
		printf("error\n");
	ft_free(data);
}
