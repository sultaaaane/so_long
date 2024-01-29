/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:13:56 by mbentahi          #+#    #+#             */
/*   Updated: 2024/01/28 20:20:35 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_replace_n(char *line)
{
	char	*str;

	str = ft_strtrim(line, "\n");
	return (free(line), str);
}

int	line_counter(t_map *map, int fd)
{
	char	*line;

	line = NULL;
	line = ft_replace_n(get_next_line(fd));
	if (!line)
		return (free(line), perror("the map is empty"), 0);
	map->rows++;
	map->commun_size = ft_strlen(line);
	while (line)
	{
		free(line);
		line = ft_replace_n(get_next_line(fd));
		printf("%s pp \n", line);
		if (!line)
			return (free(line), map->rows);
		if (ft_strlen(line) != (size_t)map->commun_size)
			return (free(line), perror("the map columns is not the same"), 0);
		map->rows++;
	}
	close(fd);
	free(line);
	return (map->rows);
}

void	map_free(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->rows)
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
	free(map);
}

char	**map_reader(t_map *map, int fd)
{
	char	*line;
	int	i;

	i = 0;
	line = NULL;
	map->map = malloc(sizeof(char *) * (map->rows + 1));
	if (!map->map)
		return (free(map), NULL);
	while (i < map->rows)
	{
		line = ft_replace_n(get_next_line(fd));
		if (!line)
			return (map_free(map), free(line), NULL);
		map->map[i] = ft_strdup(line);
		free(line);
		i++;
	}
	map->map[i] = NULL;
	close(fd);
	return (map->map);
}

int	main(int ac, char **av)
{
	t_map	*map;

	if (ac != 2)
		return (perror("usage: ./so_long map.ber"), 0);
	if (!extention_check(av[1]))
		return (1);
	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		return (1);
	map_initializer(map);
	if (!map_testing(map, av[1]))
		return (1);
	mlx_handler(map);
	return (0);
}
