/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaioumy <mbaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:20:09 by mbaioumy          #+#    #+#             */
/*   Updated: 2023/01/24 19:09:09 by mbaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"

enum e_bool	ft_start(t_game *game, char **argv)
{
	if (ft_mapname_protection(argv[1]))
	{
		game->data = malloc(sizeof(t_parse));
		game->data->file = open(argv[1], O_RDONLY);
		if (game->data->file > 0)
		{
			ft_read_map(game->data);
			return (TRUE);
		}
		else
			ft_file_error(game->data);
	}
	ft_mapname_error(game->data);
	return (FALSE);
}

enum e_bool	ft_init_parsing(int argc, char **argv, t_game *game)
{
	if (argc == 2)
		return (ft_start(game, argv));
	else
	{
		ft_arguments_error(game->data);
		return (FALSE);
	}
	return (TRUE);
}
