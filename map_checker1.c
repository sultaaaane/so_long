/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:43:44 by mbentahi          #+#    #+#             */
/*   Updated: 2024/01/24 15:03:06 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_initializer(t_map *map)
{
	map->rows = 0;
	map->exit_x = 0;
	map->exit_y = 0;
	map->collectables = 0;
	map->commun_size = 0;
	map->init_player.collected = 0;
	map->init_player.moves = 0;
	map->init_player.x = 0;
	map->init_player.y = 0;
}

int	collectable_checker(t_map *map)
{
	int	i;
	int	j;
	int		collectable;

	i = 0;
	j = 0;
	collectable = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->commun_size)
		{
			if (map->map[i][j] == 'C')
				collectable++;
			j++;
		}
		i++;
	}
	if (collectable == 0)
		return (free_2d(map->map, map),
			perror("the map must have at least one collectable"), 0);
	return (1);
}

int	exit_checker(t_map *map)
{
	int	i;
	int	j;
	int		exit;

	i = 0;
	j = 0;
	exit = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->commun_size)
		{
			if (map->map[i][j] == 'E')
			{
				exit++;
				map->exit_y = i;
				map->exit_x = j;
			}
			j++;
		}
		i++;
	}
	if (exit != 1)
		return (free_2d(map->map, map), perror("atleast a exit"), 0);
	return (1);
}

int	player_checker(t_map *map)
{
	int	i;
	int	j;
	int		player;

	i = 0;
	j = 0;
	player = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->commun_size)
		{
			if (map->map[i][j] == 'P')
			{
				player++;
				map->init_player.y = i;
				map->init_player.x = j;
			}
			j++;
		}
		i++;
	}
	if (player != 1)
		return (free_2d(map->map, map), perror("atleast a player"), 0);
	return (1);
}

int	border_checker(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map->rows)
	{
		if (map->map[i][0] != '1' || map->map[i][map->commun_size - 1] != '1')
			return (free_2d(map->map, map),
				perror("the map columns's is wrong"), 0);
		i++;
	}
	while (j < map->commun_size)
	{
		if (map->map[0][j] != '1' || map->map[map->rows - 1][j] != '1')
			return (free_2d(map->map, map), perror("the map rows's is wrong"),
				0);
		j++;
	}
	return (1);
}
