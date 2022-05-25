/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verif.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaumas <fdaumas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 22:13:06 by fdaumas           #+#    #+#             */
/*   Updated: 2022/04/07 15:52:09 by fdaumas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

size_t	ft_char_curator(t_map *map_data, int i, int *player)
{
	int	x;

	x = 0;
	while (map_data->map[i][x])
	{
		if (map_data->map[i][x] == 'C')
			++map_data->collectible;
		else if (map_data->map[i][x] == 'E')
			++map_data->e;
		else if (*player > 0 && map_data->map[i][x] == 'P')
			map_data->map[i][x] = '0';
		else if (map_data->map[i][x] == 'P')
		{
			++*player;
			map_data->playerx = i;
			map_data->playery = x;
		}
		else if (map_data->map[i][x] != '1' && map_data->map[i][x] != '0')
			return (-1);
		x++;
	}
	return (x);
}

int	ft_error_handler(int error, t_map *map_data)
{
	if (error < 3)
	{	
		if (map_data->collectible < 1)
			write(2, "Error\nMap invalid: No collectibles\n", 35);
		else if (map_data->e < 1)
			write(2, "Error\nMap invalid: No exit\n", 27);
		else if (map_data->playerx < 1)
			write(2, "Error\nMap invalid: No player\n", 29);
		else if (error == -1)
			write(2, "Error\nMap invalid: Unknown character\n", 37);
		else if (error == -2)
			write(2, "Error\nMap invalid: Not a rectangle\n", 35);
		else if (error == -3)
			write(2, "Error\nMap invalid: Not long enough\n", 35);
		else if (error == -4)
			write(2, "Error\nMap invalid: Broken wall\n", 31);
		else
			write(2, "Error\nMap invalid: Not wide enough\n", 35);
		return (0);
	}
	return (1);
}

int	ft_edge_check(t_map *map_data, char c, int length)
{
	int	i;
	int	x;

	x = 0;
	while (map_data->map[0][x])
	{
		if (map_data->map[0][x] != c || map_data->map[length][x] != c)
			return (0);
		x++;
	}
	i = 0;
	while (i <= length)
	{
		if (map_data->map[i][0] != c || map_data->map[i][x - 1] != c)
			return (0);
		i++;
	}
	return (1);
}

int	ft_map_validation(t_map *map_data)
{
	int	i;
	int	player;
	int	error;

	i = 0;
	player = 0;
	error = 1;
	map_data->length = ft_strlen(map_data->map[0]);
	while (map_data->map[i] && error > 0)
	{
		error = ft_char_curator(map_data, i, &player);
		if (error > 0 && (size_t)error != map_data->length)
			error = -2;
		i++;
	}
	map_data->height = i;
	if (i < 3 || map_data->collectible < 1 || map_data->e < 1 \
		|| map_data->playerx < 1)
		error = -3;
	if (error > 0 && ft_edge_check(map_data, '1', i - 1) == 0)
		error = -4;
	return (ft_error_handler (error, map_data));
}
