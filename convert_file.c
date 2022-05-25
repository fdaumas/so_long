/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaumas <fdaumas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 21:07:35 by fdaumas           #+#    #+#             */
/*   Updated: 2022/04/06 21:11:50 by fdaumas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_file_to_string(char *file)
{
	int		fd;
	char	*string;
	char	*string2;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror("Error\nError ");
		return (0);
	}
	string = get_next_line(fd);
	string2 = get_next_line(fd);
	while (string2)
	{
		string = ft_strjoin(string, string2);
		free(string2);
		string2 = get_next_line(fd);
	}
	return (string);
}

char	**ft_file_to_map(char *file, char split)
{
	char	**map;
	char	*string;

	string = ft_file_to_string(file);
	if (!string)
		return (0);
	map = ft_split(string, split);
	free(string);
	return (map);
}
