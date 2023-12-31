/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pausanch <pausanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:43:23 by pausanch          #+#    #+#             */
/*   Updated: 2023/10/31 14:43:23 by pausanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

static void	img_init(t_game *game)
{
	game->img_floor = mlx_xpm_file_to_image(game->mlx,
			"Sprites/floor.xpm", &game->img_w, &game->img_h);
	game->img_wall = mlx_xpm_file_to_image(game->mlx, "Sprites/wall.xpm",
			&game->img_w, &game->img_h);
	game->img_player = mlx_xpm_file_to_image(game->mlx,
			"Sprites/character_down.xpm", &game->img_w, &game->img_h);
	game->img_colect1 = mlx_xpm_file_to_image(game->mlx,
			"animation/collectible1.xpm", &game->img_w, &game->img_h);
	game->img_exit = mlx_xpm_file_to_image(game->mlx,
			"Sprites/exit2.xpm", &game->img_w, &game->img_h);
	game->img_colect2 = mlx_xpm_file_to_image(game->mlx,
			"animation/collectible2.xpm", &game->img_w, &game->img_h);
	game->img_colect3 = mlx_xpm_file_to_image(game->mlx,
			"animation/collectible3.xpm", &game->img_w, &game->img_h);
	game->img_colect4 = mlx_xpm_file_to_image(game->mlx,
			"animation/collectible4.xpm", &game->img_w, &game->img_h);
	game->img_enemie = mlx_xpm_file_to_image(game->mlx,
			"Sprites/enemie.xpm", &game->img_w, &game->img_h);
	game->img_colect = mlx_xpm_file_to_image(game->mlx,
			"animation/collectible1.xpm", &game->img_w, &game->img_h);
}

static void	img_init2(t_game *game)
{
	game->img_enemie1 = mlx_xpm_file_to_image(game->mlx,
			"animation/enemie1.xpm", &game->img_w, &game->img_h);
	game->img_enemie2 = mlx_xpm_file_to_image(game->mlx,
			"animation/enemie2.xpm", &game->img_w, &game->img_h);
	game->img_enemie3 = mlx_xpm_file_to_image(game->mlx,
			"animation/enemie3.xpm", &game->img_w, &game->img_h);
	game->img_enemie4 = mlx_xpm_file_to_image(game->mlx,
			"animation/enemie4.xpm", &game->img_w, &game->img_h);
}

static void	size_window_init(t_game *game)
{
	int	i;

	game->map_w = ft_strlen(game->map[0]) * 32;
	i = 0;
	while (game->map[i] != (void *)0)
		i++;
	game->map_h = i * 32;
}

void	game_init(t_game *game)
{
	game->mlx = mlx_init();
	size_window_init(game);
	game->win = mlx_new_window(game->mlx, game->map_w, game->map_h, "so_long");
	game->moves = 0;
	game->moves_ant = -1;
	game->endgame = 0;
	game->time = 0;
	game->pos_colect = 1;
	img_init(game);
	img_init2(game);
	map_draw(game);
}
