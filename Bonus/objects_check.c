/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcherki <mcherki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:40:00 by mcherki           #+#    #+#             */
/*   Updated: 2022/03/17 15:13:53 by mcherki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	obj_check(t_game *game, char c)
{
	int	obj;
	int	i;
	int	j;
	int	len;

	i = 1;
	obj = 0;
	len = ft_strlen(game->map[i]) - 1;
	while (game->map[i])
	{
		j = 1;
		while (j < len)
		{
			if (game->map[i][j] == c)
				obj++;
			j++;
		}
		i++;
	}
	return (obj);
}

int	line_check(t_game *game)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = ft_strlen(game->map[i]);
	while (game->map[i])
	{
		j = 0;
		while (j < len)
		{
			if (game->map[i][j] != '0' && game->map[i][j] != '1'
					&& game->map[i][j] != 'P'
					&& game->map[i][j] != 'C' && game->map[i][j] != 'E'
					&& game->map[i][j] != 'R')
				return (ft_printf("Invalid map!!\n"), 1);
			j++;
		}
		i++;
	}
	return (0);
}

int	map_0(t_game *game)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == '0')
				count++;
			j++;
		}
		i++;
	}
	if (count == 0)
		return (ft_printf("invalid map!!"), 1);
	return (0);
}
