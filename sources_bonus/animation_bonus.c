/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pausanch <pausanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:51:31 by pausanch          #+#    #+#             */
/*   Updated: 2023/12/06 11:27:18 by pausanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

static void	anim_util(t_game *game, int x)
{
	if (x == 1)
	{
		game->img_colect = game->img_colect1;
		game->img_enemie = game->img_enemie1;
	}
	else if (x == 2)
	{
		game->img_colect = game->img_colect2;
		game->img_enemie = game->img_enemie4;
	}
	else if (x == 3)
	{
		game->img_colect = game->img_colect3;
		game->img_enemie = game->img_enemie3;
	}
	else if (x == 4)
	{
		game->img_colect = game->img_colect4;
		game->img_enemie = game->img_enemie2;
	}
}

int	animation(t_game *game)
{
	if (game->time < 2999)
	{
		game->time++;
		return (0);
	}
	game->time = 0;
	if (game->pos_colect == 1)
		anim_util(game, 1);
	else if (game->pos_colect == 2)
		anim_util(game, 2);
	else if (game->pos_colect == 3)
		anim_util(game, 3);
	else if (game->pos_colect == 4)
	{
		anim_util(game, 4);
		game->pos_colect = 0;
	}
	map_draw(game);
	game->pos_colect++;
	return (0);
}
