/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:26:40 by mbentahi          #+#    #+#             */
/*   Updated: 2024/01/24 19:32:40 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int key_up(int keycode,t_mlx *mlx)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(mlx->mlx,mlx->window);
		exit(0);
	}
	if (keycode == 65362)
		ft_printf("up");
	if (keycode == 65364)
		ft_printf("down");
	if (keycode == 65361)
		ft_printf("left");
	if (keycode == 65363)
		ft_printf("right");
	ft_printf(" the key is %d\n",keycode);
	return (keycode);
}
int close_window(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx,mlx->window);
	exit(0);
	return (0);
}

void texture_initializer(t_mlx *mlx,t_map *map)
{
	mlx->empty_texture = mlx_xpm_file_to_image(mlx->mlx, "./textures/floor/AnyConv.com__floor_3.xpm", &map->commun_size, &map->rows);
    mlx->wall_texture = mlx_xpm_file_to_image(mlx->mlx, "./textures/walls/AnyConv.com__wall_2.xpm", &map->commun_size, &map->rows);
    mlx->collectible_texture = mlx_xpm_file_to_image(mlx->mlx, "./textures/coin/AnyConv.com__bag_coins.xpm", &map->commun_size, &map->rows);
    mlx->exit_texture = mlx_xpm_file_to_image(mlx->mlx, "./textures/door/AnyConv.com__door_closed.xpm", &map->commun_size, &map->rows);
    mlx->player_texture = mlx_xpm_file_to_image(mlx->mlx, "./textures/knight/AnyConv.com__knight_idle_anim_f4.xpm", &map->commun_size, &map->rows);
}

void display_texture(char c, t_mlx *mlx, int x, int y)
{
    if (c == '0') 
        mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->empty_texture, x, y);
    else if (c == '1')
        mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->wall_texture, x, y);
    else if (c == 'C')
        mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->collectible_texture, x, y);
    else if (c == 'E')
        mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->exit_texture, x, y);
    else if (c == 'P')
        mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->player_texture, x, y);
}

int mlx_handler(t_map *map)
{
	t_mlx	mlx;
	int i;
	int j;

	i = 0;
	mlx.mlx = mlx_init();
	mlx.window = mlx_new_window(mlx.mlx, map->commun_size * 32,
			map->rows * 32, "so_long");
	mlx_key_hook(mlx.window, key_up, &mlx);
	mlx_hook(mlx.window, 17,0, close_window, &mlx);
	while (i < map->rows)
	{
		j = 0;
		while (j < map->commun_size)
		{
			display_texture(map->map[i][j],&mlx, 0, 0);
			j++;
		}
		i++;
	}
	mlx_loop(mlx.mlx);
	return (0);
}