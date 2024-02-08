/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handler_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:26:40 by mbentahi          #+#    #+#             */
/*   Updated: 2024/02/08 14:21:27 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	key_input(int keycode, t_mlx *mlx)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(mlx->mlx, mlx->window);
		exit(0);
	}
	key_input_handler(keycode, mlx->map, mlx);
	return (keycode);
}

int	close_window(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->window);
	exit(0);
	return (0);
}

void player_enemies_init(t_mlx *mlx,t_map *map)
{
	mlx->player_texture[0] = mlx_xpm_file_to_image(mlx->mlx,
			mlx->player_path[0], &map->commun_size, &map->rows);
	mlx->player_texture[1] = mlx_xpm_file_to_image(mlx->mlx,
			mlx->player_path[1], &map->commun_size, &map->rows);
	mlx->player_texture[2] = mlx_xpm_file_to_image(mlx->mlx,
			mlx->player_path[2], &map->commun_size, &map->rows);
	mlx->enemie_texture[0] = mlx_xpm_file_to_image(mlx->mlx,
			mlx->enemie_path[0], &map->commun_size, &map->rows);
	mlx->enemie_texture[1] = mlx_xpm_file_to_image(mlx->mlx,
			mlx->enemie_path[1], &map->commun_size, &map->rows);
	mlx->enemie_texture[2] = mlx_xpm_file_to_image(mlx->mlx,
			mlx->enemie_path[2], &map->commun_size, &map->rows);
	mlx->enemie_texture[3] = mlx_xpm_file_to_image(mlx->mlx,
			mlx->enemie_path[3], &map->commun_size, &map->rows);
}

void	texture_initializer(t_mlx *mlx, t_map *map)
{
	mlx->empty_texture = mlx_xpm_file_to_image(mlx->mlx,
			"./textures/floor/floor.xpm", &map->commun_size, &map->rows);
	if (!mlx->empty_texture)
		perror("empty");
	mlx->wall_texture = mlx_xpm_file_to_image(mlx->mlx,
			"./textures/wall/wall.xpm", &map->commun_size, &map->rows);
	if (!mlx->wall_texture)
		perror("wall");
	mlx->collectible_texture = mlx_xpm_file_to_image(mlx->mlx,
			"./textures/coin/coin.xpm", &map->commun_size, &map->rows);
	if (!mlx->collectible_texture)
		perror("collectible_texture");
	mlx->exit_texture = mlx_xpm_file_to_image(mlx->mlx,
			"./textures/door/closed_door.xpm", &map->commun_size, &map->rows);
	if (!mlx->exit_texture)
		perror("exit_texture");
	mlx->open_exit_texture = mlx_xpm_file_to_image(mlx->mlx,
			"./textures/door/open_door.xpm", &map->commun_size, &map->rows);
}

void	display_texture(char c, t_mlx *mlx, int x, int y)
{
	if (c == '0')
		mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->empty_texture, x,
			y);
	else if (c == '1')
		mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->wall_texture, x, y);
	else if (c == 'C')
		mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->collectible_texture,
			x, y);
	else if (c == 'E')
		mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->exit_texture, x, y);
	else if (c == 'X')
		mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->enemie_texture[mlx->enemie_frame++],
			x, y);
	else if (c == 'P')
		mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->player_texture[mlx->player_frame++], x,
			y);
	else if (c == 'O')
		mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->open_exit_texture,
			x, y);
	if (mlx->player_frame == 2)
		mlx->player_frame = 0;
	if (mlx->enemie_frame == 3)
		mlx->enemie_frame = 0;
	usleep(500);
}

void texture_path(t_mlx *mlx)
{
	mlx->enemie_frame = 0;
	mlx->player_frame = 0;
	mlx->player_path[0] = "./textures/knight/knights1.xpm";
	mlx->player_path[1] = "./textures/knight/knights2.xpm";
	mlx->player_path[2] = "./textures/knight/knights3.xpm";
	mlx->enemie_path[0] = "./textures/enemies/enemie0.xpm";
	mlx->enemie_path[1] = "./textures/enemies/enemie1.xpm";
	mlx->enemie_path[2] = "./textures/enemies/enemie2.xpm";
	mlx->enemie_path[3] = "./textures/enemies/enemie3.xpm";
	mlx->frame = 0;
	player_enemies_init(mlx,mlx->map);
}

int	render_map(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	
	while (mlx->map->map[i])
	{
		j = 0;
		while (mlx->map->map[i][j])
		{
			display_texture(mlx->map->map[i][j], mlx, j * 32, i * 32);
			j++;
		}
		i++;
	}
	return (1);
}
