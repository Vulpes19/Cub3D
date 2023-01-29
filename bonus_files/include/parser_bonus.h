/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaioumy <mbaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 19:17:19 by mbaioumy          #+#    #+#             */
/*   Updated: 2023/01/27 14:48:02 by mbaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include <stdlib.h>
# include "game.h"

enum		e_bool	ft_init_parsing(int argc, char **argv, t_game *game);
void		ft_read_map(t_parse *data);
t_status	ft_sn_border(char *map);
t_status	ft_ew_border(char *map);
t_status	ft_examine_box_sn(t_parse *data, int i, int j);
void		ft_mapname_error(void);
int			ft_mapname_protection(char *name);
void		ft_paths(t_parse *data, char **path);
t_status	ft_organize(t_parse *data);
t_status	ft_check_colors(char **rgb);
void		ft_free_map_error(t_parse *data);
void		ft_free_parse_error(t_parse *data);
int			ft_is_space(char c);
void		ft_free_map_error(t_parse *data);
void		ft_map_error(t_parse *data);
void		freethis_int(int **str);
t_status	ft_examine_line(char *map, size_t index);

#endif
