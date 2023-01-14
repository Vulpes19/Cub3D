/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorMessages.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaioumy <mbaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 19:18:42 by mbaioumy          #+#    #+#             */
/*   Updated: 2023/01/14 15:23:20 by mbaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser.h"
#include "../include/libft.h"

void	ft_file_error(void)
{
	ft_putstr("Error: File could not be opened or doesn't exist.\n");
}

void	ft_arguments_error(void)
{
	ft_putstr("Error: Not enough arguments.\n");
}

void	ft_mapname_error(void)
{
	ft_putstr("Error: File name is invalid!\n");
}
