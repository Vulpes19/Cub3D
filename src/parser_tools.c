/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:05:20 by mbaioumy          #+#    #+#             */
/*   Updated: 2023/01/23 14:59:44 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"

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
	// free(data);
}

void	ft_free_parse_error(t_parse *data)
{
	free(data->tmp);
	freethis1(data->textures_colors);
	free(data->ea);
	free(data->so);
	free(data->we);
	free(data->no);
	printf("%s %s %s\n", data->floor[0], data->floor[1], data->floor[2]);
	if (data->floor)
		freethis1(data->floor);
	if (data->ceiling)
		freethis1(data->ceiling);
}
