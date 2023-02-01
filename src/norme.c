/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norme.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:06:10 by abaioumy          #+#    #+#             */
/*   Updated: 2023/02/01 19:10:44 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"
#include <string.h>

void	ft_parse_norme(t_parse *data, int x, int y)
{
	data->player_x = x;
	data->player_y = y;
	data->player_direction = data->map[y][x];
	data->player_count++;
}

int	ft_isallspaces(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] == ' ' || line[i] == '\t')
			i++;
		else
			return (0);
	}
	return (1);
}

void	ft_test_map(char *previous_line, t_parse *data)
{
	if (data->buff && (ft_strcmp(data->buff, "\n") == 0
			|| ft_isallspaces(data->buff)))
	{
		if (ft_sn_border(previous_line) == ERROR)
		{
			ft_putstr_fd("Error: map is not closed\n", STDERR_FILENO);
			exit(1);
		}
		else if (ft_strcmp(data->buff, "\n") == 0)
			data->map_length--;
	}
	else if (previous_line && (ft_strcmp(previous_line, "\n") == 0
			|| ft_isallspaces(previous_line)))
	{
		if (ft_sn_border(data->buff) == ERROR)
		{
			ft_putstr_fd("Error: map is not closed\n", STDERR_FILENO);
			exit(1);
		}
		else
			data->map_length--;
	}
}

void	ft_check_player(t_parse *data, int x, int y)
{
	if ((data->map[y - 1] && data->map[y - 1][x] == '0')
		|| (data->map[y + 1] && data->map[y + 1][x] == '0')
		|| (data->map[y][x + 1] && data->map[y][x + 1] == '0')
		|| (data->map[y][x - 1] && data->map[y][x - 1] == '0'))
		return ;
	ft_putstr_fd("Error: player is trapped!\n", STDERR_FILENO);
	exit(1);
}

t_status	ft_check_colors_norm(char **tmp)
{
	int	j;
	int	color;

	j = 0;
	color = -1;
	while (tmp[j])
	{
		if (!tmp[2] || ft_isallspaces(tmp[j]))
			return (ERROR);
		if (ft_check_digit(tmp[j]) == ERROR)
			return (ERROR);
		color = ft_atoi(tmp[j++]);
		if (color < 0 || color > 255)
		{
			freethis1(tmp);
			return (ERROR);
		}
	}
	freethis1(tmp);
	return (GOOD);
}
