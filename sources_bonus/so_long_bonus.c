/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pausanch <pausanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:35:47 by pausanch          #+#    #+#             */
/*   Updated: 2023/10/31 14:35:47 by pausanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

static int	argv_checker(char *argv)
{
	int	i;

	if (!argv)
		return (0);
	i = 0;
	while (argv[i])
		i++;
	i -= 1;
	if (argv[i] == 'r' && argv[i - 1] == 'e'
		&& argv[i - 2] == 'b' && argv[i - 3] == '.')
		return (1);
	return (0);
}

void	ft_leaks(void)
{
	system("leaks -q so_long");
}

int	main(int argc, char **argv)
{
	t_game	game;

	atexit(ft_leaks);
	if (argc == 2)
	{
		game.map = read_map(argv[1]);
		if (map_checker(&game) && argv_checker(argv[1]))
		{
			game_init(&game);
			gameplay(&game);
			mlx_loop(game.mlx);
		}
		else
			return (free_map(game.map), 1);
	}
	else
	{
		ft_printf("Error\nInvalid Syntax");
		exit(1);
	}
	return (0);
}
