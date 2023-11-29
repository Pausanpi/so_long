/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pausanch <pausanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:06:53 by pausanch          #+#    #+#             */
/*   Updated: 2023/11/29 13:19:55 by pausanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	display_moves(t_game *game)
{
	char	*str;

	str = ft_itoa(game->moves);
	mlx_string_put(game->mlx, game->win, 9, 20, 0x6BBBD0, str);
	free(str);
}

void	extra_player_moves(t_game *game)
{
	game->moves++;
	game->endgame = 1;
	map_draw(game);
	exit_game(game);
}

void	dead_player(t_game *game)
{
	game->endgame = 1;
	map_draw(game);
	exit_game(game);
}
