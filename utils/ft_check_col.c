/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_col.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsousa-l <gsousa-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 22:19:07 by gsousa-l          #+#    #+#             */
/*   Updated: 2021/06/17 22:41:40 by gsousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	ft_check_col(char **arr, int col, int line_end, char *str_check)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < line_end)
	{
		if (!ft_check_char(arr[i][col], str_check))
			return (0);
		i++;
	}
	return (1);
}
