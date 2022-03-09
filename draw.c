#include "so_long.h"


void dynamic_map(t_game *game)
{
    int i;
    int lines;
    int columns;

    i = 0;
    while(game->map[i])
        i++;
    lines = i;
    i = 0;
    columns = ft_strlen(game->map[i]);
    game->win = mlx_new_window(game->mlx, columns * 50, lines * 50, "Hello world!");
}

void	map_init(t_game *game)
{
	game->n_player = 0;
	game->n_colect = 0;
	game->n_exit = 0;
	game->map_h = 0;
	game->map_w = 0;
	game->p_x = 0;
	game->p_y = 0;
	game->moves = 0;
}

void draw(t_game *game)
{
    int i;
    int j;

    i = 0;
    while (game->map[i])
    {
        j = 0;
        while (game->map[i][j])
        {
            mlx_put_image_to_window(game->mlx, game->win, game->img_backg, j * 50, i * 50);
            if (game->map[i][j] == '1')
                mlx_put_image_to_window(game->mlx, game->win, game->img_wall, j * 50, i * 50);
            else if (game->map[i][j] == 'P')
                mlx_put_image_to_window(game->mlx, game->win, game->img_player, j * 50, i * 50);
            else if (game->map[i][j] == 'C')
                mlx_put_image_to_window(game->mlx, game->win, game->img_colect, j * 50, i * 50);
            else if (game->map[i][j] == 'R')
                mlx_put_image_to_window(game->mlx, game->win, game->img_enemie, j * 50, i * 50);
            // else if (game.map[i][j] == 'E')
            //     mlx_put_image_to_window(game.mlx, game.win, game.img_exit, j, i);
            j++;
        }
        i++;
    }
}

void init_textures(t_game *game)
{
    game->img_player = mlx_xpm_file_to_image
    (game->mlx, "assets/boyX.xpm", &game->img_w, &game->img_h);
    game->img_wall = mlx_xpm_file_to_image
    (game->mlx, "assets/wallX.xpm", &game->img_w, &game->img_h);
    game->img_backg = mlx_xpm_file_to_image
    (game->mlx, "assets/floorX.xpm", &game->img_w, &game->img_h);
    game->img_colect = mlx_xpm_file_to_image
    (game->mlx, "assets/uniqueX.xpm", &game->img_w, &game->img_h);
    game->img_enemie = mlx_xpm_file_to_image
    (game->mlx, "assets/Enemie.xpm", &game->img_w, &game->img_h);
    draw(game);
}