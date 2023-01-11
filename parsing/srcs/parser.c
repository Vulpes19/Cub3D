/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaioumy <mbaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:07:04 by mbaioumy          #+#    #+#             */
/*   Updated: 2023/01/11 21:22:14 by mbaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser.h"
#include "../include/libft.h"

status	ft_examineLine(char	*map, size_t index)
{
	status	flag;

	flag = GOOD;
	if (index == 0 || index == (ft_strlen(map) - 1))
		flag = ft_SN_border(map);
	else
		flag = ft_EW_border(map);
	return (flag);
}

status	ft_examineMap(t_parse *data)
{
	size_t		i;
	status	flag;	
	size_t		j;

	i = 0;
	flag = GOOD;
	while (flag == GOOD && data->map[i])
	{
		j = 0;
		flag = ft_examineLine(data->map[i], i);
		if (i > 0)
		{
			while (flag == GOOD && data->map[i][j])
			{
				if (data->map[i][j] == '0')
				{
					flag = ft_examineBox_SN(data->map[i + 1][j], data->map[i - 1][j]);
					
					// flag = ft_examineBox_EW(data->map[i][j + 1], data->map[i][j - 1]);
				}
				j++;
			}
		}
		i++;
	}
	return (flag);
}

void    ft_readMap(t_parse *data)
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
	if (ft_examineMap(data) == GOOD)
		printf("all good\n");
	else
		printf("error\n");
	system ("leaks test");
}
