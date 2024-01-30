/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:09:24 by mbentahi          #+#    #+#             */
/*   Updated: 2024/01/30 18:34:21 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int is_valid_move(t_map *map , char **visited, int y, int x)
{
    if (y < 0 || y > map->rows || map->map[y][x] == '1' || x < 0 || x > map->commun_size || visited[y][x] != 'V')
        return (0);
    return (1);
}
char **visited_initializer(t_map *map)
{
    int y;
    int x;
    char **visited;
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

int bfs(t_map *map, t_point start, int *collectibles)
{
    char **visited;
    int exit_reached;
    t_point queue[map->rows * map->commun_size];
    t_point current;
    int front;
    int rear;
    int row_direction[4] = {1, -1, 0, 0};
    int col_direction[4] = {0, 0, 1, -1};
    int i;
    int next_row;
    int next_col;
    
    front = 0;
    rear = 0;
    queue[rear++] = start;
    exit_reached = 0;
    visited = visited_initializer(map);
    while (front != rear)
    {
        current = queue[front++];
        if (map->map[current.row][current.col] == 'C')
        {
            (*collectibles)++;
            map->map[current.row][current.col] = '0';
        }
        else if (map->map[current.row][current.col] == 'E')
            exit_reached = 1;
        
        while (i < 4)
        {
            next_row = current.row + row_direction[i];
            next_col = current.col + col_direction[i];
            if (is_valid_move(map, visited, next_row, next_col))
            {
                visited[next_row][next_col] = 'V';
                t_point next_point = {next_row, next_col};
                queue[rear++] = next_point;
            }
            i++;
        }
    }
    return (free_2d, exit_reached);
}
