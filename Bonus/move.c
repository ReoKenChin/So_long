/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcherki <mcherki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:37:21 by mcherki           #+#    #+#             */
/*   Updated: 2022/03/19 11:17:11 by mcherki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_a(t_game *game)
{
	game->img_player = mlx_xpm_file_to_image
		(game->mlx, "Bonus/assets/hero_left.xpm", &game->img_w, &game->img_h);
	if (game->map[game->p_x][game->p_y - 1] == 'R')
		exit_game(game);
	move_player(game, 0, -1);
}

void	move_d(t_game *game)
{
	game->img_player = mlx_xpm_file_to_image
		(game->mlx, "Bonus/assets/hero_right.xpm", &game->img_w, &game->img_h);
	if (game->map[game->p_x][game->p_y + 1] == 'R')
		exit_game(game);
	move_player(game, 0, 1);
}

void	move_w(t_game *game)
{
	game->img_player = mlx_xpm_file_to_image
		(game->mlx, "Bonus/assets/hero_up.xpm", &game->img_w, &game->img_h);
	if (game->map[game->p_x - 1][game->p_y] == 'R')
		exit_game(game);
	move_player(game, -1, 0);
}

void	move_s(t_game *game)
{
	game->img_player = mlx_xpm_file_to_image
		(game->mlx, "Bonus/assets/hero_down.xpm", &game->img_w, &game->img_h);
	if (game->map[game->p_x + 1][game->p_y] == 'R')
		exit_game(game);
	move_player(game, 1, 0);
}

int	move_enemy(t_game *game)
{
	if (game->map[game->e_x + 1][game->e_y] == '0')
	{
		game->map[game->e_x + 1][game->e_y] = 'R';
		game->map[game->e_x][game->e_y] = '0';
		game->e_x += 1;
	}
	else if (game->map[game->e_x - 1][game->e_y] == '0')
	{
		game->map[game->e_x - 1][game->e_y] = 'R';
		game->map[game->e_x][game->e_y] = '0';
		game->e_x -= 1;
	}
	return (0);
}
