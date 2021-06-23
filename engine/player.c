/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsousa-l <gsousa-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 22:46:58 by gsousa-l          #+#    #+#             */
/*   Updated: 2021/06/18 19:45:02 by gsousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	rotate_player(t_player *player, int direction)
{
	player->angle = (player->angle + (direction * ROT_DEGREE)) % 360;
	if (player->angle < 0)
		player->angle += 360;
	if (player->angle > 360)
		player->angle -= 360;
	return (1);
}

int	move_right_left(char **map, t_player *player, int direction)
{
	double	player_cos;
	double	player_sin;
	double	new_x;
	double	new_y;
	int		res;

	player_cos = cos(ft_deg_to_rad(player->angle + (direction * 90)))
		* MOV_SPEED;
	player_sin = sin(ft_deg_to_rad(player->angle + (direction * 90)))
		* MOV_SPEED;
	new_x = player->x + player_cos;
	new_y = player->y + player_sin;
	res = 0;
	if (map[(int)new_y][(int)new_x] != '1')
	{
		player->x = new_x;
		player->y = new_y;
	}
	return (1);
}

int	move_forward_back(char **map, t_player *player, int direction)
{
	double	player_cos;
	double	player_sin;
	double	new_x;
	double	new_y;
	int		res;

	player_cos = direction * (cos(ft_deg_to_rad(player->angle)) * MOV_SPEED);
	player_sin = direction * (sin(ft_deg_to_rad(player->angle)) * MOV_SPEED);
	new_x = player->x + player_cos;
	new_y = player->y + player_sin;
	res = 0;
	if (map[(int)new_y][(int)new_x] != '1')
	{
		player->x = new_x;
		player->y = new_y;
	}
	return (1);
}

void	set_position(t_game *game, int i, int j, int *num_players)
{
	game->player.x = j + 0.5;
	game->player.y = i + 0.5;
	*num_players += 1;
	if (game->map[i][j] == 'N')
		game->player.angle = 270;
	else if (game->map[i][j] == 'E')
		game->player.angle = 0;
	else if (game->map[i][j] == 'S')
		game->player.angle = 90;
	else if (game->map[i][j] == 'W')
		game->player.angle = 180;
}

void	ft_set_player(t_game *game)
{
	int	i;
	int	j;
	int	num_players;

	i = 0;
	num_players = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (ft_check_char(game->map[i][j], "NSWE"))
			{
				if (num_players == 0)
					set_position(game, i, j, &num_players);
				else
					message_error("More than one player on the map.");
			}
			j++;
		}
		i++;
	}
	if (num_players == 0)
		message_error("Player not found in map.");
}
