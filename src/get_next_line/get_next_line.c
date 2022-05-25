/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaumas <fdaumas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 08:10:28 by fdaumas           #+#    #+#             */
/*   Updated: 2022/04/18 08:10:33 by fdaumas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../../so_long.h"

char	*ft_free(char *string)
{
	if (string)
		free(string);
	return (0);
}

char	*ft_trimalloc(char *string, char c)
{
	char	*trimmed;
	size_t	i;
	size_t	l;

	i = 0;
	l = ft_strlen(string);
	while (string[i] != c && string[i])
		i++;
	if (string[i] == c)
		i++;
	trimmed = malloc(sizeof(char) * (l - i) + 1);
	if (!trimmed)
		return (0);
	l = 0;
	while (string[i + l])
	{
		trimmed[l] = string[i + l];
		l++;
	}
	trimmed[l] = '\0';
	free(string);
	return (trimmed);
}

char	*ft_read(int fd, char *buffer)
{
	int		read_state;
	char	temp[BUFFER_SIZE + 1];

	read_state = 1;
	while (read_state > 0)
	{
		read_state = read(fd, temp, BUFFER_SIZE);
		if ((!buffer && read_state < 1) || fd < 0 || read_state == -1)
			return (0);
		temp[read_state] = '\0';
		if (read_state > 0)
			buffer = ft_strjoin(buffer, temp);
		if (ft_strchr(temp, '\n'))
			break ;
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer = 0;

	if (fd < 0)
		return (0);
	if (buffer != 0)
	{
		buffer = ft_trimalloc(buffer, '\n');
		if (ft_strchr(buffer, '\n'))
			return (ft_strfelement(buffer, '\n'));
	}
	buffer = ft_read(fd, buffer);
	if (buffer && *buffer == 0)
	{
		buffer = ft_free(buffer);
		return (buffer);
	}
	if (!buffer)
		return (0);
	return (ft_strfelement(buffer, '\n'));
}
