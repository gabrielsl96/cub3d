/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsousa-l <gsousa-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 15:27:01 by gsousa-l          #+#    #+#             */
/*   Updated: 2021/06/02 23:14:40 by gsousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_params(t_game *game)
{
	game->color.f = 0;
	game->color.c = 0;
	game->screen.mlx = mlx_init();
	if (!game->screen.mlx)
		message_error("Cannot connect to display.");
	game->screen.win = NULL;
	game->screen.res_x = 0;
	game->screen.res_y = 0;
	game->map = malloc(sizeof(char **));
	game->map[0] = NULL;
	game->img.img = NULL;
	game->num_sprites = 0;
	game->keys.forw_back = 0;
	game->keys.left_right = 0;
	game->keys.rotat = 0;
}

void	read_file(char *str, t_game *game)
{
	int	fd;

	if (valid_ext(str, ".cub"))
		message_error("Invalid file extension.");
	ft_valid_file(str, game);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
	{
		init_params(&game);
		read_file(argv[1], &game);
		init_window(&game);
	}
	else if (argc == 3)
	{
		if (!ft_strncmp(argv[2], "--save", 6))
		{
			init_params(&game);
			read_file(argv[1], &game);
			save_bmp(&game);
		}
		else
			printf("Deu ruim!!\n");
	}
	else
		printf("Deu ruim, tiozão!\n");
	return (0);
}
