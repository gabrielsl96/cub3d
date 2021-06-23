/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsousa-l <gsousa-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 01:20:07 by gsousa-l          #+#    #+#             */
/*   Updated: 2021/06/23 23:27:47 by gsousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

char	**split_nums(char **str)
{
	char	**temp;
	char	**numbers;

	temp = ft_split(*str, ' ');
	if (ft_arrlen(temp) != 2)
	{
		free(*str);
		ft_freearr(temp);
		message_error("Invalid information for color.");
	}
	numbers = ft_split(temp[1], ',');
	ft_freearr(temp);
	return (numbers);
}

int	valid_num(int *arr)
{
	int	num;
	int	i;

	i = 0;
	while (arr[i])
	{
		if (arr[i] < 0 || arr[i] > 255)
			return (1);
		i++;
	}
	return (0);
}

int	valid_arrnum(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j] != '\0')
		{
			if (!ft_isdigit(str[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	*trat_error_color(char **str)
{
	char	**numbers;
	int		*nums;

	numbers = split_nums(str);
	if (ft_arrlen(numbers) != 3 || !valid_arrnum(numbers))
	{
		free(*str);
		ft_freearr(numbers);
		message_error("Invalid information for color.");
	}
	nums = arrstr_to_arrint(numbers);
	ft_freearr(numbers);
	if (valid_num(nums))
	{
		free(*str);
		free(nums);
		message_error("Invalid range for color.");
	}
	return (nums);
}

int	set_color(char **str, u_int32_t *color)
{
	int	*colors;

	colors = trat_error_color(str);
	*color = ft_conv_rgb(255, colors[0], colors[1], colors[2]);
	free(colors);
	return (1);
}
