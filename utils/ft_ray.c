/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsousa-l <gsousa-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 20:21:26 by gsousa-l          #+#    #+#             */
/*   Updated: 2021/06/23 22:50:42 by gsousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	ft_ray(t_ray *ray, t_game *game)
{
	while (1)
	{
		ray->x += ray->cos;
		ray->y += ray->sin;
		if (game->map[(int)ray->y][(int)ray->x] == '1')
		{
			ray->side = (ft_round_two_dec(ray->y) == round(ray->y));
			break ;
		}
	}
	ray->distance = ft_hipot(ray->x - game->player.x, ray->y - game->player.y);
	ray->distance *= cos(ft_deg_to_rad(ray->angle - game->player.angle));
	ray->wall_height = ((double)game->screen.res_y / 2) / ray->distance;
}
