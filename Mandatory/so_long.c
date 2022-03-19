/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcherki <mcherki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 12:42:47 by mcherki           #+#    #+#             */
/*   Updated: 2022/03/19 16:38:07 by mcherki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	validate(t_game *game)
{
	if (!check_rectangular(game))
	{
		ft_printf("the map is not rectangular!!\n");
		exit(EXIT_FAILURE);
	}
	if (!map_correct_form(game))
		exit(EXIT_FAILURE);
	if (line_check(game))
		exit(EXIT_FAILURE);
	if (map_0(game))
		exit(EXIT_FAILURE);
	if (!walls_check(game))
	{
		ft_printf("Walls error!\n");
		exit(EXIT_FAILURE);
	}
	if (content_check(game))
		exit(EXIT_FAILURE);
}

int	check_extention(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	if (str[i - 1] == 'r' && str[i - 2] == 'e' && str[i - 3] == 'b'
		&& str[i - 4] == '.')
		return (1);
	return (0);
}

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
}

void	win(t_game *game)
{
	ft_printf("Congratulations, you found all the Eggs and the exit.\n");
	ft_printf("You won!\n");
	ft_printf("Is %d moves really the best you can do?\n", game->moves);
	exit(EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac == 2)
	{
		if (!check_extention(av[1]))
			return (ft_printf("the extention is invalid!\n"), 0);
	}
	else
		return (ft_printf("Error more or less than 2 arguments!"), 0);
	game.map = read_map(&game, av[1]);
	validate(&game);
	map_init(&game);
	player_pos(&game);
	game.mlx = mlx_init();
	dynamic_map(&game);
	init_textures(&game);
	mlx_hook(game.win, 17, (1L << 2), destroy_window, &game);
	mlx_hook(game.win, 2, (1L << 0), m_hook, &game);
	mlx_loop(game.mlx);
	free_map(&game);
	free(game.mlx);
}
