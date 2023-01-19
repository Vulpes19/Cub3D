/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaioumy <mbaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:07:04 by mbaioumy          #+#    #+#             */
/*   Updated: 2023/01/19 16:06:54 by mbaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser.h"
#include "../include/libft.h"

t_status	ft_parse(t_parse *data)
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

void	ft_read_map(t_parse *data)
{
	if (ft_parse(data) == GOOD)
	{	
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
		ft_free_map_error(data);
	}
	else
		printf("parsing error\n");
}
