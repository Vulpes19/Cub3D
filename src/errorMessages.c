/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorMessages.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 19:18:42 by mbaioumy          #+#    #+#             */
/*   Updated: 2023/01/23 11:51:07 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"

void	ft_file_error(void)
{
	ft_putstr_fd("Error: File could not be opened or doesn't exist.\n",
		STDERR_FILENO);
}

void	ft_arguments_error(void)
{
	ft_putstr_fd("Error: Not enough arguments.\n", STDERR_FILENO);
}

void	ft_mapname_error(void)
{
	ft_putstr_fd("Error: File name is invalid!\n", STDERR_FILENO);
}
