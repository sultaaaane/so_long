/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handler1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:59:21 by mbentahi          #+#    #+#             */
/*   Updated: 2024/01/27 09:34:56 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int key_input_handler(int keycode, t_map *map)
{
	if (keycode == 65362)
		move_player(map, 0, -1);
	if (keycode == 65364)
		move_player(map, 0, 1);
	if (keycode == 65361)
		move_player(map, -1, 0);
	if (keycode == 65363)
		move_player(map, 1, 0);
	return (keycode);
}
