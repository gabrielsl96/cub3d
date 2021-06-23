/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsousa-l <gsousa-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 20:18:23 by gsousa-l          #+#    #+#             */
/*   Updated: 2021/06/23 23:32:30 by gsousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define NUM_PI 3.14159265358979323846
# define PLAYER_FOV 66
# define QUALITY 200
# define MOV_SPEED 0.04
# define ROT_DEGREE 2
# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_Q 113
# define KEY_E 101
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define FORWARD 1
# define BACK -1
# define LEFT 1
# define RIGHT -1
# define PRECISION 5
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "./libft/libft.h"
# include "./get_next_line/get_next_line.h"
# include "mlx.h"
# include "math.h"

typedef struct s_keys
{
	int			forw_back;
	int			left_right;
	int			rotat;
}				t_keys;

typedef struct s_bmp
{
	u_int16_t	type;
	u_int32_t	file_size;
	u_int16_t	reserved_1;
	u_int16_t	reserved_2;
	u_int32_t	offset;
	u_int32_t	header_size;
	u_int32_t	image_width;
	u_int32_t	image_height;
	u_int16_t	planes;
	u_int16_t	bits_per_pixel;
	u_int32_t	compression;
	u_int32_t	image_size;
	u_int32_t	x_pix_per_meter;
	u_int32_t	y_pix_per_meter;
	u_int32_t	total_colors;
	u_int32_t	important_colors;
}				t_bmp;

typedef struct s_img
{
	void		*img;
	int			*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height;
}				t_img;

typedef struct s_sprite
{
	double		x;
	double		y;
	double		dist;
	double		angle;
	double		height;
	double		width;
	int			init_y;
	int			init_x;
	int			end_y;
	int			end_x;
	int			active;
}				t_sprite;

typedef struct s_ray
{
	int			pix_x;
	double		angle;
	double		increment;
	double		x;
	double		y;
	double		cos;
	double		sin;
	double		distance;
	int			wall_height;
	int			sprites;
	int			side;
	t_img		*texture;
}				t_ray;

typedef struct s_window
{
	void		*win;
	void		*mlx;
	int			res_x;
	int			res_y;
}				t_window;

typedef struct s_textures
{
	t_img		textu_no;
	t_img		textu_so;
	t_img		textu_we;
	t_img		textu_ea;
	t_img		sprite;
}				t_textures;

typedef struct s_color
{
	u_int32_t	f;
	u_int32_t	c;
}				t_color;

typedef struct s_player
{
	int			angle;
	double		x;
	double		y;
	int			in_map;
}				t_player;

typedef struct s_game
{
	t_window	screen;
	t_textures	textures;
	t_color		color;
	t_img		img;
	t_player	player;
	t_keys		keys;
	char		**map;
	double		plane_dist;
	int			num_sprites;
	double		*z_buffer;
	t_sprite	*sprites;
}				t_game;

int			valid_ext(const char *str, char *extension);
void		ft_valid_file(char *str, t_game *game);
void		message_error(char *msg_error);
void		init_window(t_game *game);
int			close_window(t_game *game);
int			press_key(int keycode, t_game *game);
int			release_key(int keycode, t_game *game);
void		ft_freearr(char **arr);
int			set_texture(char **str, t_game *game, t_img *texture);
int			set_color(char **str, u_int32_t *color);
int			set_resolution(char **str, t_window *window);
int			ft_arrlen(char **arr);
int			ft_maxlen_arr(char **arr);
char		**ft_arrchar(int width, int height);
int			ft_check_col(char **arr, int col, int line_end, char *str_check);
char		*ft_dec_to_base(long long num, int buffer, int base);
u_int32_t	ft_conv_rgb(int t, int r, int g, int b);
int			ft_check_str(char *str, char *params);
int			ft_check_char(char c, char *params);
void		ft_pixel_put(t_img *img, int x, int y, u_int32_t color);
double		ft_deg_to_rad(double degree);
int			*arrstr_to_arrint(char **arr);
void		read_map(char *line, t_game *game, int fd);
void		draw_background(t_game *game);
void		ft_set_player(t_game *game);
void		ft_raycasting(t_game *game);
void		ft_draw_map2D(char **map, t_game *game);
void		ft_draw_colu(t_game *game, u_int32_t color, t_img *img, t_ray *ray);
double		ft_round_two_dec(double	num);
double		ft_hipot(double x, double y);
double		ft_norm_angle(double angle);
void		save_bmp(t_game *game);
int			rotate_player(t_player *player, int direction);
int			move_right_left(char **map, t_player *player, int direction);
int			move_forward_back(char **map, t_player *player, int direction);
void		move_player(t_game *game);
void		set_sprite(t_game *game);
void		ft_ray(t_ray *ray, t_game *game);
double		ft_norm_angle_rad(double angle_rad);
int			ft_check_item_arr(char **arr, char c);
void		set_params_sprite(t_sprite *s, int i, t_game *game, double *z_buff);
void		sort_sprites(t_sprite *sprites, t_game *game);
void		ft_print_sprite(t_sprite s, double *z_buff, t_game *game);
void		draw_sprite(t_game *game);
int			ft_check_num_str(char *str);
#endif
