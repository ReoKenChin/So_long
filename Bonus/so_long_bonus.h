/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcherki <mcherki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 11:39:21 by mcherki           #+#    #+#             */
/*   Updated: 2022/03/19 16:18:43 by mcherki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "gnl/get_next_line.h"
# include "ft_printf/ft_printf.h"
# include <mlx.h>
# include <math.h>

# define A 0
# define S 1
# define D 2
# define W 13
# define ESC 53

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	void	*img_backg;
	void	*img_wall;
	void	*img_player;
	void	*img_colect;
	void	*img_exit;
	void	*img_enemie;
	int		map_w;
	int		map_h;
	int		img_w;
	int		img_h;
	int		n_colect;
	int		n_player;
	int		n_exit;
	int		p_x;
	int		p_y;
	int		e_x;
	int		e_y;
	int		moves;
	int		pos_enemies;
	int		loop;
	int		lenght;
	int		count;
}	t_game;

int		check_extention(char *str);
char	**read_map(t_game *game, char *path);
int		walls_check(t_game *game);
char	**ft_split(char *s, char c);
int		check_rectangular(t_game *game);
int		content_check(t_game *game);
int		obj_check(t_game *game, char c);
int		line_check(t_game *game);
int		map_correct_form(t_game *game);
int		map_end(char *line);
char	*word_dup(char *str, int start, int finish);
char	**map_allo(t_game *game, char *line);
char	**map_filling_up(char *line, t_game *game);
void	validate(t_game *game);
void	free_map(t_game *game);
int		map_0(t_game *game);
void	dynamic_map(t_game *game);
void	draw(t_game *game);
void	init_textures(t_game *game);
void	move_player(t_game *game, int i, int j);
int		destroy_window(t_game *game);
void	player_pos(t_game *game);
int		m_hook(int key_code, t_game *game);
void	map_init(t_game *game);
void	display_moves(t_game *game);
size_t	get_digits(int n);
char	*ft_itoa(int n);
void	exit_game(t_game *game);
void	move_a(t_game *game);
void	move_d(t_game *game);
void	move_w(t_game *game);
void	move_s(t_game *game);
int		animation(t_game *game);
void	tombdraw(t_game *game);
int		move_enemy(t_game *game);
char	*check(char *line, char *holder);
void	image_drawer(t_game *game);
void	win(t_game *game);
void	drawer(t_game *game, int i, int j);
void	ft_free(char *line, char *holder);
void	check_enemy(t_game game);

#endif
