/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcherki <mcherki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 12:46:57 by mcherki           #+#    #+#             */
/*   Updated: 2022/03/19 16:41:33 by mcherki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*word_dup(char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char	**map_allo(t_game *game, char *line)
{
	int	i;
	int	k;

	i = 0;
	k = 1;
	while (line[i])
	{
		if (line[i] == '\n')
			k++;
		i++;
	}
	game->map = malloc((k + 1) * sizeof(char *));
	if (!game->map)
		return (NULL);
	return (map_filling_up(line, game));
}

char	**map_filling_up(char *line, t_game *game)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (line[i])
	{
		if (line[i] == '\n' && line[i] != '\0')
		{
			game->map[k] = word_dup(line, j, i);
			j = i + 1;
			k++;
		}
		i++;
	}
	return (game->map[k] = word_dup(line, j, i), game->map[++k] = 0, game->map);
}

void	check_enemy(t_game game)
{
	ft_printf("we can't find the enemy!!");
	free(game.map);
	exit(EXIT_FAILURE);
}
