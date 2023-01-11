/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaioumy <mbaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 19:17:19 by mbaioumy          #+#    #+#             */
/*   Updated: 2023/01/11 20:05:29 by mbaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
#define PARSER_H

#include <stdlib.h>

typedef enum
{
	GOOD,
	ERROR
} status;

typedef struct	s_parse
{
	int 	file;
	char    *buff;
	char	*tmp;
	char    **map;
	char	*leaks;
	int		i;
	int		j;
}	t_parse ;

void    ft_readMap(t_parse *data);
status	ft_SN_border(char *map);

#endif