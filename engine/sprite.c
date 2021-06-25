/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsousa-l <gsousa-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 21:33:15 by gsousa-l          #+#    #+#             */
/*   Updated: 2021/06/25 20:12:34 by gsousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

u_int32_t	get_spri_color(t_sprite s, int x, int y, t_game *game)
{
	int	offset[2];
	int	dist_to_top;
	int	diff_x;

	diff_x = (x - s.init_x);
	offset[0] = diff_x * game->textures.sprite.width / s.width;
	if (offset[0] < 0)
		offset[0] *= -1;
	dist_to_top = y + (s.height / 2) - (game->screen.res_y / 2);
	offset[1] = dist_to_top * ((float)game->textures.sprite.height
			/ (float)s.height);
	return (game->textures.sprite.addr[offset[1]
			* game->textures.sprite.line_length / 4 + offset[0]]);
}

void	set_sprite(t_game *game)
{
	int	i;
	int	j;
	int	spri;

	i = 0;
	spri = 0;
	game->num_sprites = ft_check_item_arr(game->map, '2');
	if (game->num_sprites)
	{
		game->sprites = ft_calloc(game->num_sprites, sizeof(t_sprite));
		while (game->map[i])
		{
			j = 0;
			while (game->map[i][j])
			{
				if (game->map[i][j] == '2')
				{
					game->sprites[spri].x = j + 0.5;
					game->sprites[spri++].y = i + 0.5;
				}
				j++;
			}
			i++;
		}
	}
}

void	sort_sprites(t_sprite *sprites, t_game *game)
{
	t_sprite	aux;
	int			i;
	int			j;

	i = game->num_sprites - 1;
	while (i > 0)
	{
		j = i;
		while (j > 0)
		{
			if (sprites[i].dist > game->sprites[i - 1].dist)
			{
				aux = sprites[i - 1];
				sprites[i - 1] = sprites[i];
				sprites[i] = aux;
			}
			j--;
		}
		i--;
	}
}

void	set_params_sprite(t_sprite *s, int i, t_game *game, double *z_buff)
{
	int		pixel_x;

	while (--i >= 0)
	{
		s[i].dist = ft_hipot(s[i].x - game->player.x, s[i].y - game->player.y);
		s[i].angle = atan2(s[i].y - game->player.y, s[i].x - game->player.x)
			- ft_deg_to_rad(game->player.angle);
		pixel_x = tan(s[i].angle) * game->plane_dist;
		s[i].angle = ft_norm_angle_rad(s[i].angle);
		s[i].angle = fabs(s[i].angle);
		s[i].height = (game->textures.sprite.height / s[i].dist)
			* game->plane_dist / 100;
		s[i].width = (game->textures.sprite.width / s[i].dist)
			* game->plane_dist / 100;
		s[i].init_y = (game->screen.res_y / 2) - (s[i].height / 2);
		s[i].end_y = (game->screen.res_y / 2) + (s[i].height / 2);
		if (s[i].init_y < 0)
			s[i].init_y = 0;
		if (s[i].end_y > game->screen.res_y)
			s[i].end_y = game->screen.res_y;
		s[i].init_x = (game->screen.res_x / 2) + pixel_x;
		s[i].end_x = s[i].init_x + s[i].width;
		s[i].active = s[i].angle < ft_deg_to_rad((PLAYER_FOV + PRECISION) / 2);
	}
}

void	ft_print_sprite(t_sprite s, double *z_buff, t_game *game)
{
	int			x;
	int			y;
	u_int32_t	color;

	x = s.init_x;
	while (x < s.end_x && x < game->screen.res_x)
	{
		y = s.init_y;
		while (y < s.end_y)
		{
			color = 0;
			if (s.dist < z_buff[x])
			{
				color = get_spri_color(s, x, y, game);
				if (color)
					ft_pixel_put(&(game->img), x, y, color);
			}
			y++;
		}
		x++;
	}
}
