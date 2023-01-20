/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 19:17:19 by mbaioumy          #+#    #+#             */
/*   Updated: 2023/01/20 15:08:21 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include <stdlib.h>
#include "game.h"

enum t_bool	ft_init_parsing(int argc, char **argv, t_game *game);
void		ft_read_map(t_parse *data);
t_status	ft_sn_border(char *map);
t_status	ft_ew_border(char *map);
t_status	ft_examine_box_sn(char N, char S);
void		ft_mapname_error(void);
int			ft_mapname_protection(char *name);
void		ft_paths(t_parse *data, char *path);
void		ft_colors(t_parse *data, char *color);
t_status	ft_organize(t_parse *data);
t_status	ft_check_colors(char **rgb);
void		ft_free_map_error(t_parse *data);
void		ft_free_parse_error(t_parse *data);
int			ft_is_space(char c);
void		ft_free_map_error(t_parse *data);

#endif
