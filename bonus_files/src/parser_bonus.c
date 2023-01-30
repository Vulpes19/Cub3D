/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:07:04 by mbaioumy          #+#    #+#             */
/*   Updated: 2023/01/30 15:21:24 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_bonus.h"
#include "libft_bonus.h"

t_status	ft_parse(t_parse *data)
{
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

t_status	ft_player_position(t_parse *data)
{
	int	x;
	int	y;

	y = -1;
	data->player_count = 0;
	while (data->map[++y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'N' || data->map[y][x] == 'E'
				|| data->map[y][x] == 'W' || data->map[y][x] == 'S')
			{
				ft_check_player(data, x, y);
				data->player_x = x;
				data->player_y = y;
				data->player_direction = data->map[y][x];
				data->player_count++;
			}
			x++;
		}
	}
	if (data->player_count == 1)
		return (GOOD);
	return (ERROR);
}

void	ft_parse_map(t_parse *data)
{
	char	*previous_line;

	data->map_length = 0;
	data->tmp = ft_strdup("");
	while (data->buff)
	{
		previous_line = ft_strdup(data->buff);
		data->leaks = data->tmp;
		data->tmp = ft_strjoin(data->tmp, data->buff);
		free(data->buff);
		data->buff = get_next_line(data->file);
		ft_test_map(previous_line, data);
		free(previous_line);
		free(data->leaks);
		data->map_length++;
	}
	free(data->buff);
	data->map = ft_split(data->tmp, '\n');
}

void	ft_read_map(t_parse *data)
{
	if (ft_parse(data) == GOOD)
	{	
		ft_parse_map(data);
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
