/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsousa-l <gsousa-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 01:18:03 by gsousa-l          #+#    #+#             */
/*   Updated: 2021/06/18 20:40:36 by gsousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	init_texture(t_img *texture)
{
	texture->img = 0;
	texture->width = 0;
	texture->width = 0;
}

int	set_texture(char **str, t_game *game, t_img *texture)
{
	char	**temp;

	temp = ft_split(*str, ' ');
	if (temp[1] == NULL)
	{
		ft_freearr(temp);
		message_error("No file for texture.");
	}
	if (temp[2] != NULL || (valid_ext(temp[1], ".xpm")
			&& valid_ext(temp[1], ".XPM")))
	{
		ft_freearr(temp);
		message_error("Extension invalid for texture.");
	}
	init_texture(texture);
	texture->img = mlx_xpm_file_to_image(game->screen.mlx, temp[1],
			&(texture->width), &(texture->height));
	ft_freearr(temp);
	if (!texture->img)
		message_error("Invalid archive of texture!");
	texture->addr = (int *)mlx_get_data_addr(texture->img,
			&(texture->bits_per_pixel), &(texture->line_length),
			&(texture->endian));
	return (1);
}
