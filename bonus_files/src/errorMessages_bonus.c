/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorMessages_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 19:18:42 by mbaioumy          #+#    #+#             */
/*   Updated: 2023/01/30 15:07:47 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_bonus.h"
#include "libft_bonus.h"

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

void	ft_mapname_error(void)
{
	ft_putstr_fd("Error: File name is invalid!\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	ft_map_error(t_parse *data)
{
	ft_putstr_fd("Error: Map is invalid!\n", STDERR_FILENO);
	ft_free_parse_error(data);
	exit(EXIT_FAILURE);
}
