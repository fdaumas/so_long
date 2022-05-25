/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fileformat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaumas <fdaumas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 21:43:54 by fdaumas           #+#    #+#             */
/*   Updated: 2022/04/06 21:51:48 by fdaumas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_fileformat(int argn, char **input)
{
	size_t	len;

	if (argn < 2)
	{
		write(2, "Error\nNot enough arguments\n", 27);
		return (0);
	}
	else
		len = ft_strlen(input[1]);
	if (len < 5 || ft_strlen(ft_strnstr(&input[1][len - 4], ".ber", 4)) == 0)
		write(2, "Error\nIncompatible file\n", 24);
	else
		return (1);
	return (0);
}
