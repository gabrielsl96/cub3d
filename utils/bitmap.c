/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsousa-l <gsousa-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 16:19:20 by gsousa-l          #+#    #+#             */
/*   Updated: 2021/06/23 20:35:51 by gsousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	clean_for_finish(t_game *game)
{
	ft_freearr(game->map);
	free(game->sprites);
	mlx_destroy_image(game->screen.mlx, game->textures.textu_ea.img);
	mlx_destroy_image(game->screen.mlx, game->textures.textu_we.img);
	mlx_destroy_image(game->screen.mlx, game->textures.textu_so.img);
	mlx_destroy_image(game->screen.mlx, game->textures.textu_no.img);
	mlx_destroy_image(game->screen.mlx, game->textures.sprite.img);
	mlx_destroy_image(game->screen.mlx, game->img.img);
	free(game->screen.mlx);
}

void	set_header(t_window scr, t_bmp *bmp)
{
	bmp->type = 0X4D42;
	bmp->image_size = ((scr.res_x + scr.res_x) * 4);
	bmp->file_size = bmp->image_size + 54;
	bmp->reserved_1 = 0;
	bmp->reserved_2 = 0;
	bmp->offset = 54;
	bmp->header_size = 40;
	bmp->image_width = scr.res_x;
	bmp->image_height = scr.res_y;
	bmp->planes = 1;
	bmp->bits_per_pixel = 32;
	bmp->compression = 0;
	bmp->x_pix_per_meter = 3200;
	bmp->y_pix_per_meter = 3200;
	bmp->total_colors = 0;
	bmp->important_colors = 0;
}

void	fill_header_bmp(int fd, t_img *img, t_bmp *bmp)
{
	write(fd, &bmp->type, 2);
	write(fd, &bmp->file_size, 4);
	write(fd, &bmp->reserved_1, 2);
	write(fd, &bmp->reserved_2, 2);
	write(fd, &bmp->offset, 4);
	write(fd, &bmp->header_size, 4);
	write(fd, &bmp->image_width, 4);
	write(fd, &bmp->image_height, 4);
	write(fd, &bmp->planes, 2);
	write(fd, &bmp->bits_per_pixel, 2);
	write(fd, &bmp->compression, 4);
	write(fd, &bmp->image_size, 4);
	write(fd, &bmp->x_pix_per_meter, 4);
	write(fd, &bmp->y_pix_per_meter, 4);
	write(fd, &bmp->total_colors, 4);
	write(fd, &bmp->important_colors, 4);
}

void	fill_bmp(int fd, t_img *img, t_bmp *bmp, t_window s)
{
	int	x;
	int	y;
	int	index;

	y = s.res_y - 1;
	printf("Saving bmp...\n");
	while (y >= 0)
	{
		x = s.res_x - 1;
		while (x >= 0)
		{
			index = y * img->line_length / 4 + x;
			if (write(fd, &img->addr[index], 4) <= 0)
				message_error("Fail to save bmp process.");
			x--;
		}
		y--;
	}
	printf("Finish saving!\n");
}

void	save_bmp(t_game *game)
{
	t_bmp	bmp;
	int		fd;

	fd = open("./cub.bmp", O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (fd <= 0)
		perror(strerror(fd));
	draw_background(game);
	ft_raycasting(game);
	set_header(game->screen, &bmp);
	fill_header_bmp(fd, &(game->img), &bmp);
	fill_bmp(fd, &(game->img), &bmp, game->screen);
	close(fd);
	clean_for_finish(game);
}
