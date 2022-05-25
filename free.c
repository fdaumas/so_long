/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaumas <fdaumas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 10:16:28 by fdaumas           #+#    #+#             */
/*   Updated: 2022/05/24 16:45:51 by fdaumas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_img(t_map *map)
{
	if (map->chara)
		free(map->chara);
	if (map->coin)
		free(map->coin);
	if (map->exit)
		free(map->exit);
	if (map->wall)
		free(map->wall);
	if (map->ground)
		free(map->ground);
	free(map->mlx);
}

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (map->initial_map[i])
	{
		free(map->initial_map[i]);
		i++;
	}
	i = 0;
	while (map->map[i])
	{
		free(map->map[i]);
		i++;
	}
	free(map->initial_map);
	free(map->map);
}

void	free_map_invalid(t_map *map)
{
	mlx_destroy_image(map->mlx, map->wall);
	mlx_destroy_image(map->mlx, map->ground);
	mlx_destroy_image(map->mlx, map->coin);
	mlx_destroy_image(map->mlx, map->exit);
	mlx_destroy_image(map->mlx, map->chara);
	free_map(map);
	free(map->mlx);
	exit(0);
}

void	free_kill(t_map *map)
{
	if (map->collectible == 0
		&& map->initial_map[map->playerx][map->playery] == 'E')
	{
		write(1, "Your score is ", 14);
		ft_putnbr(map->meter_moove);
	}
	else
		write(1, "Abandon\n", 8);
//	free(map->win);
	mlx_destroy_image(map->mlx, map->wall);
	mlx_destroy_image(map->mlx, map->ground);
	mlx_destroy_image(map->mlx, map->coin);
	mlx_destroy_image(map->mlx, map->exit);
	mlx_destroy_image(map->mlx, map->chara);
	free_map(map);
	free(map->mlx);
	free(map->win);
	exit(0);
}
