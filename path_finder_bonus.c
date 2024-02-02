/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:09:24 by mbentahi          #+#    #+#             */
/*   Updated: 2024/02/02 18:23:19 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int is_valid_move(t_map *map, char **visited, int y, int x) {
    return y >= 0 && y < map->rows && x >= 0 && x < map->commun_size
           && visited[y][x] != 'V' && visited[y][x] != '1';
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

int bfs(t_map *map, t_point start, int *collectibles) {
    char **visited = visited_initializer(map);
    char **temp = visited_initializer(map);
    int i;
    visited[start.row][start.col] = 'V';
    t_point row_direction[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    t_point queue[map->rows * map->commun_size];
    int front = 0, rear = 0;
    queue[rear++] = start;


    int exit_reached = 0;

    while (front != rear) {
        t_point current = queue[front++];
        if (map->map[current.row][current.col] == 'C') {
            (*collectibles)++;
            temp[current.row][current.col] = '0';
        } else if (map->map[current.row][current.col] == 'E') {
            exit_reached = 1;
        }
        i = 0;
        while (i < 4)
        {
            int next_row = current.row + row_direction[i].row;
            int next_col = current.col + row_direction[i].col;

            if (is_valid_move(map, visited, next_row, next_col)) {
                visited[next_row][next_col] = 'V';
                t_point next_point = {next_row, next_col};
                queue[rear++] = next_point;
            }
            i++;
        }
    }
    ft_printf("%d %d\n",*collectibles,map->collectables);
    free_2d(visited, map);
    free_2d(temp, map);
    return (exit_reached);
}
