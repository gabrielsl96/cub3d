/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsousa-l <gsousa-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 23:00:13 by gsousa-l          #+#    #+#             */
/*   Updated: 2021/06/18 16:37:43 by gsousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	check_space(t_game *game, int width, int height)
{
	int	i;
	int	j;

	while (i < (height - 1))
	{
		j = 0;
		while (j < (width -1))
		{
			if (ft_check_char(game->map[i][j], " \0"))
			{
				if (ft_check_char(game->map[i][j + 1], " 1\0")
				&& ft_check_char(game->map[i + 1][j], " 1\0"))
				{
					j++;
					continue ;
				}
				else
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	check_map(t_game *game)
{
	int	width;
	int	height;
	int	i;
	int	j;

	width = ft_strlen(game->map[0]);
	height = ft_arrlen(game->map);
	i = 0;
	if (ft_check_str(game->map[0], " 1")
		&& ft_check_str(game->map[height - 1], " 1")
		&& ft_check_col(game->map, 0, height, " 1")
		&& ft_check_col(game->map, width - 1, height, " 1")
		&& check_space(game, width, height))
	{
		return ;
	}
	ft_freearr(game->map);
	message_error("Map invalid!");
}

void	norm_map(t_game *game)
{
	int		width;
	int		height;
	char	**arr;
	int		i;
	int		j;

	i = 0;
	width = ft_maxlen_arr(game->map);
	height = ft_arrlen(game->map);
	arr = ft_arrchar(width, height);
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (j < ft_strlen(game->map[i]))
				arr[i][j] = game->map[i][j];
			else
				arr[i][j] = ' ';
			j++;
		}
		i++;
	}
	ft_freearr(game->map);
	game->map = arr;
}

void	copy_map(char *line, t_game *game)
{
	int			k;
	char		**map_aux;
	static int	j;

	map_aux = malloc(sizeof(map_aux) * (j + 1));
	k = 0;
	while (k < j)
	{
		map_aux[k] = game->map[k];
		k++;
	}
	map_aux[k] = line;
	free(game->map);
	game->map = malloc(sizeof(game->map) * (k + 1));
	game->map[k + 1] = NULL;
	while (k + 1 > 0)
	{
		game->map[k] = map_aux[k];
		k--;
	}
	free(map_aux);
	j += 1;
}

void	read_map(char *line, t_game *game, int fd)
{
	int			i;

	i = 1;
	if (!ft_strlen(line))
		message_error("Map not found.");
	while (i)
	{
		if (!ft_check_str(line, " 120NSEW"))
		{
			free(line);
			message_error("Invalid map.");
			return ;
		}
		else
			copy_map(line, game);
		i = get_next_line(fd, &line);
	}
	free(line);
	norm_map(game);
	check_map(game);
}
