/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pausanch <pausanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:55:32 by pausanch          #+#    #+#             */
/*   Updated: 2023/11/06 13:55:32 by pausanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

static int	random1to5(void)
{
	return (rand() % (int)5 + 1);
}

static void	draw_element(t_game *game, int random)
{
	if (random == 1)
		game->img_full = game->img_ambar;
	else if (random == 2)
		game->img_full = game->img_caracola;
	else if (random == 3)
		game->img_full = game->img_crystal;
	else if (random == 4)
		game->img_full = game->img_thing;
	else if (random == 5)
		game->img_full = game->img_thing2;
}

static bool	extreme(t_game *game, int x, int y)
{
	return (x == 0 || y == 0 || x == (int)ft_strlen(game->map[0]) - 1
		|| y == (int)ft_strlen((char *)game->map) - 2);
}

void	wall_texture(t_game *game, int x, int y)
{
	int	r;

	r = random1to5();
	if (!extreme(game, x, y))
	{
		draw_element(game, r);
		mlx_put_image_to_window(game->mlx, game->win,
			game->img_full, x * 32, y * 32);
	}
	else
		mlx_put_image_to_window(game->mlx, game->win,
			game->img_wall, x * 32, y * 32);
}
