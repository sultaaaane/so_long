/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:11:31 by mbentahi          #+#    #+#             */
/*   Updated: 2024/02/07 22:49:57 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_2d(char **map, t_map *map1)
{
	int	i;

	i = 0;
	while (i < map1->rows)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	map_testing(t_map *map, char *file)
{
	int	fd;

	if (!file)
		return (perror("give a file"), 0);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (free(map), perror("the first file didn't open"), 0);
	if (!line_counter(map, fd))
		return (free(map), 0);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (free(map), perror("the second file didn't open"), 0);
	if (!map_reader(map, fd))
		return (free(map), perror("the map is not valid"), 0);
	if (!border_checker(map))
		return (free(map), 0);
	if (!player_checker(map))
		return (free(map), 0);
	if (!collectable_checker(map))
		return (free(map), 0);
	if (!exit_checker(map))
		return (free(map), 0);
	if (!map_input(map))
		return (free(map), 0);
	return (1);
}

int	map_input(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->commun_size)
		{
			if (map->map[i][j] != '1' && map->map[i][j] != 'P'
				&& map->map[i][j] != 'C' && map->map[i][j] != 'E'
				&& map->map[i][j] != '0' && map->map[i][j] != 'X')
				return (free_2d(map->map, map),
					perror("the map should only contain 1 0 P C E X"), 0);
			j++;
		}
		i++;
	}
	return (1);
}

int	extention_check(char *file)
{
	int	i;

	if (!file)
		return (perror("give a file"), 0);
	i = 0;
	while (file[i])
		i++;
	if (i < 5)
		return (perror("the file should have a .ber extention"), 0);
	if (file[i - 1] != 'r' || file[i - 2] != 'e' || file[i - 3] != 'b' || file[i
			- 4] != '.' || file[i - 5] == '/')
		return (perror("the file should have a .ber extention"), 0);
	return (1);
}
