/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:47:39 by abaioumy          #+#    #+#             */
/*   Updated: 2023/01/22 20:15:19 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLOSE_H
# define CLOSE_H

# define ESC 53
# include <stdlib.h>
# include "draw.h"

void	ft_close_esc(t_game *game);
int		ft_close_x(t_mlx *mlx);

#endif