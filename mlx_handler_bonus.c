/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:26:40 by mbentahi          #+#    #+#             */
/*   Updated: 2024/02/02 18:10:53 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	mlx->player_texture = mlx_xpm_file_to_image(mlx->mlx,
			"./textures/knight/knight.xpm", &map->commun_size, &map->rows);
	if (!mlx->player_texture)
		perror("player_texture");
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
	else if (c == 'P')
		mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->player_texture, x,
			y);
	else if (c == 'O')
		mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->open_exit_texture,
			x, y);
}

int	render_map(t_mlx *mlx, int flag)
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
	if (flag == 1)
	{
		mlx->map->init_player.moves++;
		ft_printf("%d\n", mlx->map->init_player.moves);
	}
	return (1);
}
