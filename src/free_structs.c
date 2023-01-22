/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 18:46:25 by abaioumy          #+#    #+#             */
/*   Updated: 2023/01/21 18:46:55 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	ft_free_structs(t_game *game)
{
    free(game->mlx->window);
    free(game->mlx->init);
    free(game->mlx);
    free(game->player);
    free(game->ray);
    free(game->data);
    free(game);
}