/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaumas <fdaumas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 16:30:37 by fdaumas           #+#    #+#             */
/*   Updated: 2022/05/25 19:13:31 by fdaumas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include "src/get_next_line/get_next_line.h"
# include <stddef.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_map
{
	char	**initial_map;
	char	**map;
	size_t	length;
	size_t	height;
	int		playerx;
	int		playery;
	int		e;
	int		collectible;
	int		meter_moove;
	void	*wall;
	void	*ground;
	void	*exit;
	void	*coin;
	void	*chara;
	void	*mlx;
	void	*win;
}				t_map;

# define WIDTH 64
# define HEIGHT 64
# define W 13
# define A 0
# define S 1
# define D 2
# define ESC 53 
# define ERR_ARGC "Error\nInvalid number of argument\n"
# define ERR_MLX "Error\nBad initialization of MLX\n"
# define ERR_INIT_IMG "Error\nBad initialization of the images\n"
# define ERR_WIN "Error\nBad create of window\n"

// verif fileformat
int	ft_fileformat(int argn, char **input);
char	*ft_strnstr(const char *str, const char *str2, size_t size);
size_t	ft_strlen(const char *str);

// map
char	**ft_split(char const *str, char split);
char	*get_net_line(int fd);
char	**ft_file_to_map(char *str, char split);

// map validation
int		ft_map_validation(t_map *map);

// print terminal
void	ft_putnbr(int nb);

// free
void	free_img(t_map *map);
void	free_map_invalid(t_map *map);
void	free_map(t_map *map);
void	free_kill(t_map *map);

// moove
int		moove_a(t_map *map);
int		moove_w(t_map *map);
int		moove_s(t_map *map);
int		moove_d(t_map *map);
int		verif_moove(int direction, t_map *map);

// init_img + print (print.c)
void	init_img(t_map *map);
void	print_case(t_map *map, int x, int y, char img);
void	print_line(t_map *map, char *line, int x);
void	print_map(t_map *map);

#endif
