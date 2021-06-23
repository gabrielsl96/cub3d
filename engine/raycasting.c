/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsousa-l <gsousa-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 16:29:41 by gsousa-l          #+#    #+#             */
/*   Updated: 2021/06/23 22:50:31 by gsousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	init_params_angle(t_ray *ray, t_game *game, double *inc)
{
	ray->pix_x = 0;
	ray->angle = ((int)game->player.angle - (PLAYER_FOV / 2));
	*inc = (double)PLAYER_FOV / (double)game->screen.res_x;
	ray->sprites = 0;
}

void	init_ray(t_ray *ray, t_game *game, double ray_angle)
{
	ray->x = game->player.x;
	ray->y = game->player.y;
	ray->cos = cos(ft_deg_to_rad(ray_angle)) / QUALITY;
	ray->sin = sin(ft_deg_to_rad(ray_angle)) / QUALITY;
	ray->texture = NULL;
}

t_img	*ft_textu_wall(int side, t_game *game, double angle)
{
	if (side)
	{
		if ((angle >= 0 && angle <= 180) || angle > 360)
			return (&(game->textures.textu_so));
		else
			return (&(game->textures.textu_no));
	}
	else
	{
		if (angle > 90 && angle < 270)
			return (&(game->textures.textu_we));
		else
			return (&(game->textures.textu_ea));
	}
}

void	ft_print_wall(int h_wall, t_game *game, t_img *textu, t_ray *ray)
{
	int		line_start;
	int		line_end;
	int		textu_x;
	double	textu_y;
	double	y_inc;

	line_start = (int)((-h_wall / 2) + (game->screen.res_y / 2));
	line_end = (int)((h_wall / 2) + (game->screen.res_y / 2));
	textu_x = ((int)(textu->width * (ray->x + ray->y)) % textu->width);
	textu_y = 0;
	y_inc = (double)textu->height / h_wall;
	if (line_start < 0)
	{
		textu_y = -line_start * y_inc;
		line_start = 0;
	}
	if (line_end >= game->screen.res_y)
		line_end = game->screen.res_y - 1;
	while (line_start < line_end)
	{
		ft_pixel_put(&(game->img), ray->pix_x, line_start,
			textu->addr[(int)textu_y * textu->line_length / 4 + textu_x]);
		textu_y += y_inc;
		line_start++;
	}
}

void	ft_raycasting(t_game *game)
{
	double		increment;
	t_ray		ray;

	init_params_angle(&ray, game, &increment);
	game->z_buffer = ft_calloc(game->screen.res_x, sizeof(double));
	while (ray.pix_x < game->screen.res_x)
	{
		init_ray(&ray, game, ray.angle);
		ft_ray(&ray, game);
		ray.texture = ft_textu_wall(ray.side, game, ray.angle);
		ft_print_wall(ray.wall_height, game, ray.texture, &ray);
		game->z_buffer[ray.pix_x] = ray.distance;
		ray.angle += increment;
		ray.pix_x++;
	}
}
