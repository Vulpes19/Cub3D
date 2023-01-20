/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:20:09 by mbaioumy          #+#    #+#             */
/*   Updated: 2023/01/20 15:17:55 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"

enum t_bool	ft_init_parsing(int argc, char **argv, t_game *game)
{
	if (argc == 2)
	{
		if (ft_mapname_protection(argv[1]))
		{
			game->data = malloc(sizeof(t_parse));
			game->data->file = open(argv[1], O_RDONLY);
			if (game->data->file > 0)
				ft_read_map(game->data);
			else
				ft_file_error();
			// free(game->data);
		}
		else
		{
			ft_mapname_error();
			return (FALSE);
		}
	}
	else
	{
		ft_arguments_error();
		return (FALSE);
	}
	return (TRUE);
}
