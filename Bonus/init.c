/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcherki <mcherki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:35:11 by mcherki           #+#    #+#             */
/*   Updated: 2022/03/17 15:14:03 by mcherki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	map_init(t_game *game)
{
	game->n_player = 0;
	game->n_colect = obj_check(game, 'C');
	game->n_exit = 0;
	game->map_h = 0;
	game->map_w = 0;
	game->p_x = 0;
	game->p_y = 0;
	game->e_x = 0;
	game->e_y = 0;
	game->moves = 0;
	game->loop = 0;
	game->pos_enemies = 1;
	game->count = 0;
}
