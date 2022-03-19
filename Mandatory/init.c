/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcherki <mcherki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:35:11 by mcherki           #+#    #+#             */
/*   Updated: 2022/03/19 16:14:44 by mcherki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_init(t_game *game)
{
	game->n_player = 0;
	game->n_colect = obj_check(game, 'C');
	game->n_exit = 0;
	game->map_h = 0;
	game->map_w = 0;
	game->p_x = 0;
	game->p_y = 0;
}
