/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handler1_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:59:21 by mbentahi          #+#    #+#             */
/*   Updated: 2024/02/08 14:40:36 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	key_input_handler(int keycode, t_map *map, t_mlx *mlx)
{
	if (keycode == 65362)
		move_player(mlx, map, 0, -1);
	if (keycode == 65364)
		move_player(mlx, map, 0, 1);
	if (keycode == 65361)
		move_player(mlx, map, -1, 0);
	if (keycode == 65363)
		move_player(mlx, map, 1, 0);
	return (keycode);
}

int display_loop(t_mlx *mlx)
{
	char *str;
	char *str2;
	str2 = ft_itoa(mlx->map->init_player.moves);
	str = ft_strjoin(ft_strdup("Moves: "),str2);
	render_map(mlx);
	mlx_string_put(mlx->mlx,mlx->window, 32,20,0X00FFFFFF,
	str);
	free(str);
	free(str2);
	return (0);
}

int	mlx_handler(t_map *map)
{
	t_mlx	mlx;

	mlx.map = map;
	mlx.mlx = mlx_init();
	mlx.window = mlx_new_window(mlx.mlx, map->commun_size * 32 , map->rows * 32,
			"so_long");
	mlx_key_hook(mlx.window, key_input, &mlx);
	mlx_hook(mlx.window, 17, 0, close_window, &mlx);
	texture_initializer(&mlx, map);
	// player_enemies_init(&mlx,map);
	texture_path(&mlx);
	// render_map(&mlx, 0);
	mlx_loop_hook(mlx.mlx,display_loop,&mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
