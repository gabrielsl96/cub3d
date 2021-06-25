/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsousa-l <gsousa-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 15:46:07 by gsousa-l          #+#    #+#             */
/*   Updated: 2021/06/25 19:58:07 by gsousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	ft_pixel_put(t_img *img, int x, int y, unsigned int color)
{
	img->addr[y * img->line_length / 4 + x] = color;
}

void	draw_sprite(t_game *game)
{
	int	i;

	i = 0;
	set_params_sprite(game->sprites, game->num_sprites, game,
		game->z_buffer);
	sort_sprites(game->sprites, game);
	while (i < game->num_sprites)
	{
		if (game->sprites[i].active)
			ft_print_sprite(game->sprites[i], game->z_buffer, game);
		i++;
	}
	free(game->z_buffer);
}

void	draw_background(t_game *game)
{
	int	x;
	int	y;

	if (!game->img.img)
	{
		game->img.img = mlx_new_image(game->screen.mlx,
				game->screen.res_x, game->screen.res_y);
		game->img.addr = (int *)mlx_get_data_addr(game->img.img,
				&game->img.bits_per_pixel, &game->img.line_length,
				&game->img.endian);
	}
	y = 0;
	while (y < game->screen.res_y)
	{
		x = 0;
		while (x < game->screen.res_x)
		{
			if (y < (game->screen.res_y / 2))
				ft_pixel_put(&(game->img), x, y, game->color.c);
			else
				ft_pixel_put(&(game->img), x, y, game->color.f);
			x++;
		}
		y++;
	}
}
