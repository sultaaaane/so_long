/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:44:55 by mbentahi          #+#    #+#             */
/*   Updated: 2024/01/20 20:08:47 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "libft/libft.h" 
#include "ft_printf/ft_printf.h"

typedef struct s_map 
{
	char **map;
	int rows;
	int lines;
	int exit_y;
	int exit_x;
} t_map;

typedef struct s_player
{
	int y;
	int x;
	int moves;
	int collected;
} t_player;

typedef struct s_enemies
{
	int y;
	int x;
} t_enemies;

char *ft_replace_n(char *line);
int line_counter(t_map *map,int fd);
#endif