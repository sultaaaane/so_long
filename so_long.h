/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:44:55 by mbentahi          #+#    #+#             */
/*   Updated: 2024/01/24 19:20:37 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "libft/libft.h" 
#include "ft_printf/ft_printf.h"
#include "minilibx-linux/mlx.h"
typedef struct s_player
{
	int y;
	int x;
	int moves;
	int collected;
} t_player;

typedef struct s_map 
{
	char **map;
	
	int rows;
	int exit_y;
	int exit_x;
	int collectables;
	int commun_size;
	t_player init_player;
} t_map;

typedef struct s_mlx
{
	void *mlx;
	void *window;
	void *img;
	void *empty_texture;
    void *wall_texture;
    void *collectible_texture;
    void *exit_texture;
    void *player_texture;
} t_mlx;


char **map_reader(t_map *map,int fd);
char *ft_replace_n(char *line);
int line_counter(t_map *map,int fd);
int exit_checker(t_map *map);
int collectable_checker(t_map *map);
int player_checker(t_map *map);
int border_checker(t_map *map);
void map_free(t_map *map);
char *ft_file_reader(int fd);
void	free_2d(char **map, t_map *map1);
void	map_initializer(t_map *map);
int map_testing(t_map *map,char *file);
int map_input(t_map *map);
int extention_check(char *file);
int is_valid_move(t_map *map, int y, int x);
int mlx_handler(t_map *map);



#endif