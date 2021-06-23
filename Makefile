# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsousa-l <gsousa-l@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/26 14:40:42 by gsousa-l          #+#    #+#              #
#    Updated: 2021/06/23 23:31:36 by gsousa-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

MLX = -I ./minilibx-unix -lX11 -lmlx -lXext -lm -g -fsanitize=address

CC = clang

SRC = 	main.c \
		engine/color.c \
		engine/map.c \
		engine/texture.c \
		engine/window.c \
		engine/file.c \
		engine/draw.c \
		engine/player.c \
		engine/raycasting.c \
		engine/events.c \
		engine/valid_files.c \
		engine/sprite.c \
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c \
		utils/ft_hipot.c \
		utils/ft_freearr.c \
		utils/ft_arrlen.c \
		utils/ft_arrstr_to_arrint.c \
		utils/ft_conv_rgb.c \
		utils/ft_check_str.c \
		utils/ft_check_char.c \
		utils/ft_deg_to_rad.c \
		utils/ft_round_two_dec.c \
		utils/ft_norm_angle.c \
		utils/bitmap.c \
		utils/ft_maxlen_arr.c \
		utils/ft_arrchar.c \
		utils/ft_check_col.c \
		utils/ft_ray.c \
		utils/ft_norm_angle_rad.c \
		utils/ft_check_item_arr.c \
		utils/ft_check_num_str.c \

OBJS = $(SRC:.c=.o)

$(NAME):	$(OBJS)
			make -C ./minilibx-linux
			make -C ./libft
			sudo cp minilibx-linux/libmlx.a /usr/local/lib
			sudo cp minilibx-linux/mlx.h /usr/local/include
			$(CC) -Wall -Wextra -Werror -g $(OBJS) libft/libft.a $(MLX) -o $(NAME)

all:	$(NAME)

clean:
		rm -f $(NAME) $(OBJS)

fclean: clean
		make clean -C ./minilibx-linux
		make fclean -C ./libft

re:		fclean all

test:
		./cub3D ./maps/map_sw.cub

print:
		./cub3D ./maps/map_sw.cub --save
