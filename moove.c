/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaumas <fdaumas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 10:19:45 by fdaumas           #+#    #+#             */
/*   Updated: 2022/04/11 10:33:47 by fdaumas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	verif_moove(int direction, t_map *map)
{
	if (direction == A)
		if (map->initial_map[map->playerx][map->playery - 1] == '1')
			return (0);
	if (direction == D)
		if (map->initial_map[map->playerx][map->playery + 1] == '1')
			return (0);
	if (direction == W)
		if (map->initial_map[map->playerx - 1][map->playery] == '1')
			return (0);
	if (direction == S)
		if (map->initial_map[map->playerx + 1][map->playery] == '1')
			return (0);
	if (direction == ESC)
		return (2);
	return (1);
}

int	moove_a(t_map *map)
{
	if (map->initial_map[map->playerx][map->playery] == 'E')
		map->map[map->playerx][map->playery] = 'E';
	else
		map->map[map->playerx][map->playery] = '0';
	if (map->map[map->playerx][map->playery - 1] == 'C')
		map->collectible--;
	map->map[map->playerx][map->playery - 1] = 'P';
	map->playery--;
	print_map(map);
	return (0);
}

int	moove_d(t_map *map)
{
	if (map->initial_map[map->playerx][map->playery] == 'E')
		map->map[map->playerx][map->playery] = 'E';
	else
		map->map[map->playerx][map->playery] = '0';
	if (map->map[map->playerx][map->playery + 1] == 'C')
		map->collectible--;
	map->map[map->playerx][map->playery + 1] = 'P';
	map->playery++;
	print_map(map);
	return (0);
}

int	moove_w(t_map *map)
{
	if (map->initial_map[map->playerx][map->playery] == 'E')
		map->map[map->playerx][map->playery] = 'E';
	else
		map->map[map->playerx][map->playery] = '0';
	if (map->map[map->playerx - 1][map->playery] == 'C')
		map->collectible--;
	map->map[map->playerx - 1][map->playery] = 'P';
	map->playerx--;
	print_map(map);
	return (0);
}

int	moove_s(t_map *map)
{
	if (map->initial_map[map->playerx][map->playery] == 'E')
		map->map[map->playerx][map->playery] = 'E';
	else
		map->map[map->playerx][map->playery] = '0';
	if (map->map[map->playerx + 1][map->playery] == 'C')
		map->collectible--;
	map->map[map->playerx + 1][map->playery] = 'P';
	map->playerx++;
	print_map(map);
	return (0);
}
