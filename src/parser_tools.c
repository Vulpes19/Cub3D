/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaioumy <mbaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:05:20 by mbaioumy          #+#    #+#             */
/*   Updated: 2023/01/19 16:07:09 by mbaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/parser.h"

void	ft_free_map_error(t_parse *data)
{
	freethis1(data->map);
	free(data->tmp);
	freethis1(data->textures_colors);
	free(data->no);
	free(data->so);
	free(data->we);
	free(data->ea);
	freethis1(data->cieling);
	freethis1(data->floor);
}

void	ft_free_parse_error(t_parse *data)
{
	free(data->tmp);
	freethis1(data->textures_colors);
	free(data->ea);
	free(data->so);
	free(data->we);
	free(data->no);
	if (data->floor)
		freethis1(data->floor);
	if (data->cieling)
		freethis1(data->cieling);
}
