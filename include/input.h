/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:25:56 by abaioumy          #+#    #+#             */
/*   Updated: 2023/01/22 20:19:54 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# define W_KEY 13
# define S_KEY 1
# define D_KEY 2
# define A_KEY 0
# define UP_ARROW 126
# define DOWN_ARROW 125
# define RIGHT_ARROW 124
# define LEFT_ARROW 123

# include <mlx.h>
# include "game.h"

int		ft_input_handler(int keycode, t_game *game);
void	ft_check_w_collision(t_game *game, int mx, int my);
void	ft_check_s_collision(t_game *game, int mx, int my);
void	ft_check_a_collision(t_game *game, int mx, int my);
void	ft_check_d_collision(t_game *game, int mx, int my);

#endif