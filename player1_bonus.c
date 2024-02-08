/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player1_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 11:13:25 by mbentahi          #+#    #+#             */
/*   Updated: 2024/02/07 23:38:08 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	can_move(t_mlx *mlx, t_map *map, int x, int y)
{
	if (x > map->commun_size || y > map->rows || x < 0 || y < 0)
		return (1);
	if (is_wall(map, x, y) || is_exit(map, x, y))
		return (1);
	if (is_open_exit(map, x, y))
	{
		close_window(mlx);
		exit(0);
	}
	if (map->map[y][x] == 'X')
	{
		close_window(mlx);
		exit(0);
	}
	return (0);
}

void	move_player(t_mlx *mlx, t_map *map, int x, int y)
{
	x += map->init_player.x;
	y += map->init_player.y;
	if (!can_move(mlx, map, x, y))
	{
		if (is_empty(map, x, y))
		{
			map->map[map->init_player.y][map->init_player.x] = '0';
			map->init_player.x = x;
			map->init_player.y = y;
			map->map[map->init_player.y][map->init_player.x] = 'P';
		}
		else if (is_collectible(map, x, y))
		{
			map->map[map->init_player.y][map->init_player.x] = '0';
			map->init_player.x = x;
			map->init_player.y = y;
			map->map[map->init_player.y][map->init_player.x] = 'P';
			map->collectables--;
			map->init_player.collected++;
			if (map->collectables == 0)
				map->map[map->exit_y][map->exit_x] = 'O';
		}
		map->init_player.moves++;
	}
}
