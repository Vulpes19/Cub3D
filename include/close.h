/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:47:39 by abaioumy          #+#    #+#             */
/*   Updated: 2023/01/03 10:55:24 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLOSE_H
#define CLOSE_H

#define ESC 53
#include "window.h"
#include <stdlib.h>

int	ft_close_esc(int keycode, t_mlx *mlx);
int	ft_close_x(t_mlx *mlx);

#endif