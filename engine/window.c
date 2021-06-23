/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsousa-l <gsousa-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 20:29:08 by gsousa-l          #+#    #+#             */
/*   Updated: 2021/06/23 23:28:04 by gsousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	render_screen(t_game *game)
{
	move_player(game);
	draw_background(game);
	ft_raycasting(game);
	draw_sprite(game);
	mlx_put_image_to_window(game->screen.mlx, game->screen.win,
		game->img.img, 0, 0);
	return (0);
}

void	check_resolution(t_window *screen, int *x, int *y)
{
	int	x_screen;
	int	y_screen;

	x_screen = 0;
	y_screen = 0;
	mlx_get_screen_size(screen->mlx, &x_screen, &y_screen);
	if (x_screen < *x)
		*x = x_screen;
	if (y_screen < *y)
		*y = y_screen;
}

void	init_window(t_game *game)
{
	int	x;
	int	y;

	check_resolution(&(game->screen), &(game->screen.res_x),
		&(game->screen.res_y));
	x = game->screen.res_x;
	y = game->screen.res_y;
	game->plane_dist = floor((game->screen.res_x / 2)
			/ tan(ft_deg_to_rad(PLAYER_FOV / 2)));
	game->screen.win = mlx_new_window(game->screen.mlx, x, y, "CUB3D");
	mlx_hook(game->screen.win, 2, 1L << 0, press_key, game);
	mlx_hook(game->screen.win, 3, 1L << 1, release_key, game);
	mlx_hook(game->screen.win, 33, 1L << 17, close_window, game);
	mlx_loop_hook(game->screen.mlx, render_screen, game);
	mlx_loop(game->screen.mlx);
}

int	set_resolution(char **str, t_window *window)
{
	char	**temp;

	temp = ft_split(*str, ' ');
	if (ft_arrlen(temp) != 3 || !ft_check_num_str(temp[1])
		|| !ft_check_num_str(temp[2]))
	{
		ft_freearr(temp);
		message_error("Invalid resolution parameters.");
	}
	window->res_x = ft_atoi(temp[1]);
	window->res_y = ft_atoi(temp[2]);
	ft_freearr(temp);
	return (1);
}
