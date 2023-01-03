/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:48:37 by abaioumy          #+#    #+#             */
/*   Updated: 2023/01/03 10:50:57 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
#define WINDOW_H

#include <mlx.h>
#include <stdlib.h>

typedef struct s_mlx
{
    void	*init;
	void	*window;
}   t_mlx;

#endif