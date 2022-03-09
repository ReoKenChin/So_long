#include "so_long.h"

void validate(t_game *game)
{
    if (!map_correct_form(game))
        exit(0);
    if (line_check(game))
        exit(0);
    if (map_0(game))
        exit(0);
    if (!check_rectangular(game))
    {
        ft_printf("the map is not rectangular!!\n");
        exit(0);
    }
    if (!walls_check(game))
    {
        ft_printf("Walls error!\n");
        exit(0);
    }
    if (content_check(game))
        exit(0);
    map_printer(game);
}


int check_extention(char *str)
{
    int i;

    i = 0;
    if (!str)
        return (0);
    while (str[i])
        i++;
    if (str[i - 1] == 'r' && str[i - 2] == 'e' && str[i - 3] == 'b' && str[i - 4] == '.')
        return (1);
    return (0);
}

void free_map(t_game *game)
{
    int i;

    i = 0;
    while (game->map[i])
        free(game->map[i++]);
    free(game->map);
}

int main(int ac, char **av)
{
    int i;
    t_game game;

    i = 0;
    if (ac == 2)
    {
        if (!check_extention(av[1]))
            return (ft_printf("the extention is invalid don't need to carry on!\n"), 0);
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
    mlx_hook(game.win, 17, 0, destroy_window, &game);
    mlx_hook(game.win, 2, (1L<<2), m_hook, &game);
	mlx_loop(game.mlx);
    //free_map(map);
}