/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pausanch <pausanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:12:05 by pausanch          #+#    #+#             */
/*   Updated: 2023/11/29 14:55:40 by pausanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../libft/libft.h"
# include "../MLX/mlx.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdbool.h>

# define KEY_ESC 53
# define KEY_Q 12

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

# define KEY_UP 126
# define KEY_LEFT 123
# define KEY_DOWN 125
# define KEY_RIGHT 124

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	void	*img_floor;
	void	*img_wall;
	void	*img_player;
	void	*img_colect;
	void	*img_colect1;
	void	*img_colect2;
	void	*img_colect3;
	void	*img_colect4;
	void	*img_exit;
	void	*img_enemie;
	int		map_w;
	int		map_h;
	int		img_w;
	int		img_h;
	int		n_colect;
	int		n_player;
	int		n_exit;
	int		x_player;
	int		y_player;
	int		moves;
	int		moves_ant;
	int		endgame;
	int		time;
	int		pos_colect;
}	t_game;

int		animation(t_game *game);
void	img_draw(t_game *game, void *image, int x, int y);
int		map_draw(t_game *game);
void	game_init(t_game *game);
char	**read_map(char *path);
int		map_checker(t_game *game);
void	gameplay(t_game *game);
void	player_w(t_game *game);
void	player_s(t_game *game);
void	player_a(t_game *game);
void	player_d(t_game *game);
int		exit_game(t_game *game);
void	free_map(char **map);
void	display_moves(t_game *game);
void	extra_player_moves(t_game *game);
void	dead_player(t_game *game);

#endif
