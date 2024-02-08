/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:09:24 by mbentahi          #+#    #+#             */
/*   Updated: 2024/02/08 15:06:46 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	is_valid_move(t_map *map, char **visited, int y, int x)
{
	return (y >= 0 && y < map->rows && x >= 0 && x < map->commun_size
		&& visited[y][x] != 'V' && visited[y][x] != '1' && visited[y][x] != 'X');
}

char	**visited_initializer(t_map *map)
{
	int		y;
	int		x;
	char	**visited;

	y = 0;
	visited = malloc(sizeof(char *) * map->rows);
	while (y < map->rows)
	{
		visited[y] = malloc(sizeof(char) * map->commun_size);
		y++;
	}
	y = 0;
	while (y < map->rows)
	{
		x = 0;
		while (x < map->commun_size)
		{
			visited[y][x] = map->map[y][x];
			x++;
		}
		y++;
	}
	return (visited);
}

void	t_data_init(t_data *data, t_map *map)
{
	data->queue = (t_point *)malloc(sizeof(t_point) * map->commun_size
			* map->rows);
	data->row_direction[0].col = 0;
	data->row_direction[0].row = 1;
	data->row_direction[1].col = 0;
	data->row_direction[1].row = -1;
	data->row_direction[2].col = 1;
	data->row_direction[2].row = 0;
	data->row_direction[3].col = -1;
	data->row_direction[3].row = 0;
	data->current.col = map->commun_size;
	data->current.row = map->rows;
	data->front = 0;
	data->rear = 0;
	data->exit_reached = 0;
}

void	while_bfs(t_map *map, t_data *data, char **visited)
{
	int	i;
	int	next_row;
	int	next_col;

	i = 0;
	while (i < 4)
	{
		next_row = data->current.row + data->row_direction[i].row;
		next_col = data->current.col + data->row_direction[i].col;
		if (is_valid_move(map, visited, next_row, next_col))
		{
			visited[next_row][next_col] = 'V';
			data->next_point.col = next_col;
			data->next_point.row = next_row;
			data->queue[data->rear++] = data->next_point;
		}
		i++;
	}
}

int	bfs(t_map *map, t_point start, int *collectibles)
{
	t_data	data;
	char	**visited;
	char	**temp;

	t_data_init(&data, map);
	visited = visited_initializer(map);
	temp = visited_initializer(map);
	visited[start.row][start.col] = 'V';
	data.queue[data.rear++] = start;
	while (data.front != data.rear)
	{
		data.current = data.queue[data.front++];
		if (map->map[data.current.row][data.current.col] == 'C')
		{
			(*collectibles)++;
			temp[data.current.row][data.current.col] = '0';
		}
		else if (map->map[data.current.row][data.current.col] == 'E')
		{
			data.exit_reached = 1;
			continue;
		}
		while_bfs(map, &data, visited);
	}
	free(data.queue);
	return (free_2d(temp, map), free_2d(visited, map), data.exit_reached);
}
