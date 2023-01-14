/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaioumy <mbaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 19:17:19 by mbaioumy          #+#    #+#             */
/*   Updated: 2023/01/14 15:31:21 by mbaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include <stdlib.h>

typedef enum s_status
{
	GOOD,
	ERROR
}	t_status;

typedef struct s_parse
{
	int			file;
	char		*buff;
	char		*tmp;
	char		*no;
	char		**d_tmp;
	char		*so;
	char		*we;
	char		*ea;
	char		*floor;
	char		*cieling;
	char		**map;
	char		**textures_colors;
	char		*leaks;
	int			i;
	int			j;
	t_status	flag;
}	t_parse;

void		ft_read_map(t_parse *data);
t_status	ft_sn_border(char *map);
t_status	ft_ew_border(char *map);
t_status	ft_examine_box_sn(char N, char S);
void		ft_mapname_error(void);
int			ft_mapname_protection(char *name);
void		ft_paths(t_parse *data, char *path);
void		ft_colors(t_parse *data, char *color);
t_status	ft_organize(t_parse *data);

#endif
