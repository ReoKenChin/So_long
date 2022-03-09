#include "so_long.h"

void player_pos(t_game *game)
{
    int i;
    int j;
    i = 0;
    while (game->map[i])
    {
        j = 0;
        while (game->map[i][j])
        {
            if (game->map[i][j] == 'P')
            {
                game->p_x = i;
                game->p_y = j;
            }
            j++;
        }
        i++;
    }
}

int destroy_window(t_game *game)
{
    free_map(game);
    mlx_destroy_window(game->mlx, game->win);
    ft_printf("Exit!!");
    exit(EXIT_SUCCESS);
    return (0);
}

void move_player(t_game *game, int i, int j)
{
    if (game->map[game->p_x + i][game->p_y + j] != '1')
    {
        if (game->map[game->p_x + i][game->p_y + j] == 'C')
            game->n_colect--;
        else if (game->map[game->p_x + i][game->p_y + j] == 'E')
        {
            if (game->n_colect != 0)
            {
                ft_printf("Bravo!!");
                free_map(game);
                mlx_destroy_window(game->mlx, game->win);
                exit(EXIT_SUCCESS);
            }
            return ;
        }
        game->moves++;
        game->map[game->p_x + i][game->p_y + j] = 'P';
        game->map[game->p_x][game->p_y] = '0';
        game->p_x += i;
        game->p_y += j;
        ft_printf("Moves : %d\n", game->moves);
        draw(game);
    }
}

int m_hook(int key_code, t_game *game)
{
    if (key_code == A)
        move_player(game, 0, -1);
    else if (key_code == D)
        move_player(game, 0, 1);
    else if (key_code == W)
        move_player(game, -1, 0);
    else if (key_code == S)
        move_player(game, 1, 0);
    else if (key_code == ESC)
        destroy_window(game);
    return (0);
}


