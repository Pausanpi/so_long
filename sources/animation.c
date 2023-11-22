/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pausanch <pausanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:51:31 by pausanch          #+#    #+#             */
/*   Updated: 2023/11/15 12:43:00 by pausanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	animation(t_game *game)
{
	if (game->time < 5999)
	{
		game->time++;
		return (0);
	}
	game->time = 0;
	if (game->pos_colect == 1)
		game->img_colect1 = game->img_colect1;
	else if (game->pos_colect == 2)
		game->img_colect1 = game->img_colect2;
	else if (game->pos_colect == 3)
		game->img_colect1 = game->img_colect3;
	else if (game->pos_colect == 4)
	{
		game->img_colect1 = game->img_colect4;
		game->pos_colect = 0;
	}
	map_draw(game);
	game->pos_colect++;
	return (0);
}
