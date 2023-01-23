/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:47:39 by abaioumy          #+#    #+#             */
/*   Updated: 2023/01/23 12:05:46 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLOSE_H
# define CLOSE_H

# define ESC 53
# include <stdlib.h>
# include "draw.h"

void	ft_close_esc(t_game *game);
int		ft_close_x(t_game *mlx);
void	ft_free_textures(t_game *game);
void	ft_free_game(t_game *game);

#endif