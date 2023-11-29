/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pausanch <pausanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:51:04 by pausanch          #+#    #+#             */
/*   Updated: 2023/10/31 14:51:04 by pausanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

static int	is_rectangular(char **map)
{
	int	i;

	if (!map)
		return (0);
	i = 1;
	while (map[i] != (void *)0)
	{
		if (ft_strlen(map[i]) != ft_strlen(map[0]))
		{
			ft_printf("Error, el mapa no es rectangular!\n");
			return (0);
		}
		i++;
	}
	return (1);
}

static int	is_wall(char **map)
{
	int	i;
	int	j;
	int	len;

	j = 0;
	i = 0;
	while (map[i] != (void *)0)
		i++;
	while (map[0][j] != '\0' && map[i - 1][j] != '\0')
	{
		if (map[0][j] != '1' || map[i - 1][j] != '1')
			return (ft_printf("Error, no todo es muro!\n"), 0);
		j++;
	}
	i = 1;
	len = ft_strlen(map[i]);
	while (map[i] != (void *)0)
	{
		if (map[i][0] != '1' || map[i][len - 1] != '1')
			return (ft_printf("Error, no todo es muro!\n"), 0);
		i++;
	}
	return (1);
}

static int	is_pec(t_game *game)
{
	int	i;
	int	j;

	game->n_colect = 0;
	game->n_player = 0;
	game->n_exit = 0;
	i = 0;
	while (game->map[i] != (void *)0)
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (game->map[i][j] == 'P')
				game->n_player++;
			else if (game->map[i][j] == 'E')
				game->n_exit++;
			else if (game->map[i][j] == 'C')
				game->n_colect++;
			j++;
		}
		i++;
	}
	if (game->n_player != 1 || game->n_exit == 0 || game->n_colect == 0)
		return (ft_printf("Error, le falta un elemento!\n"), 0);
	return (1);
}

static int	is_validate(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != (void *)0)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] != 'P' && map[i][j] != 'E' && map[i][j] != 'C'
				&& map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'X')
				return (ft_printf("Error, tiene algo de más!\n"), 0);
			j++;
		}
		i++;
	}
	return (1);
}

int	map_checker(t_game *game)
{
	if (is_rectangular(game->map) && is_wall(game->map)
		&& is_pec(game) && is_validate(game->map))
		return (1);
	return (0);
}
