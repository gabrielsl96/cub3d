/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsousa-l <gsousa-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 22:24:04 by gsousa-l          #+#    #+#             */
/*   Updated: 2021/06/23 20:35:32 by gsousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	close_window(t_game *game)
{
	ft_freearr(game->map);
	free(game->sprites);
	mlx_destroy_window(game->screen.mlx, game->screen.win);
	exit(0);
	return (0);
}

void	move_player(t_game *game)
{
	if (game->keys.forw_back != 0)
		move_forward_back(game->map, &(game->player), game->keys.forw_back);
	if (game->keys.left_right != 0)
		move_right_left(game->map, &(game->player), game->keys.left_right);
	if (game->keys.rotat != 0)
		rotate_player(&(game->player), game->keys.rotat);
}

int	press_key(int keycode, t_game *game)
{
	int	res;

	if (keycode == KEY_ESC)
		close_window(game);
	else if (keycode == KEY_W)
		game->keys.forw_back = FORWARD;
	else if (keycode == KEY_S)
		game->keys.forw_back = BACK;
	else if (keycode == KEY_A)
		game->keys.left_right = RIGHT;
	else if (keycode == KEY_D)
		game->keys.left_right = LEFT;
	else if (keycode == KEY_E || keycode == KEY_RIGHT)
		game->keys.rotat = -RIGHT;
	else if (keycode == KEY_Q || keycode == KEY_LEFT)
		game->keys.rotat = -LEFT;
	return (0);
}

int	release_key(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		game->keys.forw_back = 0;
	else if (keycode == KEY_S)
		game->keys.forw_back = 0;
	else if (keycode == KEY_A)
		game->keys.left_right = 0;
	else if (keycode == KEY_D)
		game->keys.left_right = 0;
	else if (keycode == KEY_E || keycode == KEY_RIGHT)
		game->keys.rotat = 0;
	else if (keycode == KEY_Q || keycode == KEY_LEFT)
		game->keys.rotat = 0;
	return (0);
}
