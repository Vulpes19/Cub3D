/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaioumy <mbaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:07:04 by mbaioumy          #+#    #+#             */
/*   Updated: 2023/01/24 16:02:41 by mbaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"

t_status	ft_parse(t_parse *data)
{
	int	i;

	i = 1;
	data->buff = get_next_line(data->file);
	if (data->buff == NULL)
		return (ERROR);
	data->tmp = ft_strdup("");
	while (ft_strncmp(data->buff, "1", 1) != 0)
	{
		data->leaks = data->tmp;
		data->tmp = ft_strjoin(data->tmp, data->buff);
		free(data->leaks);
		free(data->buff);
		data->buff = get_next_line(data->file);
		if (data->buff == NULL)
			return (ERROR);
		i++;
	}
	data->textures_colors = ft_split(data->tmp, '\n');
	if (ft_organize(data) == GOOD)
	{
		free(data->tmp);
		return (GOOD);
	}
	ft_free_parse_error(data);
	return (ERROR);
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

t_status	ft_player_position(t_parse *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'N' || data->map[y][x] == 'E'
				|| data->map[y][x] == 'W' || data->map[y][x] == 'S')
			{
				data->player_x = x;
				data->player_y = y;
				data->player_direction = data->map[y][x];
				return (GOOD);
			}
			x++;
		}
		y++;
	}
	return (ERROR);
}

void	ft_read_map(t_parse *data)
{
	if (ft_parse(data) == GOOD)
	{	
		data->map_length = 0;
		data->tmp = ft_strdup("");
		while (data->buff)
		{
			data->leaks = data->tmp;
			data->tmp = ft_strjoin(data->tmp, data->buff);
			free(data->leaks);
			free(data->buff);
			data->buff = get_next_line(data->file);
			if (data->buff && ft_strncmp(data->buff, "\n", 1) == 0)
			{
				free(data->buff);
				data->buff = get_next_line(data->file);
				data->map_length--;
			}
			data->map_length++;
		}
		free(data->buff);
		data->map = ft_split(data->tmp, '\n');
		if (ft_examine_map(data) == GOOD
			&& ft_player_position(data) == GOOD)
		{
			return ;
		}
		else
		{
			ft_map_error(data);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		ft_putstr_fd("parsing error\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}
