/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaumas <fdaumas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 10:17:45 by fdaumas           #+#    #+#             */
/*   Updated: 2022/04/11 10:39:38 by fdaumas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_img(t_map *map)
{
	int	width;
	int	height;

	width = WIDTH;
	height = HEIGHT;
	map->wall = mlx_xpm_file_to_image
		(map->mlx, "./sprite/wall.xpm", &width, &height);
	map->coin = mlx_xpm_file_to_image
		(map->mlx, "./sprite/coin.xpm", &width, &height);
	map->ground = mlx_xpm_file_to_image
		(map->mlx, "./sprite/ground.xpm", &width, &height);
	map->exit = mlx_xpm_file_to_image
		(map->mlx, "./sprite/exit.xpm", &width, &height);
	map->chara = mlx_xpm_file_to_image
		(map->mlx, "./sprite/character.xpm", &width, &height);
}

void	print_case(t_map *map, int x, int y, char box)
{
	if (box == '0')
		mlx_put_image_to_window(map->mlx, map->win, map->ground, x, y);
	if (box == '1')
		mlx_put_image_to_window(map->mlx, map->win, map->wall, x, y);
	if (box == 'P')
	{
		mlx_put_image_to_window(map->mlx, map->win, map->ground, x, y);
		mlx_put_image_to_window(map->mlx, map->win, map->chara, x, y);
	}
	if (box == 'C')
	{
		mlx_put_image_to_window(map->mlx, map->win, map->ground, x, y);
		mlx_put_image_to_window(map->mlx, map->win, map->coin, x, y);
	}
	if (box == 'E')
		mlx_put_image_to_window(map->mlx, map->win, map->exit, x, y);
}

void	print_line(t_map *map, char *line, int y)
{
	int	index;
	int	x;

	index = 0;
	y *= HEIGHT;
	while (line[index])
	{
		x = index * WIDTH;
		print_case(map, x, y, line[index]);
		index++;
	}
}

void	print_map(t_map *map)
{
	int	y;

	y = 0;
	while (map->map[y])
	{
		print_line(map, map->map[y], y);
		y++;
	}
}
