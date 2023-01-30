/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norme.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaioumy <mbaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:06:10 by abaioumy          #+#    #+#             */
/*   Updated: 2023/01/30 14:30:20 by mbaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"

void	ft_parse_norme(t_parse *data, int x, int y)
{
	data->player_x = x;
	data->player_y = y;
	data->player_direction = data->map[y][x];
	data->player_count++;
}

void	ft_test_map(char *previous_line, char *next_line)
{
	if (next_line && ft_strcmp(next_line, "\n") == 0)
	{
		if (ft_sn_border(previous_line) == ERROR)
		{
			ft_putstr_fd("Error: map is not closed\n", STDERR_FILENO);
			exit(1);
		}
	}
	else if (previous_line && ft_strcmp(previous_line, "\n") == 0)
	{
		if (ft_sn_border(next_line) == ERROR)
		{
			ft_putstr_fd("Error: map is not closed\n", STDERR_FILENO);
			exit(1);
		}
	}
}

void	ft_check_player(t_parse *data, int x, int y)
{
	if (data->map[y - 1] && data->map[y - 1][x] == '0'
		&& data->map[y + 1] && data->map[y + 1][x] == '0'
		&& data->map[y][x + 1] && data->map[y][x + 1] == '0'
		&& data->map[y][x - 1] && data->map[y][x - 1] == '0')
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
