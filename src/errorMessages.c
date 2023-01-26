/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorMessages.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 19:18:42 by mbaioumy          #+#    #+#             */
/*   Updated: 2023/01/26 16:23:30 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"

void	ft_file_error(t_parse *data)
{
	ft_putstr_fd("Error: File could not be opened or doesn't exist.\n",
		STDERR_FILENO);
	free(data);
	exit(EXIT_FAILURE);
}

void	ft_arguments_error(t_parse *data)
{
	ft_putstr_fd("Error: Not enough arguments.\n", STDERR_FILENO);
	free(data);
	exit(EXIT_FAILURE);
}

void	ft_mapname_error(t_parse *data)
{
	ft_putstr_fd("Error: File name is invalid!\n", STDERR_FILENO);
	(void)data;
	// ft_free_map_error(data);
	exit(EXIT_FAILURE);
}

void	ft_map_error(t_parse *data)
{
	ft_putstr_fd("Error: Map is invalid!\n", STDERR_FILENO);
	ft_free_parse_error(data);
	exit(EXIT_FAILURE);
}
