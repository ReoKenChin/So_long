/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcherki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 20:55:24 by mcherki           #+#    #+#             */
/*   Updated: 2022/03/14 17:32:01 by mcherki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	walls_check(t_game *game)
{
	int	i;
	int	j;
	int	len;

	j = 0;
	i = 0;
	while (game->map[i] != '\0')
		i++;
	while (game->map[0][j] != '\0' && game->map[i - 1][j] != '\0')
	{
		if (game->map[0][j] != '1' || game->map[i - 1][j] != '1')
			return (0);
		j++;
	}
	i = 0;
	len = ft_strlen(game->map[i]) - 1;
	while (game->map[i] != '\0')
	{
		if (game->map[i][0] != '1' || game->map[i][len] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_rectangular(t_game *game)
{
	int	lines;

	lines = 1;
	while (game->map[lines])
	{
		if (ft_strlen(game->map[0]) != ft_strlen(game->map[lines]))
			return (0);
		lines++;
	}
	return (1);
}

int	content_check(t_game *game)
{
	if (obj_check(game, 'P') > 1)
		return (ft_printf("the map has more than 1 player!!"), 1);
	else if (obj_check(game, 'E') > 1)
		return (ft_printf("the map has more than 1 exit!!"), 1);
	if (!obj_check(game, 'P') && !obj_check(game, 'C') && !obj_check(game, 'E'))
		return (ft_printf("all of the objects are missing!!"), 1);
	else if (!obj_check(game, 'P') && !obj_check(game, 'C'))
		return (ft_printf("the player and the collectable are missing!!"), 1);
	else if (!obj_check(game, 'P') && !obj_check(game, 'E'))
		return (ft_printf("the player and the exit are missing!!"), 1);
	else if (!obj_check(game, 'C') && !obj_check(game, 'E'))
		return (ft_printf("the collactable and the exit are missing!!"), 1);
	else if (!obj_check(game, 'P'))
		return (ft_printf("the player is missing!!"), 1);
	else if (!obj_check(game, 'C'))
		return (ft_printf("the collectable is missing!!"), 1);
	else if (!obj_check(game, 'E'))
		return (ft_printf("the exit is missing!!"), 1);
	return (0);
}
