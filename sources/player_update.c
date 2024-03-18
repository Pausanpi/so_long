/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_update.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pausanch <pausanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 10:41:44 by pausanch          #+#    #+#             */
/*   Updated: 2023/11/03 10:41:44 by pausanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	player_update_image(char key, t_game *game)
{
	mlx_destroy_image(game->mlx, game->img_player);
	if (key == 'w')
		game->img_player = mlx_xpm_file_to_image(game->mlx,
				"Sprites/character_up.xpm", &game->img_w, &game->img_h);
	else if (key == 's')
		game->img_player = mlx_xpm_file_to_image(game->mlx,
				"Sprites/character_down.xpm", &game->img_w, &game->img_h);
	else if (key == 'd')
		game->img_player = mlx_xpm_file_to_image(game->mlx,
				"Sprites/character_right.xpm", &game->img_w, &game->img_h);
	else if (key == 'a')
		game->img_player = mlx_xpm_file_to_image(game->mlx,
				"Sprites/character_left.xpm", &game->img_w, &game->img_h);
}

void	player_w(t_game *game)
{
	player_update_image('w', game);
	mlx_clear_window(game->mlx, game->win);
	if (game->map[game->y_player][game->x_player] == 'E'
		&& game->n_colect == 0)
	{
		game->map[game->y_player + 1][game->x_player] = '0';
		game->moves++;
		game->endgame = 1;
		exit_game(game);
	}
	else if (game->map[game->y_player][game->x_player] == '1'
		|| game->map[game->y_player][game->x_player] == 'E')
		game->y_player += 1;
	else
	{
		if (game->map[game->y_player][game->x_player] == 'C')
			game->n_colect -= 1;
		game->map[game->y_player][game->x_player] = 'P';
		game->map[game->y_player + 1][game->x_player] = '0';
		game->moves++;
	}
	map_draw(game);
}

void	player_s(t_game *game)
{
	player_update_image('s', game);
	mlx_clear_window(game->mlx, game->win);
	if (game->map[game->y_player][game->x_player] == 'E'
		&& game->n_colect == 0)
	{
		game->map[game->y_player - 1][game->x_player] = '0';
		game->moves++;
		game->endgame = 1;
		exit_game(game);
	}
	else if (game->map[game->y_player][game->x_player] == '1'
		|| game->map[game->y_player][game->x_player] == 'E')
		game->y_player -= 1;
	else
	{
		if (game->map[game->y_player][game->x_player] == 'C')
			game->n_colect -= 1;
		game->map[game->y_player][game->x_player] = 'P';
		game->map[game->y_player - 1][game->x_player] = '0';
		game->moves++;
	}
	map_draw(game);
}

void	player_a(t_game *game)
{
	player_update_image('a', game);
	mlx_clear_window(game->mlx, game->win);
	if (game->map[game->y_player][game->x_player] == 'E'
		&& game->n_colect == 0)
	{
		game->map[game->y_player][game->x_player + 1] = '0';
		game->moves++;
		game->endgame = 1;
		exit_game(game);
	}
	else if (game->map[game->y_player][game->x_player] == '1'
		|| game->map[game->y_player][game->x_player] == 'E')
		game->x_player += 1;
	else
	{
		if (game->map[game->y_player][game->x_player] == 'C')
			game->n_colect -= 1;
		game->map[game->y_player][game->x_player] = 'P';
		game->map[game->y_player][game->x_player + 1] = '0';
		game->moves++;
	}
	map_draw(game);
}

void	player_d(t_game *game)
{
	player_update_image('d', game);
	mlx_clear_window(game->mlx, game->win);
	if (game->map[game->y_player][game->x_player] == 'E'
		&& game->n_colect == 0)
	{
		game->map[game->y_player][game->x_player - 1] = '0';
		game->moves++;
		game->endgame = 1;
		exit_game(game);
	}
	else if (game->map[game->y_player][game->x_player] == '1'
		|| game->map[game->y_player][game->x_player] == 'E')
		game->x_player -= 1;
	else
	{
		if (game->map[game->y_player][game->x_player] == 'C')
			game->n_colect -= 1;
		game->map[game->y_player][game->x_player] = 'P';
		game->map[game->y_player][game->x_player - 1] = '0';
		game->moves++;
	}
	map_draw(game);
}
