/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 11:13:25 by mbentahi          #+#    #+#             */
/*   Updated: 2024/01/26 19:10:11 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int can_move(t_map *map, int x, int y)
{
	x += map->init_player.x;
	y += map->init_player.y;
	if (is_wall(map, x, y) || is_exit(map, x, y))
		return (1);
	return (0);
}

int move_player(t_map *map, int x, int y)
{
	map->init_player.x += x;
	map->init_player.y += y;
	if (can_move(map, x, y))
	{
		if (is_empty(map, x, y))
		{
			map->map[map->init_player.y][map->init_player.x] = '0';
			map->init_player.x += x;
			map->init_player.y += y;
			map->map[map->init_player.y][map->init_player.x] = 'P';
			return (1);
		}
		else if (is_collectible(map, x, y))
		{
			map->map[map->init_player.y][map->init_player.x] = '0';
			map->init_player.x += x;
			map->init_player.y += y;
			map->map[map->init_player.y][map->init_player.x] = 'P';
			map->collectables--;
			return (1);
		}
	}
	return (0);
}


