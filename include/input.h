/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:25:56 by abaioumy          #+#    #+#             */
/*   Updated: 2023/01/05 16:42:14 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# define W_KEY 13
# define S_KEY 1
# define D_KEY 2
# define A_KEY 0

#include <mlx.h>
#include "game.h"

int    ft_input_handler(int keycode, t_game *game);

#endif