/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 11:12:26 by mbentahi          #+#    #+#             */
/*   Updated: 2024/01/29 14:28:42 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_wall(t_map *map, int x, int y)
{
	if (map->map[y][x] == '1')
		return (1);
	return (0);
}

int	is_collectible(t_map *map, int x, int y)
{
	if (map->map[y][x] == 'C')
		return (1);
	return (0);
}

int	is_exit(t_map *map, int x, int y)
{
	if (map->map[y][x] == 'E')
		return (1);
	return (0);
}

int	is_open_exit(t_map *map, int x, int y)
{
	if (map->map[y][x] == 'O')
		return (1);
	return (0);
}

int	is_empty(t_map *map, int x, int y)
{
	if (map->map[y][x] == '0')
		return (1);
	return (0);
}
