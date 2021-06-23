/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsousa-l <gsousa-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 23:00:13 by gsousa-l          #+#    #+#             */
/*   Updated: 2021/06/23 19:46:59 by gsousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	set_parameters(char *line, t_game *game)
{
	int	res;

	if (!ft_strncmp(line, "R ", 2))
		res = set_resolution(&line, &(game->screen));
	else if (!ft_strncmp(line, "NO ", 3))
		res = set_texture(&line, game, &(game->textures.textu_no));
	else if (!ft_strncmp(line, "SO ", 3))
		res = set_texture(&line, game, &(game->textures.textu_so));
	else if (!ft_strncmp(line, "WE ", 3))
		res = set_texture(&line, game, &(game->textures.textu_we));
	else if (!ft_strncmp(line, "EA ", 3))
		res = set_texture(&line, game, &(game->textures.textu_ea));
	else if (!ft_strncmp(line, "S ", 2))
		res = set_texture(&line, game, &(game->textures.sprite));
	else if (!ft_strncmp(line, "F ", 2))
		res = set_color(&line, &(game->color.f));
	else if (!ft_strncmp(line, "C ", 2))
		res = set_color(&line, &(game->color.c));
	else
		res = 0;
	return (res);
}

void	check_num_args(int args, char *line, int fd, t_game *game)
{
	if (args == 8)
	{
		read_map(line, game, fd);
		ft_set_player(game);
		set_sprite(game);
	}
	else
	{
		free(line);
		message_error("File invalid.");
	}
}

void	ft_valid_file(char *str, t_game *game)
{
	char		*line;
	int			fd;
	static int	args;

	fd = open(str, O_RDONLY);
	if (fd <= 0)
		perror(strerror(fd));
	else
	{
		while (get_next_line(fd, &line))
		{
			if (set_parameters(line, game))
				args++;
			else if (line[0] == '\0')
			{
				free(line);
				continue ;
			}
			else
				break ;
			free(line);
		}
	}
	check_num_args(args, line, fd, game);
}
