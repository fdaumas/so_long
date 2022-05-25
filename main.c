/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaumas <fdaumas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:34:21 by fdaumas           #+#    #+#             */
/*   Updated: 2022/05/24 17:35:04 by fdaumas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx/mlx.h"
#include "so_long.h"
#include "src/get_next_line/get_next_line.h"
#include <stddef.h>
#include <stdlib.h>

int	travel(int keycode, t_map *map)
{
	int	verif;

	verif = verif_moove(keycode, map);
	if (verif == 1)
	{
		if (keycode == W)
			moove_w(map);
		if (keycode == A)
			moove_a(map);
		if (keycode == S)
			moove_s(map);
		if (keycode == D)
			moove_d(map);
	}
	if (keycode != ESC)
		map->meter_moove++;
	if ((map->collectible == 0
			&& map->initial_map[map->playerx][map->playery] == 'E')
			|| verif == 2)
		free_kill(map);
	return (0);
}

int	init_game(int argc, t_map *map)
{
	if (argc != 2)
	{
		write(2, ERR_ARGC, ft_strlen(ERR_ARGC));
		return (1);
	}
	map->mlx = mlx_init();
	if (!map->mlx)
	{
		write(2, ERR_MLX, ft_strlen(ERR_MLX));
		return (1);
	}
	init_img(map);
	if (!map->wall || !map->ground || !map->exit || !map->coin || !map->chara)
	{
		write(2, ERR_INIT_IMG, ft_strlen(ERR_INIT_IMG));
		free_img(map);
		return (1);
	}
	return (0);
}

void ft_bzero(void *ptr, unsigned int n)
{
	char	*p = ptr;

	while (n--)
	{
		*p++ = 0;
	}
}

int	main(int argc, char *argv[])
{
	t_map	map;	

	/* TODO */
	ft_bzero(&map, sizeof(map));

	if (init_game(argc, &map) == 1)
		return (0);
	map.map = ft_file_to_map(argv[1], '\n');
	map.initial_map = ft_file_to_map(argv[1], '\n');
	if (ft_map_validation(&map) < 1)
		free_map_invalid(&map);
	map.win = mlx_new_window(map.mlx, (
				map.length * WIDTH), (map.height * HEIGHT), "so_long");
	if (!map.win)
	{
		free_map(&map);
		free(map.mlx);
		write(1, ERR_WIN, ft_strlen(ERR_WIN));
		return (0);
	}
	print_map(&map);
	mlx_key_hook(map.win, travel, &map);
	mlx_hook(map.win, 17, 0, (int (*)())free_kill, &map);
	mlx_loop(map.mlx);
	return (1);
}
